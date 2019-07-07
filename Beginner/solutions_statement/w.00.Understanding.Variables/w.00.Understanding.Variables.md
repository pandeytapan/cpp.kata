![alt text](http://programmingdays.com/img/62c218d0-fda7-4dd2-b49f-8628130c4c8f.png "programmingDays")

# C++ code kata: Week 1️ part 1 of 3
## **`Undersanding variables and literals`** 
[![Solutions](https://img.shields.io/badge/Language-C++17-informational.svg)](https://shields.io/)  [![Solutions](https://img.shields.io/badge/Compiler-G++7-important.svg)](https://shields.io/) 
[![Solutions](https://img.shields.io/badge/Track-Beginner-yellowgreen.svg)](https://shields.io/)

---

## Contents

<!-- code_chunk_output -->

- [Solutions](#solutions)
  - [01. Age of a Person](#01-age-of-a-person)
    - [Solution 1: Commentry](#solution-1-commentry)
  - [02. Value of absolute zero in celcius](#02-Value-of-absolute-zero-in-celcius)
    - [Solution 2: Commentry](#solution-2-commentry)
  - [03. Value of PI](#03-Value-of-PI)
    - [Solution 3: Commentry](#solution-3-commentry)

<!-- /code_chunk_output -->

---
Hello &#x1F44B;

If you have not attempted 💻, I would request you to try your hand over few solutions, for those of you who have written soem solutions here is solution document &#x1F381; for you.

# Solutions  

## 01. Age of a Person

```CPP
01:     std::cout << "Age of a person: " << 78 << std::endl;
02:     std::cout << "Age of person: " << std::dec << 78 << std::endl;
03:     printf("Age of person: %u\n", 78);
04:     fprintf(stdout, "Age of person: %u\n", 78);
```

### Solution 1: Commentry

In our solutions we have written this statement in four ways let us discuss them one by one:-

line 01

---
We have used [cout](http://www.cplusplus.com/reference/iostream/cout/), which is object of ostream class and is associated with standard output device 🖥.
Since this class is defined in [standard namespace](https://www.learncpp.com/cpp-tutorial/naming-conflicts-and-the-std-namespace/) we have to prefix `std::` before using `cout`.

In first technique *see line 01* we have passed a [string literal](https://en.cppreference.com/w/cpp/language/string_literal) followed by age of person. Since age will always be a numeric value and we are under assumption that it will be integral value we have written age as an [integer literal](https://en.cppreference.com/w/cpp/language/integer_literal). 

Remember integers can be written in **binary, decimal, octal and headecimal number systems** in C/ C++. Age is best expressed in decimal number system that we have used here.

The [<<](https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=vs-2019) used here is known as **insertion operator** is basically an overloaded operator of ostream class to handle various kind of `literals`.  

At last the [std::endl](https://en.cppreference.com/w/cpp/io/manip/endl) is a manipulator that inserts a new line character in the stream.

line 02

---

Same as **line 01**, but the only change here is the [std::dec](https://en.cppreference.com/w/cpp/io/manip/hex), which is a manipulator that modifies the default numeric base for integer I/O. It is useful when you have to represent an integer entity in a particular base.

This is not quite useful here as we are already in same base.

line 03

---

This solution is interesting in sense that some of the new budding C++ programmers don't even consider it a C++ solution. C language is subset of C++ and [printf](http://www.cplusplus.com/reference/cstdio/printf/) is a valid C++ function for C style I/O. It takes a [format string with specifier](http://www.cplusplus.com/reference/cstdio/printf/#parameters) that is required for output conversion. 

Since it is a function, the arguments are passed visibly (unlike Object orientation), and each is separated by a `comma (,)` operator.

Out of all `format specifiers` for integers the `%u` is most appripriate here 😕.

line 04

---

Same as **line 03**, but the only change here is [fprintf](https://en.cppreference.com/w/cpp/io/c/fprintf) again a valid C++ function for C style I/O. It takes an additional argument [stream](http://www.cplusplus.com/reference/cstdio/printf/#parameters) representing the [FILE](http://www.cplusplus.com/reference/cstdio/FILE/) object, basically representing where the output will go.

## 02. Value of absolute zero in celcius

```CPP
01:     std::cout << "Value of absolute zero: " << -273.15F << std::endl;
02:     std::cout << "Value of absolute zero: " << std::fixed << -273.15F << '\n'
03:               << "Value of absolute zero: " << std::scientific << -273.15F << '\n'
04:               << "Value of absolute zero: " << std::hexfloat << -273.15F << '\n'
05:               << "Value of absolute zero: " << std::defaultfloat << -273.15F << '\n';
06:     printf("Value of absolute zero: %f\n", -273.15F);
07:     printf("Value of absolute zero: %e\n", -273.15F);
08:     printf("Value of absolute zero: %g\n", -273.15F);

```

### Solution 2: Commentry

In our solutions we have written this statement in four ways let us discuss them one by one:-

line 01

---
Value of absolute zero in celcius is a [fractional number](http://www.montereyinstitute.org/courses/DevelopmentalMath/COURSE_TEXT_RESOURCE/U03_L1_T1_text_final.html), that can be best represented as a [floating point number](https://floating-point-gui.de/formats/fp/).

Floating point notation is how fractional numbers are represented in computer 💻. More about it you can read [here](https://floating-point-gui.de/formats/fp/#how-floating-point-numbers-work).

Now we have written value for absolute zero as `-273.15F`. Apart from integers, floating point values are second type of literals used in computer programming. You must be wondering why is that `F` suffixed to value.

It is basically to round off the value to single precision. We will discuss more on this when we are discussing the datatype, variables and memory.

line 02 to 05

---

Same as **line 01**, but the only change here is the [std::fixed and three more manipulators](https://en.cppreference.com/w/cpp/io/manip/hex), prefixed and they modify the default formatting for floating-point input/output. It is useful when you have to represent an integer entity in a particular base.

This is not quite useful here but we can put these to use when dealing with irrational numbers like value of mathematical constant likePi.

line 06 to 08

---

Here we have used [printf](http://www.cplusplus.com/reference/cstdio/printf/) and have provided various `format specifier` controlling the value conversion for output stream. Lets see when we need them

- %f is used to display decimal point in lowercase.
- %e is used for scientific notation (mantissa/exponent), lowercase.
- %g will choose either of former two whichever is appropriate.

## 03. Value of PI

```CPP
01:     std::cout << M_PI;
```

### Solution 3: Commentry

Let us discuss our solution:-

line 01

---
We may be thinking to do some mathematical computation like dividing 22 by 7 times or taking value as `3.14`, but both of these approaches are wrong since they depend upon the person writing the code and if some one else makes use of it that person has to make sure that value of PI is correct.

Instead of this the best way is to ask language itself for the value of Pi. To do that you have to define constant `_USE_MATH_DEFINES` and include `cmath` header. `cmath` defines Pi as `M_PI` that we have used in our solution.


>Hope you have liked the solutions and must have learnt some thing. Rest of the answers will be available to you in part 2 and 3 of this answer sheet.

>If you still have questions fell fee to connect. We will be happy to answer your questions.

</br></br></br>
[![Get in touch on Messenger](https://img.shields.io/static/v1.svg?label=Ask&nbsp;a&nbsp;Question&message=❓&logo=messenger&style=social)](https://m.me/programmingdays) 

[![Send me a message on WhatsApp](https://img.shields.io/static/v1.svg?label=Ask&nbsp;a&nbsp;Question&message=❓&color=1ebea5&logo=whatsapp&logoColor=white&labelColor=1ebea5)](https://wa.me/919458176671?text=I%20have%20a%20question.) 

---
</br></br>
![Copyright](https://img.shields.io/static/v1.svg?label=C&nbsp;codekata%20©️%20&message=%202019%20programmingDays&labelColor=informational&color=033450) 


