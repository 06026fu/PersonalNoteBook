#include <iterator>

//迭代器就是一种广义指针，它可以指向容器中的元素，也可以指向容器中元素的下一个位置。
//可以对他执行诸如*、&、++、--等操作。

// 迭代器类别
namespace 迭代器分类 {
    输入迭代器:
        特性：
            1. 只读访问
            2. 单次遍历
            3. 只能递增操作
        示例：
            istream_iterator<int> iit(cin);

    输出迭代器:
        特性：
            1. 只写访问
            2. 单次遍历
        示例：
            ostream_iterator<int> oit(cout, " ");

    前向迭代器:
        特性：
            1. 读写访问
            2. 多次遍历
            3. 只能递增操作
        示例：
            forward_list<int>::iterator

    双向迭代器:
        特性：
            1. 支持递增/递减
            2. 可反向遍历
        示例：
            list<int>::iterator
            set<int>::iterator

    随机访问迭代器:
        特性：
            1. 支持算术运算（+/-）
            2. 支持下标访问
        示例：
            vector<int>::iterator
            deque<int>::iterator
};

// 迭代器操作
namespace 迭代器操作 {
    begin/end:
        功能：获取容器范围
        示例：
            vector<int> v{1,2,3};
            auto begin = v.begin();
            auto end = v.end();

    rbegin/rend（C++11）:
        功能：获取反向迭代器
        示例：
            for(auto rit = v.rbegin(); rit != v.rend(); ++rit){
                cout << *rit; // 逆向输出
            }

    advance:
        功能：移动迭代器位置
        示例：
            list<int> lst{1,2,3};
            auto it = lst.begin();
            advance(it, 2); // 移动到第三个元素

    distance:
        功能：计算迭代器间距
        示例：
            int len = distance(v.begin(), v.end());
};

// 与容器关联用法
vector迭代器示例：
    vector<int> v = {3,1,4,2};
    sort(v.begin(), v.end()); // 使用随机访问迭代器
    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }

list迭代器示例：
    list<int> lst{5,2,8};
    // 不支持随机访问，只能用双向迭代器
    lst.sort(); // 使用成员函数排序

// 注意事项
1. 迭代器失效场景：
   - vector插入/删除导致重新分配内存
   - deque头尾插入导致迭代器失效
   - map/set删除元素时当前迭代器失效

2. 解决方案：
   - 插入后重新获取迭代器
   - 使用erase返回下一个有效迭代器
    示例：
        for(auto it = m.begin(); it != m.end(); ){
            if(condition){
                it = m.erase(it);
            }else{
                ++it;
            }
        }