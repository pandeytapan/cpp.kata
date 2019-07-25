![alt text](http://programmingdays.com/img/62c218d0-fda7-4dd2-b49f-8628130c4c8f.png "programmingDays")

# C++ code kata: Week 3

# **`Arithmetic operators and expressions`**

[![Solutions](https://img.shields.io/badge/Language-C++17-informational.svg)](https://shields.io/)  [![Solutions](https://img.shields.io/badge/Compiler-G++7-important.svg)](https://shields.io/) [![Solutions](https://img.shields.io/badge/Track-Beginner-yellowgreen.svg)](https://shields.io/)

## Contents

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [C++ code kata: Week 3](#c-code-kata-week-3)
- [**`Arithmetic operators and expressions`**](#arithmetic-operators-and-expressions)
  - [Contents](#contents)
  - [Kata this week](#kata-this-week)
    - [Arithmetic operators in C++](#arithmetic-operators-in-c)
    - [Other mathematical recipes in C++](#other-mathematical-recipes-in-c)
  - [Ground Statement](#ground-statement)
    - [Statement 1](#statement-1)
    - [Statement 2](#statement-2)
    - [Statement 3](#statement-3)
    - [Statement 4](#statement-4)
    - [Statement 5](#statement-5)
    - [Statement 6](#statement-6)
    - [Statement 7](#statement-7)
    - [Statement 8](#statement-8)
    - [Statement 9](#statement-9)
  - [Hints and Study Materials to solve the Katas](#hints-and-study-materials-to-solve-the-katas)
  - [Tools](#tools)
  - [I need Help 🆘](#i-need-help)

<!-- /code_chunk_output -->

Hello &#x1F44B;

Nice to see you again 😀. This week we are going to practice more of arithmetic elements provided by C++ in our code kata 👇

## Kata this week

This week we are going to practice with various arithmetic operators and expressions in C++. We will try to understand how much memory storage a numeric literal requires and what various `datatypes` C++ provides to store them.  

### Arithmetic operators in C++

C++ defines following arithmetic operators:-
| Operator  | Usage | Example| Return Value |
|:-----:|:-----|-----------------:|-:|
|+|Represent a positive numerical value. | +2|2|
| |Adds two numerical values.|5 + 2, 12.4 + 45.89|7, 58.29|
|-|Represent a negative numerical value. | -89| -89|
| |Subtract two numerical values.|13 - 5, 62.4 - 1.56|8, 60.84|
|*|Multiplies two numerical values|45 * 23|1035|
|/|Division between two numerical values (When both are integers)| 5 / 2|2|
|/|Division between two numerical values (When either is integer)| 5.0 / 2|2.5|
|%|Reminder of a floor divison| 5 % 2|1|

**Output of arithmetic operators is always a numerical value.**

### Other mathematical recipes in C++

Many other mathematical operations like calculating power or square root are not built into language but are available as functions in header `cmath` or header file `math.h`. 

Some of the functions are:-

| function  | Usage |
|:-----|:-----|
|pow (x, y)|Returns x raised to the power y.|
|sqrt (x)|Returns square root of x.|
|sin (x)|Sine of x. (x is in radians)|
|cos (x)|cosine of x. (x is in radians)|
|tan (x)|tangent of x. (x is in radians)|
|abs (x)|absolute value \| x \| |

## Ground Statement

---

`Ground Statement` are small programming exercises for you to play ⚾️ with:

### Statement 1

What will be the value of mystery after statement at line 3:-

```C++
01. __int8 mystery = 1;
02. mystery = 1 - 2 * mystery;
03. mystery = mystery + 1;
```

### Statement 2

Write following mathematical equations as C++ statements:-

$$A = \pi r^2$$
$$A = \frac{(b_1 + b_2)h}{2}$$
$$A = b(1+\frac{r}{100})^n$$
$$ i = \sqrt{a^2+b^2}$$

### Statement 3

Write following C++ statements in mathematical notation.

```cpp
a. m = m * (sqrt(1 + v / c) / sqrt(1 - v / c) - 1);
b. volume = pi * r * r * h;
c. volume = 4 * pi * r ** 3 / 3;
d. z = sqrt(x * x + y * y);
```

### Statement 4

What are the values of the following expressions? In each line, assume that

```c++
double x = 2.5;
double y = -1.5;
int m = 18;
int n = 4;

a. x + n * y - (x + n) * y;
b. m / n + m % n;
c. 5 * x - n / 5;
d. 1 - (1 - (1 - (1 - (1 - n))));
e. sqrt(sqrt(n));  
```

### Statement 5

What are the values of the following expressions? In each line, assume that

```c++
double x = 2.5;
double y = -1.5;
int m = 18;
int n = 4;

a. x + n * y - (x + n) * y;
b. m / n + m % n;
c. 5 * x - n / 5;
d. 1 - (1 - (1 - (1 - (1 - n))));
e. sqrt(sqrt(n));  
```

### Statement 6

What are the type specifier (data type) and value of the variables in the following programs?

a. The value of x, y and z, and their type?

```c++
01: #include <iostream>
02: #include <climits>
03:
04: int main (int argc, char * argv[])
05: {
06:     auto x = INT_MAX ;
07:     auto y = INT_MAX ;
08:     auto z = unsigned long(x) + y;
09:     return EXIT_SUCCESS;
10: }
```

b. For the variables `price` and `dollars` you have to tell:-

- the value stored in `price` and `dollars`.
- Storage class i.e. type specifier for `price` and `dollars`.
- How many bytes of memory is required to store them?

```c++
01: #include <iostream>
02:
03: int main (int argc, char * argv[])
04: {
05:     auto price = 2.55F;
06:     auto dollars = int(price + 0.5);
07:
08:     std::cout << sizeof(price) << std::endl;
09:     std::cout << sizeof(dollars) << std::endl;
10:
11:     return EXIT_SUCCESS;
12: }
```

### Statement 7

Modify this program to print correct value for the following expressions:-

```c++
1: #include <iostream>
2:
3: int main (int argc, char * argv[])
4: {
5:     std::cout << 3 * 1'000 * 1'000 *1'000 << std::endl;
6:     std::cout << 3.0 * 1'000 * 1'000 *1'000 << std::endl;
7:
8:     return EXIT_SUCCESS;
9: }
```

### Statement 8

The following pseudocode describes how to extract the rupees and paise from a price given as a ﬂoating-point value. For example, a price 2.95 yields value 2 and 95 for the rupees and paise.
>Assign the price to an integer variable dollars.
>Multiply the difference price - dollars by 100 and add 0.5.
>Assign the result to an integer variable cents.
Translate this pseudocode into a C++ program.
>Provide a price and print the rupees and paise.
>Test your program with inputs 2.95 and 4.35

### Statement 9

According to the Coulomb force law, the electric force between two charged particles of charge Q1 and Q2 Coulombs, that are a distance r meters apart, is
$$F = \frac{Q_1 Q_2}{4 \pi \epsilon r^2}{Newtons}$$
where, $\epsilon = 8.854 X 10^{-12}$ Farads/ Meters. Write a program that calculates the force on a pair of charged particles, based on the value of Q1 Coulombs, Q2 Coulombs, and r meters, and then computes and displays the electric force.

## Hints and Study Materials to solve the Katas

- [Discussion on mathematical functions provided by C++](https://en.wikipedia.org/wiki/C_mathematical_functions)
- [Arithmetic operators and type conversion in C++](http://www.informit.com/articles/article.aspx?p=352857&seqNum=4)

---

## Tools

---
To write solutions you can download tools from:

| Tool | Usage | Download Location |
|:-----|:-----:|:-----------------:|
|Visual Studio Code |Lightweight program editor. |[Download](https://code.visualstudio.com/download)|
|GCC (Linux)|C / C++ Compiler.|[Download](https://gcc.gnu.org/)|
|MingGW (Windows)| C / C++ Compiler.|[Download](http://www.mingw.org/)|
|XCode toolkit (MacOS)| IDE with multi language support.|[Download](https://developer.apple.com/xcode/)|
|Visual Studio Community |Complete IDE for software development. |[Download](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&rel=16)|
|Catch2|C++ Test framework|[Download](https://github.com/catchorg/Catch2)| 

---

**Sensai Says**

**_"What you learn is not what you read or listened to, but rather what you attempted at..."_**
**[Progressive learning](https://en.wikipedia.org/wiki/Progressive_education)**

If you feel the exercise a little bit difficult to solve do not get disheartened. The whole idea behind these programming exercises is not to solve them but rather attempt them.

Try to attempt them in as many ways as possible, you will learn new techniques that will be very helpful to you in the long run especially in the work field.

We will present you with **solution mail/document** also. The solution will show you various ways to solve a problem and why a technique is better than the last one.

We encourage you to make notes from the solution provided and try to apply what you have learned in future exercise.

**What I will gain from these exercises ?**

1. A better and faster way to solve exercise.
2. Reusable components like containers, algorithms, etc. that you can apply to the problem at hand rather than designing your own.
3. Confidence and attitude to solve a problem in new ways, instead of trying monotonous techniques.
4. Writing the robust and quality software using **[test driven development](https://en.wikipedia.org/wiki/Test-driven_development)**.

## I need Help 🆘

Still, have some questions related to this exercise. If you still have questions feel free to connect. We will be happy to answer your questions.

[![Get in touch on Messenger](https://img.shields.io/static/v1.svg?label=Ask&nbsp;a&nbsp;Question&message=❓&logo=messenger&style=social)](https://m.me/programmingdays) [![Send me a message on WhatsApp](https://img.shields.io/static/v1.svg?label=Ask&nbsp;a&nbsp;Question&message=❓&color=1ebea5&logo=whatsapp&logoColor=white&labelColor=1ebea5)](https://wa.me/919458176671?text=I%20have%20a%20question.)

---

![Copyright](https://img.shields.io/static/v1.svg?label=C&nbsp;codekata%20©️%20&message=%202019%20programmingDays&labelColor=informational&color=033450)
