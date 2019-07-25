![alt text](http://programmingdays.com/img/62c218d0-fda7-4dd2-b49f-8628130c4c8f.png "programmingDays")

# C++ code kata: Week 3 solutions
# **`Arithmetic operators and expressions`**

[![Solutions](https://img.shields.io/badge/Language-C++17-informational.svg)](https://shields.io/)  [![Solutions](https://img.shields.io/badge/Compiler-G++7-important.svg)](https://shields.io/) [![Solutions](https://img.shields.io/badge/Track-Beginner-yellowgreen.svg)](https://shields.io/)

## Contents

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->
<!-- code_chunk_output -->

- [C++ code kata: Week 3 solutions](#c-code-kata-week-3-solutions)
- [**`Arithmetic operators and expressions`**](#arithmetic-operators-and-expressions)
  - [Contents](#contents)
- [Solutions](#solutions)
  - [01. Statement 01: Value of variable mystery](#01-statement-01-value-of-variable-mystery)
    - [Solution 1: Commentry](#solution-1-commentry)
  - [02. Statement 02: mathematical notation to C++ statements](#02-statement-02-mathematical-notation-to-c-statements)
    - [Solution 2: Commentry](#solution-2-commentry)
  - [03. Statement 03: C++ to mathematical notation](#03-statement-03-c-to-mathematical-notation)
    - [Solution 3: Commentry](#solution-3-commentry)
  - [04. Statement 04: Value of C++ expressions](#04-statement-04-value-of-c-expressions)
    - [Solution 4.a: Commentry](#solution-4a-commentry)
  - [Footnotes](#footnotes)

<!-- /code_chunk_output -->

Hello &#x1F44B;

If you have not attempted 💻, I would request you to try your hand over a few solutions, for those of you who have written some solutions here is solution document &#x1F381; for you

# Solutions  

## 01. Statement 01: Value of variable mystery

The solution is written below. The reason to attempt this exercise is to get an understanding about temporary variables and how to use assertions. Here is the solution 👇

```cpp
01: #include <iostream>
02: #include <cassert>
03: int main (int argc, char * argv[])
04: {
05:     __int8 mystery = 1;
06:     mystery = 1 - 2 * mystery;
07:     mystery = mystery + 1;
08:     assert(mystery == 0);
09:
10:     return EXIT_SUCCESS;
11: }
```

### Solution 1: Commentry

There are two things that can be learnt here.

- ### Solution 1.A:Temporary placeholder variable

`Temporary placeholder variables`[^1] are automatically created[^2] by C++
whenever an expression (arithmetic, boolean or comparison to name a few) is computed. Though for language builtin datatypes e.g. int, float, or double etc., CPU registers can be used directly but they should one should try to minimize their creation by rewriting the expression.

>Because they have no name, there’s no way to refer to them beyond the point where they are created. Consequently, they have **expression scope**, meaning they are created, evaluated, and destroyed all within a single expression

In our example code we have 2 temporary placeholder variables at:-

```cpp
06:     mystery = 1 - 2 * mystery;
```

Let us how and when they are created:-
The expression above first solves the multiplication and creates a single temporary placeholder variable to holds value for next part of expression. Internally it becomes 👇

```cpp
06:     mystery = 1 - Temp_1;
```

where `Temp_1` holds return value of 2 * `mystery`

Similarly, the result of subtraction will be hold in a temporary before being assigned to *l-value* i.e. `mystery`

```cpp
06:     mystery = Temp_2;
```

Do you think that one more temporary will be created here 👇?

```cpp
07:     mystery = mystery + 1;
```

Temporary variables are inevitable and can't be removed altogether, but yes we can reduce them by rewriting the expression. The whole code could be rewritten as 👇:-

```cpp
1: #include <iostream>
2: #include <cassert>
3: int main (int argc, char * argv[])
4: {
5:     __int8 mystery = 1;
6:     mystery = 2 * (1- mystery);
7:     assert(mystery == 0);
8:     return EXIT_SUCCESS;
9: }
```

- ### Solution 1.B: Assertion check

Many newbie programmers use `printf()` or `cout` as a measure of test for checking the value stored at a memory locatoin i.e. variable. When we are quite sure about the value of a variable the best way to test our assumption at runtime is using the C++ `assert()`[^3] function.

`assert()` validates the expression to be true and continues further execution of the program. If expression fails then an error message is flashed and program execution is stopped. We have used `assert()` at *line 07* to confirm that our expression results 0 👇:-

```c++
7:     assert(mystery == 0);
```

In case the expression fails i.e. `mystery` is not 0 then it will result following output in console and program will stop

```con
Assertion failed: mystery == 1, file 010.cpp, line 7
```

Voila! ✨ We learnt about temporary variables and using `assert()` to test our programs.

## 02. Statement 02: mathematical notation to C++ statements

The solution is written below. The reason to attempt this exercise is to get an understanding what C++ library functions and mathematical operators are required to write a methematical expression. Let us see them one by one 👇:-

### Solution 2: Commentry

- ### Solution 2.a: Expression #1

$$A = \pi r^2$$

```cpp
1: #include <cstdlib>
2: #include <cmath>
3:
4: int main (int argc, char * argv[])
5: {
6:     float_t r = 12.4f;
7:     double_t a = M_PI * pow(r, 2);
8:     return EXIT_SUCCESS;
9: }
```

We have used `M_PI`[^5] and `pow()`[^6] to convert from mathematical expression to C++ expression. These are basically part of mathematical library written as part of C++ standard library. To use this library at least we need is to include `<cmath>`[^7]

- ### Solution 2.b: Expression #2

$$A = \frac{(b_1 + b_2)h}{2}$$

```cpp
01: #include <cstdlib>
02: #include <cmath>
03:
04: int main (int argc, char * argv[])
05: {
06:     float_t b1 = 1.4f;
07:     float_t b2 = 11.34f;
08:     float_t h = 56.f;
09:     double_t a = (b1 + b2) * h / 2;
10:     return EXIT_SUCCESS;
11: }
```

There is no special function or constant has been used here but regular C++ mathematical operators to achieve the result. Only thing we can discuss here is `float_t`[^8]. Recall, using suffix `f` with a floating point value considers it as single precision instead of double precision.

- ### Solution 2.c: Expression #3

$$A = b(1+\frac{r}{100})^n$$

```cpp
01: #include <cstdlib>
02: #include <cmath>
03:
04: int main (int argc, char * argv[])
05: {
06:     float_t b = 231.4f;
07:     float_t r = 3.34f;
08:     float_t n = 2.1f;
09:     double_t a = b * pow(1 + r / 100, n);
10:     return EXIT_SUCCESS;
11: }
```

If you have followed last examples, this solution is quite easy to understand.

- ### Solution 2.d: Expression #4

$$ i = \sqrt{a^2+b^2}$$

```cpp
01: #include <cstdlib>
02: #include <cmath>
03:
04: int main (int argc, char * argv[])
05: {
06:     int a = 65.34f;
07:     int b = 56.61f;
08:     double_t i  = sqrt(a * a + b * b);
09:
10:     return EXIT_SUCCESS;
11: }
```

This solution is again an easy one to understand. There is one thing though that we can discuss here. See these two lines:-

```c++
06:     int a = 65.34f;
07:     int b = 56.61f;
```

Well this won't give any error and the floating point values will be downcasted to integers with integer part getting assigned to *`lvalues`* i.e. if we check for values of `a` and `b` we get followng in console:-

```con
a = 65
b = 56
```

If you have followed last examples, this solution is quite easy to understand.

## 03. Statement 03: C++ to mathematical notation

The solution is written below. The reason to attempt this exercise is to get an understanding how C++ expressions are written in reverse notation. Here is the solution 👇

### Solution 3: Commentry

The only thing to care of is placement of parenthesis (*if they are even required or not*), position of operators. Let's see each expression one by one:-

- ### Solution 3.b: Expression #1

```cpp
01. m = m * (sqrt(1 + v / c) / sqrt(1 - v / c) - 1);
```

$$ m= m(\frac{\sqrt\frac{1 + v}{c}}{\sqrt\frac{1 + v}{c}} - 1)$$

- ### Solution 3.b: Expression #2

```cpp
01. volume = pi * r * r * h;
```

$$ volume = \pi r^2 h$$

- ### Solution 3.c: Expression #3

```cpp
01. volume = 4 * pi * r ** 3 / 3;
```

$$ volume = \frac{4 \pi r^3}{3}$$

- ### Solution 3.d: Expression #d

```cpp
01. volume = 4 * pi * r ** 3 / 3;
```

$$ volume = \sqrt{x^2 y^2}$$

Voila! ✨ We learnt about temporary variables and using `assert()` to test our programs.

## 04. Statement 04: Value of C++ expressions

The solution is written below. The reason to attempt this exercise is to get an understanding how C++ expressions make use of temporary variables. Here is the solution 👇

### Solution 4.a: Commentry

Let us see how the expression will be solved with details of operators precedence and temporary variables created

For all of the solutions below refer to the following table discussing precedence and associativity.

|  Precedence  | Associativity |             Operator             |
| ------------ | ------------- | -------------------------------- |
| 1. (Highest) | ()            | Bracket                          |
| 2.           | / , * ,  %    | Divison, Multiplication, Modulus |
| 3. (Lowest)  | +, -          | Addition, Subtraction            |

- ### Solution 4.a: Expression #1

```cpp
01: #include <cstdlib>
02:
03: int main (int argc, char * argv[])
04: {
05:     double x = 2.5;
06:     double y = -1.5;
07:     int n = 4;
08:
09:     x + n * y - (x + n) * y;
10:
11:     return EXIT_SUCCESS;
12: }
```

The expression will get solved as follows:-

|        expression         |         temporary         |
| ------------------------- | ------------------------- |
| x + n \* y - (x + n) \* y |                           |
| x + n * y - *temp1* * y   | temp1 (6.5)               |
| x + *temp2* - *temp1* * y | temp1 (6.5), temp2(-6)    |
| x + *temp2* - *temp3*     | temp3 (9.75), temp2(-6)   |
| *temp4* - *temp3*         | temp3 (9.75), temp4(-3.5) |
| 6.25                      |                           |

- ### Solution 4.b: Expression #2

```cpp
01: #include <cstdlib>
02:
03: int main (int argc, char * argv[])
04: {
05:     int m = 18;
06:     int n = 4;
07:
08:     m / n + m % n;
09:
10:     return EXIT_SUCCESS;
11: }
```

The expression will get solved as follows:-

|    expression     |      temporary      |
| ----------------- | ------------------- |
| m / n + m % n     |                     |
| *temp1* + m % n   | temp1 (4)           |
| *temp1* + *temp2* | temp1 (4), temp2(2) |
| 6                 |                     |

- ### Solution 4.c: Expression #3

```cpp
01: #include <cstdlib>
02:
03: int main (int argc, char * argv[])
04: {
05:     double x = 2.5;
06:     int n = 4;
07:
08:     5 * x - n / 5;
09:
10:     return EXIT_SUCCESS;
11: }
```

The expression will get solved as follows:-

|    expression     |          temporary          |
| ----------------- | --------------------------- |
| 5 \* x - n / 5    |                             |
| *temp1* - n / 5   | temp1 (12.500000)           |
| *temp1* - *temp2* | temp1 (12.500000), temp2(0) |
| 12.500000         |                             |

- ### Solution 4.d: Expression #4

```cpp
01: #include <cstdlib>
02:
03: int main (int argc, char * argv[])
04: {
05:     int n = 4;
06:
07:     1 - (1 - (1 - (1 - (1 - n))));
08:
09:     return EXIT_SUCCESS;
10: }

```

The expression will get solved as follows:-

|           expression            | temporary |
| ------------------------------- | --------- |
| 1 - (1 - (1 - (1 - (1 - n))))   |           |
| 1 - (1 - (1 - (1 - \*temp1\*))) | temp1(-3) |
| 1 - (1 - (1 - \*temp2\*))       | temp2(4)  |
| 1 - (1 - \*temp3\*)             | temp3(-3) |
| 1 - \*temp4\*                   | temp4(4)  |
| -3                              |           |

- ### Solution 4.e: Expression #5

```cpp
01: #include <cstdlib>
02: #include <cmath>
03:
04: int main (int argc, char * argv[])
05: {
06:     int n = 4;
07:
08:     sqrt(sqrt(n));  
09:
10:     return EXIT_SUCCESS;
11: }
```

The expression will get solved as follows:-

|   expression    |    temporary    |
| --------------- | --------------- |
| sqrt(sqrt(n))   |                 |
| sqrt(\*temp1\*) | temp1(2.000000) |
| 1.414214        |                 |


## 05. Statement 05: Type specifier (data type) and value of the variables.

The solution is written below. The reason to attempt this exercise is to get an understanding of how `type specifiers`[^9] are deduced for `auto` variables. Here is the solution 👇

### Solution 5: Commentry

The type specifier for the `auto` variable is deduced from the initializer statement at run time. e.g. Consider the following code segment:-

```c++
auto value = 45;
```

If we see the *rvalue* it solves down to an integer expression i.e. 45. Integers are assigned to type specifer *int* when assignment is done. based on the fact lets see how it will work for our program:-

```c++
01: #include <iostream>
02: #include <climits>
03:
04: int main (int argc, char * argv[])
05: {
06:     auto x = INT_MAX ;
07:     auto y = INT_MAX ;
08:     auto z = unsigned long(x) + y;
09:
10:     std::cout << std::boolalpha << std::is_same<decltype(x),int>::value << std::endl;
11:     std::cout << std::boolalpha << std::is_same<decltype(y),int>::value << std::endl;
12:     std::cout << std::boolalpha << std::is_same<decltype(z),unsigned long>::value << std::endl;
13:
14:     return EXIT_SUCCESS;
15: }
```

There is just a small addition that we have done here, to verify the type identifier we have written 3 statements _see line 10 to 12_. First we have initialized `x` to INT_MAX[^10]. Now, since the *rvalue* is of type integer, this will make `x` as int type. Same applies for variable `y` _see line 07_.

When we add `x` and `y` _see line 08_ the resulting value is negative. Why? Because we exceed the maximum value for integers and thus turning on the sign bit because of value roll over. We can easily tackle this by treating sign bit as value bit by making use of `unsigned` qualifier. We have done this by type-casting `x` and thus making whole expression computed under `unsigned long`. Finally, the type of `z` will be `unsigned long`. The same has been verified below _see line 10 to 12_.

>Hope you have liked the solutions and must have learned something. Rest of the answers will be available to you in part 2 and 3 of this answer sheet.
>If you still have questions feel free to connect. We will be happy to answer your questions.

</br></br></br>
[![Get in touch on Messenger](https://img.shields.io/static/v1.svg?label=Ask&nbsp;a&nbsp;Question&message=❓&logo=messenger&style=social)](https://m.me/programmingdays)

[![Send me a message on WhatsApp](https://img.shields.io/static/v1.svg?label=Ask&nbsp;a&nbsp;Question&message=❓&color=1ebea5&logo=whatsapp&logoColor=white&labelColor=1ebea5)](https://wa.me/919458176671?text=I%20have%20a%20question.)

</br>

![Copyright](https://img.shields.io/static/v1.svg?label=C&nbsp;codekata%20©️%20&message=%202019%20programmingDays&labelColor=informational&color=033450)

## Footnotes

[^1]: [Temporary place holder objects](https://www.learncpp.com/cpp-tutorial/814-anonymous-objects/comment-page-1/)
[^2]: [Value categories in C++.](https://en.cppreference.com/w/cpp/language/value_category)
[^3]: [Checking if type T is equals to U or not.](https://en.cppreference.com/w/cpp/types/is_same)
[^4]: [Using assert() and static_assert()](https://www.learncpp.com/cpp-tutorial/7-12a-assert-and-static_assert/)
[^5]: [Using predefined mathematical constants like PI](https://docs.microsoft.com/en-us/cpp/c-runtime-library/math-constants?view=vs-2019)
[^6]: [Raising a *base* to given power](http://www.cplusplus.com/reference/cmath/pow/)
[^7]: [C++ mathematical library functions and constants](http://www.cplusplus.com/reference/cmath/)
[^8]: [What is float_t or double_t](https://stackoverflow.com/a/5390090/2633215)
[^9]: [Deducing the type specifier for auto variables](https://www.ibm.com/support/knowledgecenter/en/ssw_ibm_i_73/rzarg/auto_type_deduction.htm)
[^10]: [Maximum value for integer type in C++](http://www.cplusplus.com/reference/climits/)
