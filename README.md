# NOI-ACM-ICPC
算法竞赛 入门经典(第二版) 例题-注解-习题

## Table of Contents

- [第二章 循环结构程序设计](#第二章-循环结构程序设计)
- [第三章 数组和字符串](#第三章-数组和字符串)
- [第四章 函数和递归](#第四章-函数和递归)
- [第五章 C++ 与 STL入门](#第五章-C++-与-STL入门)
- [第六章 数据结构基础](#第六章-数据结构基础)
- [第七章 暴力求解法](#第七章-暴力求解法)
- [第八章 高效算法设计](#第八章-高效算法设计)
- [第九章 动态规划初步](#第九章-动态规划初步)
- [第十章 数学概念与方法](#第十章-数学概念与方法)
- [第十一章 图论模型与算法](#第十一章-图论模型与算法)

---
## 第二章 循环结构程序设计

### 2.4 算法竞赛中的输入输出框架
使用文件最简单的方法是使用输入输出重定向， 只需在main函数的入口处加入以下两条语句：
```C
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```
上述语句使得scanf从文件input txt读入， printf写入文件output txt。</br></br>

以下是两种读写文件的基本方法：</br>

```C
#define LOCAL
#include <stdio.h>

#define INF 1000000000

int main()
{

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    int x, n = 0, min = INF, max = -INF, s = 0;
    while (scanf("%d", &x))
    {
        s += x;
        if (x < min) min = x;
        if (x > max) max = x;

        n++;
    }

    printf("%d %d %.3f\n", min, max, (double)s/n);
    return 0;
}
```

<p align="center"><em>程序2-10 数据统计（重定向版）</em></p></br></br>

```C
#include <stdio.h>

#define INF 1000000000

int main()
{
    FILE *fin = fopen("data.in", "rb");
    FILE *fout = fopen("data.out", "wb");

    int x, n = 0, min = INF, max = -INF, s = 0;
    while (fscanf(fin, "%d", &x))
    {
        s += x;
        if (x < min) min = x;
        if (x > max) max = x;

        n++;
    }

    fprintf(fout, "%d %d %.3f\n", min, max, (double)s/n);
    fclose(fin);
    fclose(fout);
    return 0;
}
```
<p align="center"><em>程序2-11 数据统计（fopen版）</em></p>

程序2-10中， 重定向的部分被写在了`#ifdef`和`#endif`中。其含义是：只有定义了符号`LOCAL`才编译两条`freopen`语句，否则仍为读写输入输出。</br>
重定向和`fopen`两种方法各有优劣。重定向的方法写起来简单、自然，但是不能同时读写文件和标准输入输出（因为IO已被重定向至文件）。`fopen`的写法稍显繁琐，但是灵活性较大。另外，如果想把`fopen`版本的程序改成读写标准输入输出，只需赋值`fin = stdin; fout = stdout;`即可，无需再调用`fopen`和`fclose`。


> 提示2-27： 当嵌套的两个代码块中有同名变量时， 内层的变量会屏蔽外层变量，有时会引起十分隐蔽的错误。

---
## 第三章 数组和字符串

### 3.1 数组
如果要从数组a复制k个元素（`integer`）到数组b，可以使用`memcpy(b, a, sizeof(int) * k)`。当然， 如果数组a和b都是浮点型的，复制时要写成`memcpy(b, a, sizeof(double) * k)`。另外需要注意的是， 使用`memcpy`函数要包含`string.h`。如果需要把数组a全部复制到数组b中， 可直接写成 `memcpy(b, a, sizeof(a))`。

> 提示3-9： scanf("%s", s) 遇到空白字符会停下来。

---
## 第四章 函数和递归

### 4.1 自定义函数和结构体
> 提示4-8： 对复杂的表达式进行化简有时不仅能减少计算量， 还能减少甚至避免中间结果溢出。
> 提示4-9： 编写函数时， 应尽量保证该函数能对任何合法参数得到正确的结果。 如若不然， 应在显著位置表明函数的缺陷， 以避免误用。

使用四舍五入以避免浮点误差， e.g. `floor(sqrt(n) + 0.5)`.

### 4.2 函数调用与参数传递
> 提示4-11： 函数的形参和在函数内声明的变量都是该函数的局部变量。 无法访问其他函数的局部变量。 局部变量的存储空间是临时分配的， 函数执行完毕时， 局部
变量的空间将被释放， 其中的值无法保留到下次使用。 在函数外声明的变量是全局变量， 可以被函数使用。 操作全局变量有风险， 应谨慎使用。

一般地， 若`p`是指针， `k`是正整数， 则`p+k`就是指针`p`后面第`k`个元素， `p-k`是`p`前面第`k`个元素， 而如果`p1`和`p2`是类型相同的指针指针， 则
`p1-p2`是从`p1`到`p2`的元素个数（不含`p2`）。

## 第五章 C++ 与 STL入门
> 提示5-2： `C++`能编译大多数`C`语言程序。 虽然`C`语言中大多数头文件在`C++`中仍然可以使用， 但推荐的方法是在`C`头文件之前加一个小写的`c`， 然后去掉`.h`后缀。

声明数组时， 数组大小可以用`const`声明的常数（这在`C99`中是不允许的）。 在`C++`中， 这种常数的定义方式相对于`#define`而言更加推荐。

### 5.1.2 引用
```C++
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int t = a; a = b; b = t;
}

int main() {
    int a = 3, b = 4;
    swap(a, b);
    cout << a << " " << b << "\n";

    return 0;
}
```

如果在参数名之前加一个`&`符号， 就表示这个参数按照传引用（by reference）的方式传递， 而不是`C`语言中传值（by value）的方式传递。 这样， 在函数内改变
参数的值， 也会修改到函数的实参。

### 5.1.3 字符串

```C++
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        int sum = 0, x;
        stringstream ss(line);
        while (ss >> x) sum += x;
        cout << sum << "\n";
    }

    return 0;
}

```
<p align="center"><em>stringstream 示例</em></p>

虽然`string`和 `sstream`都很方便， 但`string`很慢， `sstream`更慢， 应谨慎使用。

### 5.1.4 结构体
`C++`中可以有一个或者多个构造函数， 在声明变量时调用。 `C++`中的函数参数可以拥有默认值。 在`C++`结构体
的成员函数中， `this`是指向当前对象的指针。

```C++
#include <iostream>
using namespace std;

struct Point {
    int x, y;
    Point(x=0, y=0):x(x), y(y) {}
    // Point(x=0, y=0) {
    //    this->x = x; this->y = y;
    // }
};

Point operator + (const Point& A, const Point& B) {
    return Point(A.x + B.x, A.y + B.y);
}

ostream& operator << (ostream& out, const Point& P) {
    out << "(" << P.x << P.y << ")";
    return out;
}

int main() {
    Point a, b(1, 2);
    a.x = 3;
    cout << a+b << "\n";

    return 0;
}

```
<p align="center"><em>结构体 示例</em></p>

### 5.1.5 模板
```C++
#include <iostream>
using namespace std;

template <typename T>
struct Point {
    T x, y;
    Point(T x=0, T y=0):x(x), y(y) {}
    // Point(T x=0, T y=0) {
    //    this->x = x; this->y = y;
    // }
};

template <typename T>
Point<T> operator + (const Point<T>& A, const Point<T>& B) {
    return Point<T>(A.x + B.x, A.y + B.y);
}

template <typename T>
ostream& operator << (ostream& out, const Point<T>& P) {
    out << "(" << P.x << P.y << ")";
    return out;
}

int main() {
    Point<int> a(1,2), b(3,4);
    Point<double> c(1.1,2.2), d(3.3,4.4);

    cout << a+b << " " << c+d << "\n";

    return 0;
}

```
<p align="center"><em>模板 示例</em></p>

### 5.2 STL初步
