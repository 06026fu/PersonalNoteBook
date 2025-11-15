# 单片机
--------------------------------------------------

# 1. 入门
## 1.1 用 STM32CubeMX 和 Clion 配置工程
#### Clion 创建工程
1. 顶栏 File, New, Project, 左侧选STM32CubeMX, 设置工程目录和工程的名称, Create
   ```
   例如:
   Location: E:\Projects\MyProject
   ```
2. 左栏双击 工程名.ioc, 右侧 Open with STM32CubeMX

#### STM32CubeMX 基础配置
**在配置好Project Manager之前都不要点保存**

3. 上栏 Piniout & Configuration, 左栏RCC（时钟设置）, 左栏右侧栏High Speed Clock 改为 Crystal Resonator (晶振) 
4. 左栏 System Core, SYS栏 (这里决定代码如何烧录) , 左栏右侧栏Debug改为Serial Wire
5. 上栏 Clock Configuration
   - 左侧的输入频率应与硬件一致, 要照着原理图填, 不能填错, 例如这里是8MHz, 则 HSE 的 Input frequency也应填8M ![硬件晶振]
   - Pll Source Mux 选中 HSE
   - System Clock Mux 选中 PLLCLK
   -  (主频) HCLK 下面例如 168 MHz max, 可直接配到最高主频, 框内填168, 回车让其自动计算 
6. 上栏 Project Manager
   - 左栏Project
     - 在ToolChain/IDE 处选择STM32CubeIDE
     - **Ptoject Name 一定要和在Clion中建立的一致!!!**
         ```
         例如:
         Project Name:              MyProject
         Project Location:          E:\Projects
         Toolchain Folder Location: E:\Projects\MyProject\
         ```
   - 左栏Code Generator, 勾选 Generate peripheral initialization as a pair of '.c/.h' files per peripheral
     - Src 文件夹储存 .c 文件
     - Inc 文件夹储存 .h 文件
7. 顶栏 Generate Code, Overwrite

#### Clion 基础配置
8. 回来后会出现 Board Config Files 弹窗, 随便选一个 \
   ![Clion面板配置弹窗]
9. 点击顶栏此处, Edit Configurations ![OpenDebugConfigurations]
10. 更改为对应烧录器的配置文件, 例如使用DAP-Link \
   ![DAPLink配置文件]

## 1.2 写一个闪灯程序
#### STM32CubeMX 配置 LED
1. 看原理图, 例如看到LED2对应芯片上对应PC5管脚
2. 上栏 Piniout & Configuration, 右下角搜索框搜索PC5
3. 左键对应的引脚, 设置为GPIO_Output
   - (GPIO_Input 为读取引脚当前是高电平/低电平)
   - (GPIO_Output 为设置引脚当前是高电平/低电平)
   - (GPIO_Analog 为模拟信号)
4. 左栏 System Core, GPIO栏, 左栏右侧栏选中PC5, 下方User Label, 可改为LED2
5. 顶栏 Generate Code

#### Clion 写闪灯程序
6. 在 main.c 的 while(1) 内输入
   ```c
   HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin); // LED2_xxx 已在 main.h 中定义
   HAL_Delay(500); // 阻塞500毫秒
   ```
7. 顶栏 点 ![顶栏运行键] (构建并烧录) 

## 1.3 STM32CubeMX的其他配置
- 左栏 System Core, Analog栏
  - ADC模数转换器, (例如用在激光测距, 激光测距输入模拟信号, 需要转换为数字信号进行处理)
  - Timers 计时器
  - Connectivity 消息的传递转发, (例如串口、CAN)
  - Multimedia (例如DCMI接显示器或相机。不常用, 因为相机一般不会用STM32处理)
  - Middleware 中间层, (FREERTOS可以嵌入一个操作系统, USB_DEVICE例如用单片机开发一个键盘鼠标等)


--------------------------------------------------
--------------------------------------------------
# 2. 基础知识
- 总线: 连CPU和其他部件 (优势: 一条线上可挂多个设备, 节约连线) , 例如![总线举例], 任一时刻只有一个发送数据, CPU是管理者
- 三态门举例 ![三态门举例]
- 8位机、32机位机等, 数字为总线宽度, 代表CPU的ALU (逻辑运算单元) 能做8bit或32bit数据的加法和逻辑运算
- FPU (浮点运算单元) 可做乘法
- 位数宽度: 地址总线 <= 数据总线
## 2.1 单片机部件
- Register (寄存器) : 放临时数据
- Flash: 放程序
- RAM: 内存
  - SRAM：静态内存，不断电就一直在
  - DRAM：动态内存，定时刷新，读取速度远低于前者，容量大
