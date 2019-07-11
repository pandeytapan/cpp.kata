![alt text](http://programmingdays.com/img/62c218d0-fda7-4dd2-b49f-8628130c4c8f.png "programmingDays")



# C++ code kata: Week 2
# **`Numeric literals and types`** 
[![Solutions](https://img.shields.io/badge/Language-C++17-informational.svg)](https://shields.io/)  [![Solutions](https://img.shields.io/badge/Compiler-G++7-important.svg)](https://shields.io/) [![Solutions](https://img.shields.io/badge/Track-Beginner-yellowgreen.svg)](https://shields.io/)

## Contents

<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Contents](#contents)
- [Kata this week](#kata-this-week)
  - [Numeric literals in C++](#numeric-literals-in-c)
  - [Numeric types in C++](#numeric-types-in-c)
  - [Assignment operator](#assignment-operator)
- [Ground Statement](#ground-statement)
  - [Statement 1](#statement-1)
  - [Statement 2](#statement-2)
  - [Statement 3](#statement-3)
  - [Statement 4](#statement-4)
- [Hints and Study Materials to solve the Katas](#hints-and-study-materials-to-solve-the-katas)
- [Tools](#tools)
- [I need Help 🆘](#i-need-help)

<!-- /code_chunk_output -->

Hello &#x1F44B;

Great to see you again 👍. This week we are going to practice following elements of C++ in our code kata 👇

## Kata this week

This week we are going to practice with various numeric types in C++. we will try to understand how much memory storage a numeric literal requires and what various `datatypes` C++ provides to store them.  

### Numeric literals in C++

C++ defines the following numeric literals:-
| Number | Type | Comment |
|:-----|:-----:|:-----------------:|
|10 |Integer |Numeric values without fractional part are integers. |
|-10|Integer|Integers can be positive or negative.|
|0.5|Floating Point|Numeric value with the fractional part is floating point. These can be single precision or double precision values.|
|2.96E-2| Floating Point|Floating point values in exponential notation. 2.96 / 100 = 0.0296|
Numeric literals can be written in binary, decimal, hexadecimal and octal notation.

### Numeric types in C++

[Typed](https://www.fluentcpp.com/2017/03/31/how-typed-cpp-is-and-why-it-matters/) language like C++ has concept of datatype. Datatype helps in allocating bytes of memory so that values can be stored in them. The **most commonly type** are presented in the table below ( For much detailed description visit [Hints](#Hints-and-Study-Materials-to-solve-the-Katas) section ):-
| Data type  | Memory Usage|
|:-----|:-----:|:-----------------:|
|__int8|1 byte|
|__int16, short, unsigned short|2 bytes|
|float, __int32, int, unsigned int, long, unsigned long|4 bytes.|
|double, __int64, long double, long long|8 bytes.|

### Assignment operator

The assignment operator is basically part of the assignment statement. Its job is to update the contents of the memory location.

It is written as:-

*memory_location  **=**  expression*;

In the above statement:-

- **memory location** is the unique location where value gets updated. It is mostly referred to using an identifier known as a variable. Also known as **lvalue**, this should be assignable. The important thing here is to choose the amount of memory we want to allocate.

- **expression** is any combination of operators and operands that produces a valid result, such that it can be assigned to **lvalue**. This is also known as **rvalue**. On our case, it will be numeric literals for now.

- **=** is assignment operator whose job is to update `lvalue`. 

> ℹ️ Check links giving you information on what is variable and how to assign value to a variable in `hints` section.

## Ground Statement

---

### Statement 1

Suppose you have an integer variable that stores value for one billion and displays it onto the screen. See below 👇

```C++
1: #include <iostream>
2:
3: int main (int argc, char * argv[])
4: {
5:     int one_billion = 1000000000;
6:     std::cout << "One billion: " << one_billion << std::endl;
7:
8:     return EXIT_SUCCESS;
9: }
```

```C++Con
One billion: 1000000000
```

What will be the output if you change `line 05` like this? Please support your answer with an explanation.

```C++
5:     int three_billion = 3000000000;
```

If we have to store value `3,000,000,000` into memory what size of an integer will be required?

### Statement 2

The [oldest human](https://en.wikipedia.org/wiki/Oldest_people) as per records lived up to the age of 122. Considering that fact, what is the problem with `line 05` in code written below 👇

```C++
1: #include <iostream>
2:
3: int main (int argc, char * argv[])
4: {
5:     int age = 21;
6:     std::cout << age << std::endl;
7:     return EXIT_SUCCESS;
8: }

```

### Statement 3

Revisiting our first problem, someone changed the code like this 👇

```C++

1: #include <iostream>
2:
3: int main (int argc, char * argv[])
4: {
5:     unsigned three_billion = 3000000000;
6:     std::cout << "Three billion: " << three_billion << std::endl;
7:
8:     return EXIT_SUCCESS;
9: }
```

```C++Con
Three billion: 3000000000
```

Why it is coming correct. Try to support your answer with an explanation.


### Statement 4

Area of a circle is can be computed as follows. See below 👇

```C++
01: #define _USE_MATH_DEFINES
02:
03: #include <iostream>
06: #include <cmath>
07:
08: int main (int argc, char *argv[])
09: {
10:     area  = M_PI * radius * radius;
11:     return EXIT_SUCCESS;
12: }
```

What `datatype` you will prefer to store the value of `radius` and `area`?

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
