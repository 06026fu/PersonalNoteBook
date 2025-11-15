# Linux ROS2
--------------------------------------------------

# 1. 安装相关

## 1.1 安装.deb文件
```shell
sudo dpkg -i package-file-name.deb
```
修复依赖关系:
```shell
sudo apt install -f
```

## 1.2 便捷启动程序
例如, Groot2软件的安装位置是`~/dev_ws/Groot2/bin/groot2`, 每次都需要cd进这个目录, 用`./groot2`命令来启动程序。**为了能打开终端后在任何位置都可以用`groot2`命令直接启动这个程序**: 
1. 在 `.bashrc` 文件内添加一行 `export PATH="$PATH:~/dev_ws/Groot2/bin"`
2. 终端内运行命令`source ~/.bashrc`


--------------------------------------------------
--------------------------------------------------
# 2. 终端基础命令
```shell
# 列出终端所在路径
pwd

# 列出当前目录下的文件
ls

# 创建文件夹
mkdir 文件夹名

# 创建文件
touch 文件名.后缀

# 删除文件
rm 文件

# 递归删除文件
rm -R 文件夹名

# 进入目录
cd 文件夹名

# 返回上一层目录
cd ..

# 用更高权限安装应用/库
sudo apt install 应用名/库名

# 卸载软件包
sudo apt remove 软件包名

# 卸载软件包和配置文件
sudo apt purge 软件包名

# 在 NVIDIA Jetson 系列开发板上查看 CPU GPU 资源使用情况
sudo -H pip install jetson-stats
jtop
```


--------------------------------------------------
--------------------------------------------------
# 3. 功能包 & 节点

## 3.1 安装依赖
```shell
cd ~/dev_ws/src
sudo pip install rosdepc
sudo rosdepc init 
rosdepc update
```

```shell
cd ~/dev_ws
rosdepc install -i --from-path src --rosdistro humble -y
```

## 3.2 创建功能包
```shell
cd ~/dev_ws/src
ros2 pkg create --build-type ament_cmake package_name    # C++
ros2 pkg create --build-type ament_python package_name   # Python
```

## 3.3 编写程序
#### C++
- 在ROS2中, C++功能包中的.hpp文件通常用于声明类、结构体、模板和函数原型。然而, 它也可以包含函数体。这种做法在模板类或者内联函数的定义中比较常见。将函数体放在.hpp文件中可以让编译器在编译时期就看到函数的定义, 这对于模板和内联函数的优化非常重要。但是, 这样做可能会增加编译时间, 并且如果函数定义在多个地方被包含, 还可能导致链接错误。
- 通常的做法是在.hpp文件中声明, 在.cpp文件中定义。这样做的好处是保持代码的清晰结构, 提高编译效率, 并避免潜在的链接问题。但是, 对于模板类和内联函数, 由于它们需要在编译时期被实例化或优化, 所以它们的定义通常会放在.hpp文件中。

#### Python
```python
rclpy.spin(node)
    # 阻塞型循环, 不断查看队列, 若队列里有数据则进入回调函数处理
rclpy.spin_once(node)
    # 循环执行一次节点
```

## 3.4 构建功能包
排除某些功能包
```
在功能包目录中放置名为COLCON_IGNORE的空文件
```
构建
```shell
sudo apt install python3-colcon-ros
source /opt/ros/humble/setup.bash
cd ~/dev_ws
colcon build
```
```shell
# 只构建几个功能包
colcon build --packages-select my_package1 my_package2
```

package.xml储存功能包需要的依赖
编写python功能包时需要在setup.py中

```
entry_points={
    'console_scripts': [
        '节点名 = 功能包名.文件名:函数名',
        ...
```

## 3.5 节点的终端命令
```shell
# 运行功能包中的某个节点
ros2 run 功能包名 节点名

# 列出节点
ros2 node list

# 查看节点信息
ros2 node info 节点名
```


--------------------------------------------------
--------------------------------------------------
# 4. 话题
单向

## 4.1 话题消息的类型结构
由.msg文件定义
```msg
# 例如: 
# 通信数据
int32 x
int32 y
```
```
例如uint8[] xxx可表示数组
```

## 4.2 话题的终端命令
```shell
# 列出话题
ros2 topic list

# 查看节点信息
ros2 topic info /话题名

# 打印话题
ros2 topic echo /话题名

# 往话题发送一次消息
ros2 topic pub /话题名消息类型 消息 --once

# 往话题周期性发消息
ros2 topic pub --rate 频率赫兹 /话题名 消息类型 消息

# 录制 (保存到终端所在目录)
ros2 bag record /话题名

# 回放
ros2 bag play /话题名
```

--------------------------------------------------
--------------------------------------------------
# 5. 服务
节点间的你问我答, 双向。服务器唯一, 客户端可不唯一\
.srv文件定义数据结构:
```srv
# 例如: 
# request结构体 (客户端发送的请求)
int64 a
int64 b
---
# response结构体 (服务器端返回的应答)
int64 sum
```

## 5.1 查看接口数据结构在哪定义
```shell
ros2 service type /服务名
```

## 5.2 命令行请求服务器
```shell
ros2 service type /服务名
```


--------------------------------------------------
--------------------------------------------------
# 6. 通信接口
标准消息类型存放处于`/opt/ros/humble/share/`

列出系统内全部接口定义
```
ros2 interface list
```

