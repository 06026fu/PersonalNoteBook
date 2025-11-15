#include <functional>  // 函数对象头文件

//函数对象其实就是重载了()运算符的类对象，
//可以像函数一样被调用，

// 内建函数对象
namespace 算术运算 {
    plus<int> add;       // 加法：add(1,2)=3
    minus<double> sub;   // 减法：sub(5,3)=2.0
    multiplies<> mul;    // 乘法：mul(2.5,4)=10.0（C++14自动推导）
    divides<int> div;    // 除法：div(10,3)=3
    modulus<int> mod;    // 取模：mod(10,3)=1
    negate<int> neg;     // 取反：neg(5)=-5
};

namespace 关系运算 {
    greater<int> gt;     // 大于：gt(5,3)=true
    less_equal<int> le;  // 小于等于：le(3,5)=true
    equal_to<string> eq; // 等于：eq("a","a")=true
    not_equal_to<> neq;  // 不等于：neq(5.0,5)=false
};

namespace 逻辑运算 {
    logical_and<bool> land;  // 逻辑与：land(true,false)=false
    logical_or<bool> lor;    // 逻辑或：lor(true,false)=true
    logical_not<bool> lnot;  // 逻辑非：lnot(false)=true
};

// 自定义函数对象
namespace 自定义仿函数 {
    struct Square {
        int operator()(int x) const { return x*x; }
    };
    
    // 使用示例：
    vector<int> v{1,2,3};
    transform(v.begin(), v.end(), v.begin(), Square()); // 平方运算

    // 带状态的函数对象
    class Threshold {
        int limit;
    public:
        Threshold(int l) : limit(l) {}
        bool operator()(int x) const { return x > limit; }
    };
    
    // 使用示例：
    vector<int> data{5,10,15};
    int count = count_if(data.begin(), data.end(), Threshold(8)); // 统计>8的元素
};

// 函数适配器（C++11之前）
namespace 适配器 {
    bind1st(multiplies<int>(), 10)  // 10*x
    bind2nd(divides<double>(), 2.0) // x/2.0
    
    // 组合适配器
    not1(bind2nd(equal_to<int>(), 0)) // x != 0
};

// C++11新特性
namespace C++11特性 {
    // Lambda表达式
    auto lambda = [scale=2](int x) { return x * scale; };
    
    // bind函数
    using namespace std::placeholders;
    auto bound = bind(multiplies<int>(), _1, 10); // 等效 bind2nd旧式适配器
};

// 与算法结合使用
sort(v.begin(), v.end(), greater<int>());          // 降序排序
transform(v1.begin(), v1.end(), v2.begin(), negate<int>()); // 取反操作
int sum = accumulate(v.begin(), v.end(), 1, multiplies<int>()); // 乘积计算

// 注意事项
1. 函数对象相比函数指针的优势：
   - 可携带状态
   - 支持内联优化
   - 类型安全

2. 优先使用C++11的bind和lambda表达式
3. 自定义函数对象应为无副作用的纯函数