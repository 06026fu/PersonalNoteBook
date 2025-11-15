#include <memory>  // 分配器头文件

// 内建分配器
namespace 标准分配器 {
    std::allocator<int> alloc;  // 默认分配器
    
    方法：
        int* p = alloc.allocate(5);    // 分配5个int空间
        alloc.deallocate(p, 5);        // 释放内存
        alloc.construct(p, 10);        // 构造对象（C++17弃用）
        alloc.destroy(p);               // 析构对象（C++17弃用）
};

// 自定义分配器
namespace 自定义实现 {
    template <typename T>
    class MemoryPool {
        struct Block {
            Block* next;
        };
        Block* head = nullptr;
        
    public:
        using value_type = T;
        
        T* allocate(size_t n) {
            if(n != 1) return static_cast<T*>(::operator new(n*sizeof(T)));
            // 从内存池分配逻辑...
            return reinterpret_cast<T*>(new Block);
        }
        
        void deallocate(T* p, size_t n) {
            if(n != 1) { ::operator delete(p); return; }
            // 回收到内存池逻辑...
        }
    };
    
    // 使用示例：
    vector<int, MemoryPool<int>> pool_vec;
};

// C++11新特性
namespace C++11特性 {
    scoped_allocator_adaptor<allocator<pair<int, string>>> sa; // 嵌套分配器
    polymorphic_allocator<int> pa;  // 多态分配器（需要内存资源支持）
};

// 内存池优化
namespace 优化技巧 {
    1. 批量分配减少malloc调用
    2. 内存对齐处理（alignas关键字）
    3. 线程本地存储分配器（thread_local）
    4. 对象复用技术（避免频繁构造/析构）
};

// 注意事项
1. 分配器需满足Allocator概念要求
2. 自定义分配器需提供value_type类型定义
3. 标准容器默认使用std::allocator
4. C++17后construct/destroy方法被弃用