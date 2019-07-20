![alt text](http://programmingdays.com/img/62c218d0-fda7-4dd2-b49f-8628130c4c8f.png "programmingDays")

# C++ code kata: Week 3 solutions
# **`Arithmetic operators and expressions`**

[![Solutions](https://img.shields.io/badge/Language-C++17-informational.svg)](https://shields.io/)  [![Solutions](https://img.shields.io/badge/Compiler-G++7-important.svg)](https://shields.io/) [![Solutions](https://img.shields.io/badge/Track-Beginner-yellowgreen.svg)](https://shields.io/)

## Contents

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->
<!-- code_chunk_output -->

- [Solutions](#solutions)
  - [01. Statement 01: Storing value for 1 billion and 3 billion](#01-statement-01-storing-value-for-1-billion-and-3-billion)
    - [Solution 1: Commentry](#solution-1-commentry)
    - [Solution 1. A: Increase the amount of memory](#solution-1-a-increase-the-amount-of-memory)
    - [Solution 1.B : Change storage specifier](#solution-1b-change-storage-specifier)
  - [02. What's wrong with human age](#02-whats-wrong-with-human-age)
    - [Solution 2: Commentry](#solution-2-commentry)
    - [Solution 2.A: Decrease the amount of memory](#solution-2a-decrease-the-amount-of-memory)
  - [03. How `unsigned` type specifier helped in storing value correctly](#03-how-unsigned-type-specifier-helped-in-storing-value-correctly)
    - [Solution 3: Commentry](#solution-3-commentry)
    - [Solution 3.A : Usage of `auto` type specifier](#solution-3a-usage-of-auto-type-specifier)
  - [04. Correct type specifier for variables](#04-correct-type-specifier-for-variables)
    - [Solution 4: Commentry](#solution-4-commentry)
    - [Solution 4.A : Usage of `double` type specifier](#solution-4a-usage-of-double-type-specifier)

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
