#include<memory>
#include<iostream>
using namespace std;
/*
智能指针实现原理：
1. 控制块机制：
   - shared_ptr/weak_ptr共享控制块，包含：
     * 引用计数器（shared_count）
     * 弱引用计数器（weak_count）
     * 删除器（deleter）
     * 被管理对象的裸指针*/

2. unique_ptr （独占指针）：
    一个 unique_ptr 只能指向一个对象，不允许拷贝和赋值
    当 unique_ptr 超出作用域时，它所指向的对象也会被自动销毁

3. shared_ptr （共享指针）：
    多个 shared_ptr 可以指向同一个对象，共享同一个引用计数
    当引用计数为0时，对象会被自动销毁

4. weak_ptr （弱指针）：
    它是 shared_ptr 的一个辅助类，用于解决 shared_ptr 的循环引用问题
    当一个对象只有 weak_ptr 指向它时，它不会被销毁
    可以通过 lock() 方法将 weak_ptr 转换为 shared_ptr
    不增加引用计数，通过expired()检测对象有效性
    内部保存控制块的弱引用计数
    lock()方法原子性地提升为shared_ptr
lock() 方法使用示例：
    std::weak_ptr<int> weak;
    void process() {
        if(auto shared = weak.lock()) {  // 原子性提升
            shared->doSomething();       // 安全访问对象
        } else {
            std::cout << "对象已销毁";
        }
    }
    // 使用要点：
    // 1. 必须检查lock()返回的shared_ptr是否为空
    // 2. 提升后的shared_ptr会临时增加引用计数
    // 3. 多线程环境下lock()是原子操作
    // 4. 典型应用场景：观察者模式、缓存系统    

// 示例控制块伪实现：
struct ControlBlock {
    long shared_count = 1;
    long weak_count = 0;
    void* managed_ptr = nullptr;
    void(*deleter)(void*) = nullptr;
};