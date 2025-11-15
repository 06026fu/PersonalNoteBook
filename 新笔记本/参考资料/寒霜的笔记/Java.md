# Java
--------------------------------------------------

# L03 Java History And Basics

## 3.1 主类需要与文件名一致
```java
// Myprogram.java
public class Myprogram{
    // methods (similar as functions in C)
}
```

## 3.2 Compile in CMD
```shell
javac 文件名.java
# 编译为.class文件

javac *.java
```

## 3.3 Run
```shell
java 文件名
```

## 3.4 main() Method
```java
public static void main (String[] args)
```
- **method name**: main means the entry point for the program 
- **static**: means there's a single instance of the method and it's associated with the class rather than individual objects
- **access restrictions**: public means it's globally accessible 
- **type of value returned by method**: void means it returns nothing 
- **command line arguments**: accessed as an array of Strings (more later)

## 3.5 打印
print 在现在这行打印 \
println 换行打印


--------------------------------------------------
--------------------------------------------------
# L04 Nuts and Bolts

## 4.1 命名
Varable & Method: start with lower case, like myVariable \
Class: start with upper case, like MyProgram

## 4.2 类型的兼容
小的类型可以直接用于大的类型, 比如float变量可以直接参与double类型的运算, 反之不行(需要类型转换) \
byte < short < int < long < float < double
```java
public double squareX(int x) { return x*x; } // valid
public int squareY(double y) { return y*y; } // invalid
```

## 4.3 强制类型转换 Type Casting
eg: `(int)1.3` 丢弃小数

## 4.4 自增
a = b++ 先赋值再自增
```java
public class Test {
    public static void main(String args[]){
        int a = 0;
        int x = a++ + 5;
        System.out.println(x); //x为5
    }
}
```

## 4.5 Continue
跳过本次循环体中剩下尚未执行的语句, 立即进行下一次的循环条件判定


--------------------------------------------------
--------------------------------------------------
# L05 Object 

## 5.1 Structure of Class
1. Class Name
2. Attributes (states)
3. Operations (behaviours) (Written by methods)

## 5.2 Object
- Object is defined by a class 
- Class defines attributes and operations 
- An object is an instance of a particular class 
- Object stores attributes and operations
- A class only exists at compile time
- An object only exists at runtime

## 5.3 Abstraction
为几个相似的subclass抽象出一个super class \
subclasses inherit the methods form the super class
```java
public class ParticularShape extends Shape{
    // ...
}
```

## 5.4 Method
```java
// modifier returnType methodName()
public int methodName(int x, int y){
    // ...
}
```

## 5.5 Stack 栈
方法执行时, 占用stack \
计算完后空间释放


--------------------------------------------------
--------------------------------------------------
# L06 

## 6.1 Create Instance
occupy the space of heap (堆)
- `Cat myCat` allocate space for reference variable of type Cat called myCat
- `new Cat()` allocate space for a new Cat object on the heap
```java
Cat myCat = new Cat();
```

## 6.2 Encapsulation 封装
public protected default private
1. Private (类访问级别) : 表示私有的, 被private修饰的成员, 仅能包含该类的其他成员访问, 任何其他类都不能访问, 即private成员只能在类的内部使用。
2. Default (包访问级别) : 如果一个类或类的成员不使用任何访问控制修饰符, 则称它为默认访问控制级别, 这个类或类的成员只能被本包中的其他类访问。
3. Protected (子类访问级别) : 被protected修饰的类的成员, 既可以被同一个包中其他类访问, 也可以被不同包中的子类访问。protected比默认访问权限的访问范围要宽。 (protected=默认权限+不同包中的子类) 
4. public (公共访问级别) : 是最宽松的访问级别权限, 如果一个类或者类的成员被public访问控制符修饰, 那么这个类或者类的成员能被所有的类访问, 不管访问类和被访问类是否在同一个包中。


--------------------------------------------------
--------------------------------------------------
# L07

## 7.1 初值
Java automatically sets some initial values for you for variables of the class (instance variables), **but not for variables in methods**. 
- boolean: `false` 
- char: `'\u0000'` 
- byte, short, int, long: `0` 
- float / double: `+0.0f` / `+0.0d` 
- object reference: `null`

## 7.2 Heap 堆
![Life_on_the_heap]
b 储存着对第一个Rabbit对象的引用 \
c 和 d 同时储存着对第二个Rabbit对象的引用 \
( 通过d修改对象的属性后, 通过c访问对象时, 访问到的也是修改后的结果 )

## 7.3 Method Overloading 重载
define same method with different parameter list
```java
public int run(int duration, boolean zigzag) {...}
public int run(int duration){...}
// Both of these methods can exist in the class Rabbit.
// Which one is called depends on how you call it, e.g.
// ...
int distance = bugs.run(5, true); 
// OR 
int distance2 = bugs.run(5);
```
```java
// 错误, 传参列表不能完全相同
run (int dur){...}
run (int dis){...}
```