查看某接口定义
```
# 查看标准定义例如
ros2 interface show sensor_msgs/msg/Image

# 查看功能包自定义例如
ros2 interface show 功能包名/action/xxx
```

查看功能包定义的接口
```
ros2 interface package 功能包名
```

自定义消息类型后需要放入CmakeLists, 例如: 
```
rosidl_generate_interfaces(${PROJECT_NAME}
    # 功能包目录下的
    "srv/GetObjectPosition.srv"
    ...
    )
```

引用自定义消息类型(python)
```python
from 功能包.其中某个文件夹 import 接口
# 例如: 
# 目录结构: learning_interface/srv/GetObjectPosition.srv
# from learning_interface.srv import GetObjectPosition
```


--------------------------------------------------
--------------------------------------------------
# 7. 动作
完整行为的流程管理, 一直有反馈, 就像有进度条, 可以把控进度

.action文件定义数据结构:
```
#目标
bool enable
---
# 结果
bool finish
---
# 反馈 (当前执行到的位置) 
int32 state
```

```
ros2 action list
ros2 action info /动作名
ros2 action send_goal /动作名 动作数据结构  "变量: 数值"
# 例如: 
# ros2 action send_goal /turtle1/rotate_absolute turtlesim/action/RotateAbsolute "{theta: 3.14}"
    # 需要周期反馈结尾再加 --feedback
```


--------------------------------------------------
--------------------------------------------------
# 8.其他
- RCLCPP_INFO函数需要一个C风格的字符串作为参数。因此, 你需要调用.c_str()来将std::string对象转换为C风格的字符串。

## 8.1 ros2 run 命令传递参数给节点
- argc: 传递给节点的参数数量
- argv: 字符串数组, 包含了传递给节点的所有参数
```cpp
#include "rclcpp/rclcpp.hpp"
#include <iostream>

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    // Print all command line arguments
    for (int i = 0; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }

    // Your node logic here

    rclcpp::shutdown();
    return 0;
}
```

## 8.2 打印消息
- WARN: 程序遇到可能会影响其正常运行但不一定会导致错误的情况 \
    (例如, 如果输入数据不在预期的范围内, 或者某个操作需要的时间比预期的要长)
- ERROR: 程序遇到错误, 但仍然可以继续运行
- FATAL: 程序遇到无法恢复的错误, 无法继续运行
```cpp
RCLCPP_DEBUG(this->get_logger(), "我是DEBUG级别的日志, 我被打印出来了!");
RCLCPP_INFO(this->get_logger(), "我是INFO级别的日志, 我被打印出来了!");
RCLCPP_WARN(this->get_logger(), "我是WARN级别的日志, 我被打印出来了!");
RCLCPP_ERROR(this->get_logger(), "我是ERROR级别的日志, 我被打印出来了!");
RCLCPP_FATAL(this->get_logger(), "我是FATAL级别的日志, 我被打印出来了!");
```
![ROS2打印消息]







如果你的服务端节点可能会被长时间阻塞, 你可以考虑以下几种策略来确保服务请求能够及时处理: 

1. **多线程处理**: 你可以在服务端节点中使用多线程, 每个线程处理一个服务请求。这样, 即使一个线程被阻塞, 其他线程仍然可以处理新的服务请求。

```cpp
rclcpp::Service<my_service>::SharedPtr service =
  node->create_service<my_service>("my_service", 
    [](const std::shared_ptr<my_service::Request> request, 
       std::shared_ptr<my_service::Response> response) {
      std::thread([](std::shared_ptr<my_service::Request> request, 
                     std::shared_ptr<my_service::Response> response) {
        // 处理服务请求
      }, request, response).detach();
    });
```

2. **异步处理**: 你可以使用异步编程模型来处理服务请求。这样, 即使处理服务请求的函数需要长时间运行, 也不会阻塞事件循环。

```cpp
rclcpp::Service<my_service>::SharedPtr service =
  node->create_service<my_service>("my_service", 
    [](const std::shared_ptr<rmw_request_id_t> request_header, 
       const std::shared_ptr<my_service::Request> request, 
       std::shared_ptr<my_service::Response> response) {
      // 创建一个新的 future 对象
      std::future<void> future = std::async(std::launch::async, []() {
        // 处理服务请求
      });
    });
```














--------------------------------------------------
--------------------------------------------------
# Robocup无人机仿真 (ROS1 Melodic)

## 欧拉角
roll pitch yaw \
缺点: 有万向锁 \
如果飞机俯仰角到达±90°时, 滚转运动和偏航运动的旋转轴重合了

## 四元数
四元数 w+xi+yj+zk 可以完备地表示任何一个旋转状态

## 强行关闭gazebo所有进程
```
killall -9 gzclient
killall -9 gzserver
```

## 用键盘控制无人机飞行

```
cd ~/PX4_Firmware
roslaunch px4 indoor1.launch
```

等Gazebo完全启动, 新开终端

```
cd ~/XTDrone/communication/
python multirotor_communication.py iris 0
```

新开终端

```
cd ~/XTDrone/control/keyboard
python multirotor_keyboard_control.py iris 1 vel
```

按 I 把向上速度加到0.3以上, 按 B 切offboard模式, 按 T 解锁。

飞到一定高度后可以切换为‘hover’模式悬停, 再利用键盘控制飞机, 或运行自己的飞行脚本。

![无人机目录]









--------------------------------------------------
