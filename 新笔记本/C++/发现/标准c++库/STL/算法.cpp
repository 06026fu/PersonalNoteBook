#include <algorithm>
#include <numeric>  // 数值算法

// 非修改序列操作
namespace 非修改序列操作 {
    for_each:
        功能：对范围内每个元素执行操作
        参数：(起始迭代器, 结束迭代器, 函数对象)
        示例：
            vector<int> v{1,2,3};
            for_each(v.begin(), v.end(), [](int x){
                cout << x * 2 << " ";
            });  // 输出 2 4 6

    count:
        功能：统计特定值出现次数
        参数：(起始迭代器, 结束迭代器, 目标值)
        返回：匹配的元素数量
        示例：
            int cnt = count(v.begin(), v.end(), 5);
};

// 修改序列操作 
namespace 修改序列操作 {
    copy:
        功能：复制元素到目标容器
        参数：(源起始, 源结束, 目标起始)
        要求：目标容器需有足够空间
        示例：
            vector<int> src{1,2,3};
            vector<int> dst(3);
            copy(src.begin(), src.end(), dst.begin());

    transform:
        功能：转换元素并存储结果
        参数：(源起始, 源结束, 目标起始, 转换函数)
        示例：
            transform(v.begin(), v.end(), v.begin(), 
                     [](int x){return x*2;});
};

// 排序及相关操作
namespace 排序操作 {
    sort:
        功能：升序排序（默认） 
        参数：(起始迭代器, 结束迭代器, 比较函数)
        复杂度：O(n log n)
        示例：
            sort(v.begin(), v.end());
            sort(v.begin(), v.end(), greater<int>()); // 降序

    binary_search:
        功能：在有序范围中二分查找
        返回：bool是否存在
        示例：
            if(binary_search(v.begin(), v.end(), 5)){
                // 找到元素
            }
};

// 数值算法
namespace 数值算法 {
    accumulate:
        功能：计算累加值
        参数：(起始迭代器, 结束迭代器, 初始值)
        示例：
            int sum = accumulate(v.begin(), v.end(), 0);
            double product = accumulate(v.begin(), v.end(), 1.0, 
                                      multiplies<double>());

    iota（C++11）:
        功能：生成连续递增序列
        示例：
            vector<int> v(5);
            iota(v.begin(), v.end(), 10); // 10,11,12,13,14
};

// C++11新算法
namespace C++11新特性 {
    all_of/any_of/none_of:
        功能：检查范围元素是否全部/任一/无满足条件
        示例：
            if(all_of(v.begin(), v.end(), [](int x){return x>0;})){
                // 所有元素>0
            }
};

// 与容器关联用法
namespace 例{
vector排序示例：
    vector<int> v = {3,1,4,2};
    sort(v.begin(), v.end());
    // v变为 [1,2,3,4]

set查找示例：
    set<int> s{5,2,8};
    auto it = find(s.begin(), s.end(), 5);
    if(it != s.end()){
        cout << "Found: " << *it;
    }
};