## 7.4 Constructor
等效于python的__init__, 类的初始化方法 \
Constructor 的名字必须与类的名字一致
```java
public class RaceCar {
    private String bodyColour;
    public RaceCar(String input) {   // Constructor
        this.bodyColour = input;
    }
}
```


--------------------------------------------------
--------------------------------------------------
# L09 Array
provides fast random access by using index position 

## 9.1 Declaration
```java
typeName arrayRef[];
// or
typeName[] arrayRef;

// eg. Sting[] args
```

## 9.2 Using New to Create
```java
int[] nums = new int[7]; // an array is an object

MyClass array[0] = new MyClass(); // fill the first place in array with a MyClass object
```

## 9.3 Exception
- ArrayIndexOutOfBounds
- NullPointerException

## 9.4 Method Overriding 重写
redefine the inherited method for particular subclass
```java
// default:
for (int i = 0; i < rabbit_array.length; i++) {
    System.out.println(rabbit_array[i]); // call the default toString() method
}

// output:
// Rabbit@3e25a5
// Rabbit@923e30
// Rabbit@9cab16

// toString() 方法被定义在内置的 Object Class 中, 我们定义的类都是它的子类
// 打印 object 程序会自动调用 toString() 方法, 可以在我们的类中重写此方法以自定义打印内容
```
```java
// override:
public class Rabbit {
    // ...
    public String toString() {
        return this.getName() + " is a " + this.getFurType() + 
        " Rabbit that runs at " + this.getSpeed() + " km/hr.";
    }
}
```

## 9.5 Java Docs
```shell
# create the docs subfolder
javadoc -d docs file.java
```


--------------------------------------------------
--------------------------------------------------
# L11 ArrayList
ArrayList can enlarge or shrink
```java
// define
ArrayList<Flower> myList = new ArrayList<Flower>(); // <Type>
```
## 11.1 Add Element
.add()是引用传递, 将对象的引用添加到列表中
```java
Flower f = new Flower();
myList.add(f); 
// r 和 myArrayList 的第一个位置都存储着新对象的引用
```

## 11.2 Compare ArrayList with Array
```java
// create
String[] my_array = new String[6];
ArrayList<Type> my_array_list = new ArrayList<Type>();

// assign an object
my_array[0] = b;
my_array_list.add(b);

// get an object
my_array[4];
my_array_list.get(4);
```

## 11.3 Convert Int to String
```java
b = "" + 3; // "3"
c = "" + 3 + 1; // "31"
```


--------------------------------------------------
--------------------------------------------------
# L12 Inheritance

## 12.1 Aggregation 聚合
eg. The Car object **has** (contains) four Tire objects.
```java
public class RangeRover {
    public Tire[] array = new Tire[4];
    // array是长度为4的Tire类型的数组
    // 之后可以如 array[0] = new Tire();
    public void drive() {
    // do driving things ... 
    }
}
```

## 12.2 Inheritance 继承
- **Subclasses inherit the properties (attributes and operations) of their superclass.**
- private instance variables and methods are not inherited

eg. The class BlueCar **is** a subclass of the superclass Car
```java
public class Car {   // the superclass
    public String bodyColour;
    public void drive() {
    // do driving things ... 
    }
}

public class BlueCar extends Car {   // the subclass
    // ...
}
```

## 12.3 Polymorphism 多态
Using a single definition (superclass) with different types (subclass)
```java
public class Creature(){
    // ...
}

public class Turtle extends Creature{
    // ...
}

public class Rabbit extends Creature{
    // ...
}

Creature aCreature = new Creature();   // valid
Creature aCreature = new Turtle();   // also valid
Creature aCreature = new Rabbit();   // also valid
// creature reference can put a creature object, a turtle object, or a rabbit object
```

## 12.4 Abstract Class
abstract class cannnot be instantiated
```java
public abstract class Creature(){   // abstract class
    // ...
}

public class Turtle extends Creature{
    // ...
}

Creature aCreature = new Turtle();   // valid
Creature aCreature = new Creature();   // not valid
```
**concrete class**: non-abstract class is called 

