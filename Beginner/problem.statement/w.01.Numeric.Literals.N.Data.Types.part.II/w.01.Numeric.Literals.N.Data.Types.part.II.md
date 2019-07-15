![alt text](http://programmingdays.com/img/62c218d0-fda7-4dd2-b49f-8628130c4c8f.png "programmingDays")



# C++ code kata: Week 3
# **`Arithmetic operaotrs and expressions`** 
[![Solutions](https://img.shields.io/badge/Language-C++17-informational.svg)](https://shields.io/)  [![Solutions](https://img.shields.io/badge/Compiler-G++7-important.svg)](https://shields.io/) [![Solutions](https://img.shields.io/badge/Track-Beginner-yellowgreen.svg)](https://shields.io/)

## Contents

<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [C++ code kata: Week 3](#C-code-kata-Week-3)
- [**`Arithmetic operaotrs and expressions`**](#Arithmetic-operaotrs-and-expressions)
  - [Contents](#Contents)
  - [Kata this week](#Kata-this-week)
    - [Arithmetic operators in C++](#Arithmetic-operators-in-C)
    - [Other mathematical recepies in C++](#Other-mathematical-recepies-in-C)
    - [Numeric types in C++](#Numeric-types-in-C)
  - [Ground Statement](#Ground-Statement)
    - [Statement 1](#Statement-1)
  - [Hints and Study Materials to solve the Katas](#Hints-and-Study-Materials-to-solve-the-Katas)
  - [- How to write a variable in C++](#How-to-write-a-variable-in-C)
  - [## Tools](#Tools)
  - [I need Help 🆘](#I-need-Help-%F0%9F%86%98)

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

### Other mathematical recepies in C++

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


### Numeric types in C++

[Typed](https://www.fluentcpp.com/2017/03/31/how-typed-cpp-is-and-why-it-matters/) language like C++ has concept of datatype. Datatype helps in allocating bytes of memory so that values can be stored in them. The **most commonly type** are presented in the table below ( For much detailed description visit [Hints](#Hints-and-Study-Materials-to-solve-the-Katas) section ):-
| Data type  | Memory Usage|
|:-----|:-----:|:-----------------:|
|__int8|1 byte|
|__int16, short, unsigned short|2 bytes|
|float, __int32, int, unsigned int, long, unsigned long|4 bytes.|
|double, __int64, long double, long long|8 bytes.|

## Ground Statement

---

`Ground Statement` are small programming exercises for you to play ⚾️ with:

### Statement 1

**1.** What will be the value of mystery after statement at line 3 :-

```C++
01. __int8 mystery = 1
02. mystery = 1 - 2 * mystery
03. mystery = mystery + 1
```

**2.** Write following mathematical equations as C++ statements:-

$$A = \pi r^2$$ 
$$A = \frac{(b_1 + b_2)h}{2}$$ 
$$A = b(1+\frac{r}{100})^n$$
$$ i = \sqrt{a^2+b^2}$$

**3.** Write following python statements in mathematical notation.
```python
a. dm = m * (sqrt(1 + v / c) / sqrt(1 - v / c) - 1)
b. volume = pi * r * r * h
c. volume = 4 * pi * r ** 3 / 3
d. z = sqrt(x * x + y * y)
```   

**4.** What are the values of the following expressions? In each line, assume that
```python
x = 2.5
y = -1.5
m = 18
n = 4

a. x + n * y - (x + n) * y
b. m // n + m % n
c. 5 * x - n / 5
d. 1 - (1 - (1 - (1 - (1 - n))))
e. sqrt(sqrt(n))  
```


## Hints and Study Materials to solve the Katas

- [Know more about C++ data types](https://docs.microsoft.com/en-us/cpp/cpp/cpp-type-system-modern-cpp?view=vs-2019#fundamental-built-in-types)
- [How to write a variable in C++](https://docs.microsoft.com/en-us/cpp/cpp/cpp-type-system-modern-cpp?view=vs-2019#fundamental-built-in-types)
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