- Instructrion Decode (指令解码器) : 把数变为控制信号 (操作数)  (如加法后续再取两个数作为数据) 
- AMBA上总线
  - AHB（Advanced High performance Bus）作为系统总线
  - APB（Advanced Peripheral Bus）作为外设总线
    - APB1 用于低速外设
    - APB2 用于高速外设
## 2.2 单片机结构
- 哈佛结构: 指令集中放置, 不会和数据混取, 更安全
- 冯·诺曼结构 (普林斯顿) : 数据和控制放到一起
 ![冯诺依曼普林斯顿]
## 2.3 芯片命名含义(例如STM32F407ZGT6)
- STM32: 产品系列, 基于ARM的32位控制器
- F：产品类型, 通用类型
- 407：产品子系列, 103增强型
- Z：引脚数目 (T=36, C=48, R=64, V=100, Z=144) 
- G：山村存储器容量 (4=16KB, 6=32KB, 8=64KB, B=128KB, C=256KB, D=384KB, E=512KB, G=1024KB) 
- T：封装 (H=BGA, T=LQFP, U=VFQFPN, Y=WLCSP64) 
- 6：温度范围 (6=-40℃~85℃, 7=-40℃~105℃) 
## 2.4 其他部位命名含义
- P开头：外部管脚
- VSS（接地）、VDD（电源）应分别接在一起
- VBAT：接电池，外部电源点开可保存一部分数据
- NRST：N代表negative，低电平复位
- BOOT：模式选择
- SYS：下载口
- RCC：时钟（外部晶振很稳定，RC振荡器误差大）
- GPIO：通用
- ADC：模数转换（电压模拟信号转为数字信号，例如声音采样）
- TIM：定时器
## 2.5 工程目录组成
- .ioc 工程文件
- core 源代码（可改）
- drivers 底层源代码
## 2.6 读外设的方法
- POLL 轮询（主动）
- Interrupt 中断（被动）（关于中断的使用方法，以前计算机以CPU为核心，现在以储存器为核心，DMA直接内存存取效率高）
- 



--------------------------------------------------
--------------------------------------------------
# 3. 时钟
## 3.1 APB1 peripheral clocks 和 Timer clocks: 
- APB1 Peripheral Clocks (APB1外设时钟) : 
   - APB1 Peripheral Clocks 是系统总线上的一个时钟域, 它提供了对一系列外设 (如串口、SPI、I2C等) 的时钟信号。
   - 这个时钟域的频率通常由系统时钟源 (一般是HSI、HSE、PLL等) 分频得到, 因此它的频率不同于主时钟 (SYSCLK) 。
   - 这个时钟域可以通过设置RCC (Reset and Clock Control) 寄存器来调整其频率分频比例, 以满足外设的时钟要求。
- Timer Clocks (定时器时钟) : 
   - Timer Clocks 是专门为定时器模块 (如TIM1、TIM2、TIM3等) 提供的时钟信号。
   - 定时器时钟通常直接来自于APB1 Peripheral Clocks, 但在一些情况下, 也可以来自APB2 Peripheral Clocks。
   - 定时器时钟的频率可以通过分频器来配置, 以满足具体的定时器应用需求。这使得您可以根据应用的需要调整定时器的工作频率。
# 3.2 STM32时钟系统
- 类型：
  - HSI（High Speed Internal）
  - HSE（High Speed External）
  - LSI（Low Speed Internal）
  - LSE（Low Speed External）
  - PLL（Phase Locked Loop）（锁相环倍频输出，先乘背书产生极高的倍率再分频）
- 选择：
  - 内部：无需精确的场景
  - 高速：CPU
  - 低速：RTC
  - HSI、HSE、PLL可用来驱动系统时钟
  - LSI、LSE二级时钟源


--------------------------------------------------
--------------------------------------------------
# 4. Cmakelists
## 4.1 构建类型
构建类型用来指定编译器的优化级别和调试信息的生成。不同的构建类型会影响程序的性能和可调试性。

相比debug模式, release模式的不同点在于: 
- 开启更高级别的优化, 使得程序运行更快, 但也会增加编译时间。
- 去掉调试信息, 使得程序占用更少的空间, 但也会导致无法使用调试器进行断点和变量查看。
- 关闭断言, 使得程序更稳定, 但也会忽略一些潜在的错误。

一般来说, release模式适合发布给用户使用, 而debug模式适合开发和测试阶段。

```
set(CMAKE_BUILD_TYPE "Release")
```




--------------------------------------------------
--------------------------------------------------
