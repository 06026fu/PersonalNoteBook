#include <vector>
#include <list>
#include <deque>
#include <array>        // C++11
#include <forward_list> // C++11
#include <set>
#include <map>
#include <stack>
#include <queue>

顺序容器:
    namespace vector{
    vector:
        特性：
            1. 动态数组，支持随机访问
            2. 尾部插入/删除高效，中间操作低效
        
        创建对象:
            vector<int> v1;                // 默认构造
            vector<int> v2(10);            // 10个0
            vector<int> v3(5, 100);        // 5个100
            vector<int> v4 = {1,2,3};      // 列表初始化
        
        方法:
            push_back()             // 尾插
            pop_back()              // 尾删
            insert(iterator, val)  // 指定位置插入
            erase(iterator)         // 删除元素
        
        与算法关联内容:
            for_each(v1.begin(), v1.end(), [](int val){cout << val << " ";}) // 遍历
            sort(v1.begin(), v1.end());                                     // 排序
    };
    namespace deque{
    deque:
        特性：
            1. 双端队列，支持头尾快速插入
            2. 支持随机访问但效率低于vector
        
        方法:
            push_front()    // 头插
            push_back()     // 尾插
            pop_front()     // 头删
            pop_back()      // 尾删
    };
    namespace list{
            
    list:
        特性：
            1. 双向链表
            2. 任意位置高效插入/删除
            3. 不支持随机访问
        
        方法:
            push_front()    // 头插
            push_back()     // 尾插
            remove(val)     // 删除所有等于val的元素
            sort()          // 链表专用排序
    };
关联容器:
    namespace set{
    // 共性特性
    set/multiset/unordered_set:
        共有方法:
            insert(val)     // 插入元素
            erase(val)      // 删除元素
            find(val)       // 查找元素
            size()          // 元素数量
            empty()         // 判空
    
    set:
        特有特性：
            1. 元素唯一（自动去重）
            2. 默认升序排列（红黑树实现）
            3. 查找复杂度O(log n)
        
        方法详解：
            pair<iterator, bool> insert(val) 
                // 返回插入结果，pair.first=迭代器，pair.second=是否插入成功
            iterator find(val)
                // 找到返回迭代器，否则返回end()
            int erase(val)  
                // 返回删除元素个数（0或1）

        示例：
            set<int> s;
            s.insert(5);    // 插入成功
            s.insert(5);    // 插入失败
            if(s.find(5) != s.end()){ /* 存在 */ }
    namespace multiset{
        multiset:
            差异特性：
                1. 允许重复元素
                2. 相同元素连续存储
                3. 插入总成功
            
            方法差异：
                iterator insert(val)  // 总是返回插入位置迭代器
                int erase(val)        // 返回删除元素个数（可能>1）
            
            示例：
                multiset<int> ms;
                ms.insert(5);  // 返回迭代器
                ms.insert(5);  
                ms.erase(5);   // 返回2
    };
    namespace unordered_set{
        unordered_set（C++11）:
            差异特性：
                1. 哈希表实现
                2. 元素无序存储
                3. 查找复杂度O(1)
            
            特殊方法：
                bucket_count()  // 返回桶数量
                load_factor()   // 负载因子
            
            示例：
                unordered_set<string> us;
                us.insert("apple");
            us.insert("banana");
            us.reserve(100); // 预分配哈希桶
    };
    }
    namespace map{
    // 共性特性
    map/multimap/unordered_map:
        共有方法:
            insert(pair)        // 插入键值对
            erase(key)          // 删除元素
            find(key)           // 查找元素
            size()              // 元素数量
            empty()             // 判空
    
    map:
        特有特性：
        1. 键唯一（自动去重）
        2. 按键升序排列（红黑树实现）
        3. 查找复杂度O(log n)
    
    方法详解：
        // 插入方式
        m.insert(make_pair(1, "one")); 
        m.emplace(2, "two");  // C++11更高效
        
        // 访问方式
        cout << m[1];         // 不存在时创建默认值
        cout << m.at(3);      // 不存在抛out_of_range异常
        
        // 遍历方式
        for(auto& [k, v] : m){ // C++17结构化绑定
            cout << k << ":" << v;
        }
    namespace multimap{
        multimap:
            差异特性：
                1. 允许重复键
                2. 相同键元素连续存储
            
            方法差异：
                iterator insert(pair)  // 总是返回插入位置
                int count(key)        // 返回匹配键的数量
            示例：
                multimap<int, string> mm;
                mm.insert({1, "a"});
                mm.insert({1, "b"});
                cout << mm.count(1); // 输出2
        };
    namespace unordered_map{
        unordered_map（C++11）:
            差异特性：
                1. 哈希表实现
                2. 元素无序存储
            3. 查找复杂度O(1)
            
            特殊方法：
                reserve(n)       // 预分配哈希桶
                bucket(key)      // 查看键所在的桶
                
            示例：
                unordered_map<string, int> um;
                um["apple"] = 5; 
                um.reserve(100); // 优化哈希表性能
        };
    };
容器适配器:
    namespace stack{
    stack:
        特性：
            1. 后进先出(LIFO)
            2. 默认基于deque实现
        
        方法:
            push()  
            pop()
            top()
    }
    namespace queue{
    queue:
        特性：
            1. 先进先出(FIFO)
            2. 默认基于deque实现
        
        方法:
            push()
            pop()
            front()
            back()
    }
// C++11新容器
    namespace array{
    array:
        特性：
            1. 固定大小数组
            2. 更安全的数组替代品

        创建对象:
            array<int,5> arr = {1,2,3};
    }
    namespace forward_list{
    forward_list:
        特性：
            1. 单向链表
            2. 只支持前向遍历
            3. 更节省内存
    }