## 12.5 Abstract Method
abstract method must be overridden in the concrete child class (if the subclass is abstract then it's fine)
```java
public abstract class Creature { 
    // ...
    public abstract int run(int duration, boolean zigzag);   // run() is a abstract method
}

public class Turtle extends Creature{
    // ...
    public int run(int duration, boolean zigzag) {   // must override run() method in subclass Turtle
        // ...
    }
}
```
if a class contains at least one abstract method, then the class must be abstract

## 12.5 Mega Class
`java.lang.Object` is the ultimate parent of EVERY class in java. \
It is implicitly inherited by every class. 

## 12.6 State
the value of the instance variable

## 12.7 Convert & Override
```java
// override equals() method
public boolean equals (Object o){
    Rabbit r = (Rabbit)o;
    if(r.getRabbitSpeed() == this.getRabbitSpeed())
        return true;
}

// 这个类和这个类的子类 的对象才能转换为这个类的类型
// e.g.
// A类
// |
// B类 (是A的子类) 
// |
// C类 (是B的子类) 
//
// C obj = new C();
// A a = (A) obj;
// 只有A和A的子类可以转换成A
```
## 12.7 Call the Parent Class Method after overriding
```java
public class ParentClass{
    public void method(){
        // ...
    }
}

public class SubClass extends ParentClass{
    public void method(){   // overriding
        // ...
    }
    super.method();   // call the method defined in ParentClass
}
```


--------------------------------------------------
--------------------------------------------------
# L14 Interface

## 14.1 Example
```java
public interface Flyable {
    public abstract void fly(); // OR public void fly(); 
    // Even if you don't declare the method abstract or public, it is!!!
    // Interface cannot be instanciated: e.g. Flyable a = new Flyable() // Error
}
```
```java
public interface Walkabe {
    public abstract void walk(); 
}
```
```java
public class FlyingSquirrel extends Creature implements Flyable, Walkabe {
    public void fly() //must provide implementation (method body), as you "said" you are Flyable
    {
        // some code
    }
    public void walk() 
    {
        // some code
    }
}
```
## 14.2 Notes
- A subclass can extend **one** superclass but implement **many** interfaces
- An interface may have many methods. If a class implements an interface, but only implements some of its methods (that is, create definition of the method), then this class becomes an abstract class; it cannot be instantiated.
- If you don't provide any method implementation, then it's better to use an interface instead of an abstract class.

## 14.3 Extending the Interface
```java
interface Father 
{
    int age = 30;
    void wash();
}
interface Mother 
{
    long bank_account = 100000;
    void cook();
}
interface Child extends Father, Mother
{
    void cry(boolean tear);
} // Child has age, bank_account, cook(), wash(), cry()
```
- If Father interface and Mother interface have the same methods:
  - different parameters: ok, it's overloading
  - differ by only return type: error
  - identical: only keep one
- If Father interface and Mother interface have the same variables:
  - ok, use Father.variable or Mother.variable to refer one of them


--------------------------------------------------
--------------------------------------------------
# L16 Garbage Collection

## 16.1 Heap & Stack
They are the main areas of memory.
- Heap: 
  - Garbage-collectible
  - where objects live
- Stack: 
  - where local variables and methods, when called, live
  - Method at top of the Stack is always the method being executed
  - ![Example_of_the_Stack]

## 16.2 Variables
- Local Variables:
  - goes on the **Stack**
  - Variables declared in a method and method parameters.
  - Temporary variables, alive only when the method they belong to is on the Stack.
  - The local object reference variable goes on the stack, and the object it refers goes on the Heap
- Instance Variables:
  - goes on the **Heap**
  - Variables declared in a class (not inside of a method).
  - Live inside the object they belong to.

## 16.3 Overloaded Constructors
```java
public class Account 
{
    public Account() 
    {
        // ...
    } 
    public Account(int balance) 
    {
        // ...
    }
    public Account(int balance, boolean giveOverdraft) 
    {
        // ...
    }
    public Account(boolean junior, int balance) 
    {
        // ...
    }
}
```

## 16.4 Constructor Chaining
When a new object is created, all the constructors in its inheritance tree must be run. \
The constructor of the superclass will run first implicitly
```java
public class BigCat {
    public BigCat() 
    {
        System.out.println("Making a BigCat");
    }
}
public class Tiger extends BigCat {
    public Tiger() 
    {
        System.out.println("Making a Tiger");
    }
}
public class TestTiger {
    public static void main(String[] args) 
    {
        System.out.println("Starting ...");
        Tiger myTiger = new Tiger();
    }
}
// Output:
// Starting ...
// Making a BigCat
// Making a Tiger
```

## 16.5 Using Superclass Constructor in Subclass
- `super()`, and can use parameters in the bracket
- If call super() explicitly, super() must be the first statement in a constructor.
```java
public Dog(int dogWeight) {
    weight = dogWeight;
    super();  // Wrong
}
```

## 16.6 Using this() for Overloaded Constructor
```java
public class Tiger()
{
    public Tiger()
    {
        this(5);
    }

    public Tiger(int a)
    {
        System.out.println(a);
    }
}
```

## 16.7 Life of Objects and Variables
- object: lives when its reference lives
- instance variable: lives when object they belong to lives
- local variable: lives when:
  - being in scope, or
  - out of scope but the method where it was declared is in stack
```java
public class ExampleGoneWrong {
    public void method1() 
    {
        int x = 10;
        method2();
    }
    public void method2() 
    {
        x = 20; // x is still alive since method1 is still in the stack, however x is out of scope so it's an error
    }
}
```


--------------------------------------------------
--------------------------------------------------
# 17 String

## 17.1 Example
```java
// Different from other object:
String s1 = "Sherlock";
String s2 = s1;
s2 = "Holmes"; 
System.out.println(s1);  // Sherlock
System.out.println(s2);  // Holmes
```

## 17.2 Elements of String  
starts at `0` and ends at `length() -1`

## 17.3 Operations
```java
String s = "HelloWorld!";
System.out.println(s.length());  // 11
c = s.charAt(5);  // c = 'W'
c = s.indexOf('W')  // c = 5, returns ch's first occurrence position (int); if not found, returns -1.
if (s.equals("abc")) // false
```
- `compareTo(str)`: compares two strings, returns int that is <0, >0, =0
    ```java
    String str1 = "abc";
    String str2 = "aef";
    int result = str1.compareTo(str2); // 从第一个字符开始比较字典序, b 在 e 前, 返回负数
    ```
- `substring(index1,index2)`: returns the substring between index1 and (excluding) index2.
    ```java
    String s = "HelloWorld!".substring(1,6); 
    // S = "elloW";
    ```
- `concat(s)`: concatenates two strings.
    ```java
    String s = "Hello".concat("World"); // s = "HelloWorld"
    ```
- `toUpperCase()` / `toLowerCase()`: convert all characters in string to 
upper/lower case.
    ```java
    String sUpper = "Cat".toUpperCase(); // sUpper = "CAT"
    String sLower = "Cat".toLowerCase(); // sLower = "cat"
    ```
- `toString()`: convert input to a string.
    ```java
    double d = 12.3;
    String dString = Double.toString(d); // dString = "12.3"
    ```
- `split(String s)`: splits the string around matches of the given regular expression s and returns an array with those substrings.
    ```java
    public class UsingSplit 
    {
        public static void main(String[] args) 
        {
            String str = "bar:foo:bar";
            String[] splitStr = str.split("a");
            for (int i=0; i < splitStr.length; i++)
                System.out.println(splitStr[i]);
        }
    }
    // b
    // r:foo:b
    // r
    ```
- `void getChars(i,j,A,k)`: returns characters from i to j (excluding), and stores them into array A starting from A[k].
    ```java
    char[] A = new char[4];
    "The rain in Spain".getChars(4,8,A,0);
    // A = {'r','a','i','n'}
    ```
- `substring(index)`: returns substring from index to end.
    ```java
    String s = "Monkeys".substring(3); // s = "keys"
    String s = "Monkeys".substring(3,"Monkeys".length()-1); 
    // s = "key"
    ```
- `replace(oldCh,newCh)`: replace oldCh by newCh everywhere in the string.
    ```java
    String s = "goose".replace('o','e'); // s = "geese"
    ```

## 17.4 Character class
- static methods:
  - `isLetter(char c)`
  - `isDigit(char c)`
  - `isUpperCase(char c)`
  - `isLowerCase(char c)`
```java
// e.g.
Character myCharacter = new Character('c');
myCharacter.compareTo(new Character('f')); // returns -3
myCharacter.compareTo(new Character('a')); // returns 2
myCharacter.equals(new Character('e')); // returns false
Character.isLetterOrDigit(new Character('?')); // returns false
```

## 17.5 String Tokenizer
- old fashion. We should use split() instead.
```java
String s = "I am from Portugal.";
// Create a StringTokenizer.
StringTokenizer my_tokenizer = new StringTokenizer(s);
System.out.println("Number of tokens is " + my_tokenizer.countTokens() + ".");
while (my_tokenizer.hasMoreTokens())
    System.out.println(my_tokenizer.nextToken());

// Number of tokens is 4.
// I
// am
// from
// Portugal.
```
```java
StringTokenizer my_tokenizer = new StringTokenizer(s, "ru"); // seperate with 'r' and 'u'
// Number of tokens is 4.
// I am f
// om Po
// t
// gal.

StringTokenizer my_tokenizer = new StringTokenizer(s, "ru", true); // don't discard 'r' and 'u'
// Number of tokens is 7.
// I am f
// r
// om Po
// r
// t
// u
// gal.
```

## 17.6 The Format Specifier
```java
String.format("I have %,6.2f bugs to fix", 12345.6789);
// I have 12,345.68 bugs to fix
```
- % [argument_number$] [flags] [width] [.precision] type
  - argument_number$: which argument it refers to, if there’s more than one
  - flags: special formatting options, e.g. inserting commas, putting negative numbers in parentheses, left/right alignment
  - width: minimum number of characters used
  - .precision: number of decimal places
  - type: 
    - %d – decimal
    - %f – floating point
    - %x – hexadecimal
    - %c – character

--------------------------------------------------
--------------------------------------------------
# L19 Numbers

## 19.1 Final
- **Final variable**: Cannot be changed once initialized.
- **Final method**: Cannot be overridden in a subclass.
- **Final class**: Cannot be inherited.

## 19.2 Static
- **Static variable/method**: All objects share the same copy of the variable/method (class-wide global).
- **Static variable/method**: Can be called without an object, directly using the class name.

    ```java
    public class Math extends Object {
        public static float PI = 3.141592f;
        static double random() {
            // ...
        }
        // ...
    }
    ```
    ```java
    // Usage:
    Math.random(); // Call this method directly
    float p = Math.PI;

    // If the random() method is not static, we have to use an object to call this method
    Math m = new Math();
    m.random();
    ```

- Static Method
  - Static methods cannot access non-static methods.
  - Static methods can be accessed by subclass but cannot be overridden.
  - (Three types of variables: local ~, instance ~, static ~) 
  - Static methods can access the variables:
    - static variable
    - local variable that is declared inside
    - (cannot access the instance variable and outside non-static variable)

    ```java
    public class Parent {
        public static void print() {
            System.out.println("Parent");
        }
    }

    public class Child extends Parent {
        public static void print() {
            System.out.println("Child");
        }
    }

    public class Test {
        public static void main(String[] args) {
            Parent p = new Child();
            p.print();  // prints "Parent", since static method print is bound with Parent class when compiling

            Child c = new Child();
            c.print(); // prints "Child", not override
        }
    }
    ```

- Static Variable
  - Static variables are created and initialized with the class (before any object is created).
  - If a static instance variable changes, all of the objects will access the modified value.

## 19.3 Constant
**Static final**: Declares a constant.

```java
// e.g.
static final int MY_VARIABLE;
```

## 19.4 Math Method
```java
double rnd = Math.random() * 5.0; // returns 0.0 ≤ rnd < 5.0

double absNum = Math.abs(-123.45); // returns absNum = 123.45

int roundedValue;
roundedValue = Math.round(-10.8f); // -11
roundedValue = Math.round(-0.5); // 0
roundedValue = Math.round(0.5); // 1

double minValue = Math.min(123.45, 123.46); // returns minValue = 123.45

double maxValue = Math.max(123.45, 123.46); // returns maxValue = 123.46
```

## 19.5 Random Class
```java
import java.util.Random;
public class RandTest {
    public static void main(String[] args) {
        Random r = new Random();
        float aRandomFloat = r.nextFloat();
        int aRandomInt = r.nextInt();
        System.out.println("A random float is " + aRandomFloat);
        System.out.println("A random int is " + aRandomInt);
    }
}
```

## 19.6 Wrapper Classes
- (e.g. Character) used when variable of a primitive type (e.g. char) needs to be treated as an object.
- Wrapper classes are part of `java.lang` package (no need to import them explicitly).

## 19.7 Wrapping & Unwrapping
```java
int i = 10;
Integer iWrapped = new Integer(i);
int unWrapped = iWrapped.intValue();
```

## 19.8 Autoboxing
- Conversion from primitive type to wrapper object is automatic after Java 5.0.

```java
// After Java 5.0
public void doNumsNewWay() {
    ArrayList<Integer> listOfNumbers = new ArrayList<Integer>(); // ArrayList<int> is invalid
    listOfNumbers.add(3);
    int one = listOfNumbers.get(0);
}

// Before Java 5.0
public void doNumsOldWay() {
    ArrayList listOfNumbers = new ArrayList();
    listOfNumbers.add(new Integer(3));
    Integer one = (Integer) listOfNumbers.get(0);
    int oneUnwrapped = one.intValue();
}

// After Java 5.0
void takeMyNumber(Integer i) {
    // ...
}
int x = 1;
takeMyNumber(x); // valid due to autoboxing
```

## 19.9 Static Methods in Wrappers
```java
// Convert a `String` to a primitive value.
String str1 = "10";
String str2 = "123.45";
String str3 = "true";

int i = Integer.parseInt(str1); // i=10
double d = Double.parseDouble(str2); // d=123.45
boolean b = new Boolean(str3).booleanValue(); // b=true
```

## 19.10 Static Imports
Import a static method or variable to save on typing.
```java
import java.lang.Math;
class BeforeStaticImports {
    public static void main(String[] args) {
        System.out.println("square root is " + Math.sqrt(4.0));
    }
}
```
```java
import static java.lang.System.out;
import static java.lang.Math.*;

class WithStaticImports {
    public static void main(String[] args) {
        out.println("square root is " + sqrt(4.0));
    }
}
```

## 19.11 Abstract Class Number
Number \
  ├── Byte \
  ├── Short \
  ├── Integer \
  ├── Long \
  ├── Float \
  └── Double
```java
Number num = new Integer(10);
```
```java
System.out.println(Long.MIN_VALUE); // –2^63
int i = 181;
System.out.println("Hex value = " + Integer.toHexString(i));
```

## 19.12 Immutable
Classes like `Character`, `Byte`, `Short`, `String` define immutable objects (their content cannot be changed).

```java
String s = "Hello"; // the content of s cannot be changed
s = s + " World"; // will create a new String object rather than changing it
```

## 19.13 Recursion
Methods that call themselves. Without recursion, iteration can be used to solve the problem.

--------------------------------------------------
--------------------------------------------------
# L20 Exception Handling

## 20.1 Syntax for try/catch/finally Blocks
```java
try {
// code that can throw exceptions E1, ..., En
// statements in this section will end halfway if it encounters an exception
}
catch (E1 e1) {
// code to handle exception E1
}
// ...
catch (En en) {
// code to handle exception En
}
finally {
// it will execute regardless of whether or not an exception is thrown
}
```

## 20.2 Example
```java
public class RiskyClass {
    public void checkFileName(String s) throws Exception 
    {
        if (s.equals("/etc/passwd"))
        throw new Exception("bad filename");
    }
}
```
``` java
// Method 1: try + catch
public class TestExceptions{
    public static void main(String[] args) 
    {
        RiskyClass rc = new RiskyClass();
        for(int i = 0; i < args.length; i++) 
        {
            try {
                rc.checkFileName(args[i]);
            } // end try
            catch (Exception e) {
                System.err.println(""+ e + " at "+ i);
            }
        }
    }
}
// java TestExceptions /etc/passwd
// java.lang.Exception: bad filename at 0
```
```java
// Method 2: throw exception in main method
public class TestExceptions {
    public static void main(String[] args) throws Exception
    {
        RiskyClass rc = new RiskyClass();
        for (int i = 0; i < args.length; i++) 
        {
            rc.checkFileName(args[i]);
        }
    }
}
// java TestExceptions /etc/passwd
// Exception in thread "main" java.lang.Exception: bad filename
```

## 20.3 Creating Exception Classes
```java
public class MyException extends Exception 
{
    public MyException() 
    {
        super(); // call constructor of parent Exception
        // other appropriate code
    }
    public MyException(String s) 
    {
        super(); // call constructor of parent Exception
        // other appropriate code
    }
}
```
```java
public class MyDate {
    // ...
        if (a < 0) {
            throw new MyException();
        }
    // ...
}
```
```java
public class TestMyDate {
    public static void main(String[] args) throws MyException {
        MyDate d = new MyDate(-1980);
    }
}
```

## 20.4 Example
```java
try {
    statement1;
    statement2;
    statement3;
}
catch (Exception1 ex1) {
    // ...
}
catch (Exception2 ex2) {
    // ...
}
statement4;
```
- If an exception is thrown in statement1 or statement2, statement3 will not be executed. If no exceptions are thrown in statement1 or statement2, statement3 will be executed.
- If the exception is not caught, then the program will terminate and statement4 will not be executed.
- If the exception is caught in one of the catch clauses, the program will go on and statement4 will be executed.

## 20.5 Checked & Unchecked Exceptions
![Checked&UncheckedExceptions]
- Run-Time Exceptions: e.g. NullPointerException, ArrayStoreException, IndexOutOfBoundsException .etc

## 20.6 Example
![ExceptionsEx2] \
// test = "no": \
start try \
start risky \
end risky \
end try \
finally \
end of main

## 20.7 Assertion
- Can be used for internal checks.
- Syntax:
  - `assert expression`
  - `assert expression : detailMessage`
    ```java
    // e.g.
    assert i == 10;
    assert (sum>10 && sum<500) : "sum is" + sum;
    // if (i == 10) or (sum>10 && sum<500) is not met, java.lang.AssertionError will be thrown
    ```

## 20.8 Enable Assertion
- disable assertion
  - java 文件名
  - java -da 文件名
- enable assertion
  - java -ea 文件名
```java
public class Foo 
{
    public void m1(int value) 
    {
        assert 0 <= value;
        System.out.println("OK");
    }

    public static void main(String[] args) 
    {
        Foo foo = new Foo();
        System.out.print("foo.m1(1): ");
        foo.m1(1);
        System.out.print("foo.m1(-1): ");
        foo.m1(-1);
    }
}

// java Foo
// foo.m1(1): OK
// foo.m1(-1): OK

// java -ea Foo
// foo.m1(1): OK
// foo.m1(-1): Exception in thread "main" java.lang.AssertionError
```


--------------------------------------------------
--------------------------------------------------
# L21 File I/O

## 21.1 data form
- for human: text
- for computer: byte

## 21.2 Stream
A stream is a connection to a source of data or to a destination for 
data (sometimes both). Stream is a sequence of bytes and can represent any data

## 21.3 Methods in File
- `File(String pathname)`: creates file with specified pathname
- `boolean exists()` / `boolean isDirectory()` / `boolean isFile()`
- `boolean canRead()` / `boolean canWrite()`
- `boolean delete()`: returns true if file successfully deleted
- `String getAbsolutePath()`: returns complete absolute file/directory name
- `boolean renameTo(File dest)`: returns true if operation successful
- `long length()`: returns length of the file in bytes
- `String[] list()`: returns an array of strings containing the list of files in this directory
- `boolean mkdir()`:  returns true if folder successfully created

## 21.4 FileReader
- Constructor:
  - `public FileReader(String filename)`
  - `public FileReader(File file)`
- Methods:
  - `int read()`: read the next character 
  - `int read(char[] cbuf)`
  - `int read(char[] cbuf,int off,int len)`
  - `void close()`

## 21.5 Example of Read
```java
File file = new File("temp.txt");
FileReader in = new FileReader(file);
```
```java
import java.io.*;
public class FileReadTest 
{
    public static void main(String args[])
    {
        String fileName = "input.txt";
        String contents = "";
        try 
        {
            FileReader file_reader = new FileReader(fileName);
            BufferedReader buffered_reader = new BufferedReader(file_reader);
            String one_line = buffered_reader.readLine();
            while (one_line != null) 
            {
                contents = contents + one_line + "\n";
                one_line = buffered_reader.readLine(); // get one line of text
            }
            buffered_reader.close();
            file_reader.close();
        }
        catch (IOException ex) 
        { // file does not exist or not readable
            System.out.println("Errors occured");
            System.exit(1);
        }
        // It's ok but it's better to catch(FileNotFoundException ex2) as well
        System.out.println(contents);
    }
} 
```
## 21.6 FileWriter
- Constructor:
  - `public FileWriter(String filename)` 
  - `public FileWriter(File file)`
  - `public FileWriter(String filename, boolean append)`
  - `public FileWriter(File file, boolean append)`
- Methods:
  - `void write(int c)`
  - `void write(byte[] cbuf)`
  - `void write(char[] cbuf,int off,int len)`
  - `void write(String str)`
  - `void write(String str, int off,int len)` 
  - `void close()`
```java
FileWriter fw = new FileWriter("myFile.txt");
// Create a new FileWriter object to write data to myFile.txt.
// if the file myFile.txt does not exist, it will be created
// if the file myFile.txt exists, it will be overwritten (equivalent to delete and rewrite)
```

## 21.7 Example of Write
- `flush()` method of buffered writer ensures that data from previous calls to write() is sent to disk and leaves the file open.
```java
import java.io.*;
public class UsingFlush 
{
    public void write_to_file(String filename)
    {
        BufferedWriter buffered_writer = null;
        try
        {
            buffered_writer = new BufferedWriter(new FileWriter(filename));
            buffered_writer.write("Writing line 1 to file");
            buffered_writer.newLine(); // new line
            buffered_writer.write("Writing line 2 to file");
        }
        catch(FileNotFoundException ex) {ex.printStackTrace();}
        catch(IOException ex) {ex.printStackTrace();}
        finally
        {
            // close the buffered writer
            try
            {
                if(buffered_writer != null)
                {
                    buffered_writer.flush(); // ensures that data from previous calls to write() is sent to disk and leaves the file open
                    
                    // write more text to the output stream
                    buffered_writer.newLine();
                    buffered_writer.write("Writing line 3 to file");

                    buffered_writer.close(); // this method also includes flushing the stream
                }
            }
            catch (IOException ex) {ex.printStackTrace();}
        }
    }

    public static void main(String[] args) 
    {
        UsingFlush obj = new UsingFlush();
        obj.write_to_file("output.txt");
    }
} 
```

--------------------------------------------------
--------------------------------------------------
# L22 Collections & Sorting

## 22.1 Collection Framework: Interfaces
- Set: A collection that **contains no duplicate elements**; it models the mathematical set abstraction.
- List: An ordered collection (also known as a sequence). Elements can be accessed by their position in the list, and it is possible to search for elements in the list. Lists **allow for duplicate elements**.
- Map: An object that maps keys to values. A map does not contain duplicate keys; each key can map to at most one value.

## 22.2 Map
- cannot contain duplicate keys
- each key maps to one value only
```java
import java.util.*;
public class HashMapTester {
    public static void main( String[] args ) 
    {
        Map<String, String> petSounds = new HashMap<String, String>();
        petSounds.put("cat", "Meow"); petSounds.put("mouse", "Squeak");
        petSounds.put("dog", "Woof"); petSounds.put("guineaPig", "Squeak");
        System.out.println("map = " + petSounds);
        String val = (String)petSounds.get("dog");
        System.out.println("Value for key 'dog' is: " + val);
    }
}
// map = {mouse=Squeak, cat=Meow, dog=Woof, guineaPig=Squeak}
// Value for key 'dog' is: Woof
```

## 22.3 Iterator
- bool `it.hasNext()`: return true if there are more elements for the iterator
- object `it.next()`: returns the next object
- object `it.remove()`: removes the most recent element that was returned by **next**. If the collection does not support remove(), an UnsupportedOperationException will be thrown .
```java
// ...
    ArrayList<String> alist = new ArrayList<String>();
    // Add Strings to alist
    for (Iterator<String> it = alist.iterator(); it.hasNext(); ) 
    {
        String s = it.next(); // No downcasting required.
        System.out.println(s);
    }
// ...
```

## 22.4 2D Array & ArrayList
```java
// e.g.
int[][] nums = new int[5][4];
Square[][] board = new Square[2][3]; // stores the references to objects
```
```java
nums = new int[][]; // ILLEGAL
nums = new int[5][]; // OK
nums = new int[5][4]; // OK
```
```java
ArrayList<ArrayList<Integer>> myList = new ArrayList<ArrayList<Integer>>();
```

## 22.5 Bubble Sort
loop: switch the place of two adjacent numbers if the order is wrong
```java
    void bubble_sort_method_1(double[] list)
    {
        int n = list.length;
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = 0; j < n - i - 1; j++)
            {
                if(list[j] > list[j + 1])
                {
                    double temp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = temp;
                }
            }
        }
    }
```
```java
    void bubble_sort_method_2(double[] list)
    {
        boolean changed = true;
        do
        {
            changed = false;
            for(int i = 0; i < list.length -1; i++)
            {
                if(list[i] > list[i+1])
                {
                    double temp = list [i];
                    list[i] = list[i+1];
                    list[i+1] = temp;
                    changed = true;
                }
            }
        }
        while(changed);
    }
```

## 22.6 Comparable
```java
// in order to sort by salary
public class Employee implements Comparable<Employee> 
{
    int empID;
    String eName;
    double salary;
    static int i;
    public Employee() 
    {
        empID = i++;
        eName = "unknown";
        salary = 0.0;
    }
    public Employee(String name, double sal) 
    {
        empID = i++;
        eName = name;
        salary = sal;
    }
    public String toString() 
    {
        return "EmpID = " + empID + "\n" + "Ename = " + eName + "\n" +
        "Salary = " + salary;
    }
    public int compareTo(Employee o1) 
    {
        if (this.salary == o1.salary) return 0;
        else if (this.salary > o1.salary) return 1;
        else return -1;
    }
}
```
```java
import java.util.*;
public class ComparableDemo 
{
    public static void main(String[] args) 
    {
        List<Employee> ts1 = new ArrayList<Employee>();
        ts1.add(new Employee("Tom", 40000.00));
        ts1.add(new Employee("Harry", 20000.00));
        ts1.add(new Employee("Maggie", 50000.00));
        ts1.add(new Employee("Chris", 70000.00));
        Collections.sort(ts1);
        Iterator <Employee> itr = ts1.iterator();
        while(itr.hasNext()) 
        {
            Object element = itr.next();
            System.out.println(element + "\n");
        }
    }
}

// EmpID = 1
// Ename = Harry
// Salary = 20000.0

// EmpID = 0
// Ename = Tom
// Salary = 40000.0

// EmpID = 2
// Ename = Maggie
// Salary = 50000.0

// EmpID = 3
// Ename = Chris
// Salary = 70000.0
```
```java
// if sort by name:
// Employee.java:
public int compareTo(Employee o1) 
{
    if (this.eName.equals(o1.eName)) return 0;
    else if (this.eName.compareTo(o1.eName) > 0) return 1;
    else return -1;
}

// EmpID = 3
// Ename = Chris
// Salary = 70000.0

// EmpID = 1
// Ename = Harry
// Salary = 20000.0

// EmpID = 2
// Ename = Maggie
// Salary = 50000.0

// EmpID = 0
// Ename = Tom
// Salary = 40000.0
```






--------------------------------------------------
--------------------------------------------------
