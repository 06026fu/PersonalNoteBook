#include <string>
#include <algorithm>

    基本特性:
    namespace 基础特性 {
        string str = "Hello";  // 动态字符数组
        wstring wstr = L"中文"; // 宽字符版本
        
        特性：
            1. 类容器设计（类似vector<char>）
            2. 支持随机访问迭代器
            3. 自动内存管理
            4. 支持STL算法操作
    };

    // 构造方法
    namespace 构造方法 {
        string s1;                   // 空字符串
        string s2(5, 'A');          // "AAAAA"
        string s3("C-style");        // C字符串转换
        string s4(s3.begin(), s3.end()); // 迭代器构造
    };

    // 常用操作
    namespace 成员方法 {
        // 修改操作
        s.append(" World");       // 尾部追加
        s.insert(3, "xx");        // 指定位置插入
        s.replace(0,5,"Hi");      // 替换子串
        
        // 访问操作
        char c = s.at(2);         // 带边界检查
        char c2 = s[5];           // 快速访问
        string sub = s.substr(2,4); // 截取子串
        
        // 容量操作
        s.reserve(100);           // 预分配内存
        s.shrink_to_fit();        // C++11释放多余内存
    };

    // 与STL算法结合
    namespace STL算法应用 {
        // 使用STL排序
        string s = "dbca";
        sort(s.begin(), s.end());  // 输出"abcd"
        
        // 使用transform转换
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        
        // 使用find_if查找
        auto it = find_if(s.begin(), s.end(), 
            [](char c){ return isdigit(c); });
    };
与STL的联系:
    1. 类容器设计
    
    - 提供 begin() / end() 迭代器接口
    - 支持 size() / empty() 等容器方法
    - 内存分配通过 allocator 实现
    2. 算法兼容性
    // 可与所有STL算法配合使用  
    count ( s . begin ( ) , s . end ( ) , 'a' ) ;
    reverse ( s . begin ( ) , s . end ( ) ) ;
    3. 适配器支持
    // 流式操作适配器
    ostringstream oss;
    copy ( s . begin ( ) , s . end ( ) ,
    ostream_iterator < char > ( oss, " " ) ) ;
    4. 特殊关联方法
    // 类似容器的查找方法
    size_t pos = s . find ( "sub" ) ;
    // 类似vector的追加操作
    s += " suffix" ;
    注意事项:/*
    1. 与 vector<char> 的区别：
    
    - 专为字符串优化的内存布局
    - 提供字符串特有方法（find/substr等）
    - 支持C++11移动语义
    2. C++17新增功能：
    string_view sv = "Hello" sv ; // 零拷贝字
    符串视图
    s . starts_with ( "http" ) ; // 前缀检查*/