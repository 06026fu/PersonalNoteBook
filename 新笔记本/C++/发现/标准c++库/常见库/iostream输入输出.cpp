#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>  // 用于STL算法

// 基础流对象
namespace 标准流 {
    istream& cin = std::cin;   // 标准输入
    ostream& cout = std::cout; // 标准输出
    ostream& cerr = std::cerr; // 无缓冲错误输出
    ostream& clog = std::clog; // 带缓冲日志输出
};

// 格式控制
namespace 格式操作 {
    // 常用格式标识
    cout << hex << 255;        // 十六进制输出 ff
    cout << setw(10) << left << "Hello"; // 左对齐
    cout << fixed << setprecision(2) << 3.1415; // 固定小数位
    
    // 自定义格式
    struct MoneyFormat : numpunct<char> {
        char do_thousands_sep() const { return ','; }
        string do_grouping() const { return "\3"; }
    };
};

// 文件流
namespace 文件操作 {
    ofstream outFile("data.txt");  // 输出文件流
    ifstream inFile("data.txt");   // 输入文件流
    
    // 二进制操作
    vector<int> data{1,2,3};
    outFile.write(reinterpret_cast<char*>(data.data()), data.size()*sizeof(int));
};

// 字符串流
namespace 内存流 {
    stringstream ss;
    ss << "Value: " << 42;  // 构建字符串
    string result = ss.str();
};

// 与STL结合
namespace STL整合 {
    // 使用流迭代器
    vector<int> numbers;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(numbers));
    
    // 格式化输出容器
    vector<string> words{"apple", "banana"};
    copy(words.begin(), words.end(), ostream_iterator<string>(cout, "\n"));
};

// C++11新特性
namespace C++11增强 {
    // 移动语义支持
    stringstream&& moved_ss = std::move(ss);
    
    // 原始字符串流
    ostringstream oss;
    oss << R"(Raw "String")";  // 输出 Raw "String"
};

// 注意事项
namespace 注意事项 {
1. 流状态管理：
   - 使用good()/fail()检查状态
   - 错误处理示例：
        while(cin >> value) {
            // 正常处理
        }
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

2. 性能优化：
   - 减少格式切换频率
   - 使用'\n'代替endl避免频繁刷新
   - 预分配字符串流缓冲区
};

