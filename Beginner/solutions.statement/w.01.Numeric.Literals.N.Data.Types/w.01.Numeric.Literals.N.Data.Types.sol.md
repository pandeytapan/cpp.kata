![alt text](http://programmingdays.com/img/62c218d0-fda7-4dd2-b49f-8628130c4c8f.png "programmingDays")



# C++ code kata: Week 2 solutions
# **`Numeric literals and types`** 
[![Solutions](https://img.shields.io/badge/Language-C++17-informational.svg)](https://shields.io/)  [![Solutions](https://img.shields.io/badge/Compiler-G++7-important.svg)](https://shields.io/) [![Solutions](https://img.shields.io/badge/Track-Beginner-yellowgreen.svg)](https://shields.io/)

## Contents

<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

<!-- /code_chunk_output -->

Hello &#x1F44B;

If you have not attempted 💻, I would request you to try your hand over few solutions, for those of you who have written soem solutions here is solution document &#x1F381; for you

# Solutions  

## 01. Statement 01 :Storing value for 1 billion and 3 billion

```cpp
01: #include <iostream>
02:
03: int main (int argc, char * argv[])
04: {
05:     int one_billion = 1'000'000'000;
06:     std::cout << "One billion: " << one_billion << std::endl;
07:     int three_billion = 3'000'000'000;
08:     std::cout << "Three billion: " << three_billion << std::endl;
09:
10:     return EXIT_SUCCESS;
11: }

```

Console Output

```con
One billion: 1000000000
Three billion: -1294967296
```

### Solution 1: Commentry

In the program above the value for 3 billion is coming incorrect. Let's try to understand this and come up with 2 solutions.

### Solution 1. A : Increase the amount of memory

It seems that value `3'000'000'000` takes more memory than `1'000'000'000`. 
We have stored `1'000'000'000` as `int` i.e. in 4 bytes of memory. 

We can increase this memory storage to 8 bytes by using either `long long` or `__int64`. Let's change it to 8 bytes and see the result.

```cpp
01: #include <iostream>
02:
03: int main (int argc, char * argv[])
04: {
05:     int one_billion = 1'000'000'000;
06:     std::cout << "One billion: " << one_billion << std::endl;
07:     __int64 three_billion = 3'000'000'000;
08:     std::cout << "Three billion: " << three_billion << std::endl;
09:
10:     return EXIT_SUCCESS;
11: }

```

Console Output

```con
One billion: 1000000000
Three billion: 3000000000
```

Voila! ✨ We got correct result. But we have to pay the price. Let's see how by discussing this little code below 👇

```cpp
01: #include <iostream>
02:
03: int main (int argc, char * argv[])
04: {
05:     int one_billion = 1'000'000'000;
06:     __int64 three_billion = 3'000'000'000;
07:  
08:     std::cout << sizeof(one_billion) << std::endl;
09:     std::cout << sizeof(three_billion) << std::endl;
10:     std::cout << sizeof(1'000'000'000) << std::endl;
11:     std::cout << sizeof(3'000'000'000) << std::endl;
12:
13:     return EXIT_SUCCESS;
14: }
```

Console Output

```con
One billion: 1000000000
Three billion: 3000000000
4
8
4
4
```

As evident from the output both `1'000'000'000` and `3'000'000'000` as __integer literals__ need only 4 bytes of memory. So what is problem with the statement:-

```cpp
int three_billion = 3'000'000'000;
```

If `3'000'000'000` can be stored in 4 bytes then why it is failing when we are using `int` dataype.

To understand this let us see memory representation of 1 billion and 3 billion

1 billion as stored in 4 bytes i.e. 32 bits

```bin
MSB                                 LSB
🔽
‭0011 1011 1001 1010 1100 1010 0000 0000‬
```

3 billion as stored in 4 bytes i.e. 32 bits

```bin
MSB
🔽                                 LSB
‭1011 0010 1101 0000 0101 1110 0000 0000‬
```

As you can see that  `Most signinficant bit` [(MSB)](https://en.wikipedia.org/wiki/Bit_numbering#Most_significant_bit) is 1 for 3 billion. This bit in an `int` type is treated as [sign bit](https://en.wikipedia.org/wiki/Sign_bit). When it is 1 the whole value is treated as negative. That is why in our original answer we are getting value for `three_billion` as `-1294967296`.

### Solution 1.B : Change storage specifier

The correct implementation is to treat MSB as value bit. `int` by default differentiates  values as positive and negative on basis of if MSB is 0 or 1. We can change this behaviour by changing [type specifier](https://en.wikipedia.org/wiki/C_syntax#Type_qualifiers).

Let's see what the correct implementation will be:

```C++
01: #include <iostream>
02:
03: int main (int argc, char * argv[])
04: {
05:     int one_billion = 1'000'000'000;
06:     std::cout << "One billion: " << one_billion << std::endl;
07:     unsigned three_billion = 3'000'000'000;
08:     std::cout << "Three billion: " << three_billion << std::endl;
09:
10:     std::cout << sizeof(one_billion) << std::endl;
11:     std::cout << sizeof(three_billion) << std::endl;
12:     std::cout << sizeof(int) << std::endl;
13:     std::cout << sizeof(unsigned) << std::endl;
14:
15:     return EXIT_SUCCESS;
16: }
```

Console Output

```con
One billion: 1000000000
Three billion: 3000000000
4
4
4
4
```

See how in __line 07__ we have used [unsigned](https://www.cs.utah.edu/~germain/PPS/Topics/unsigned_integer.html) type specifier. It basically treats the sign bit as value bit thus adds it to value while giving result back  i.e. `3'000'000'000` ✌️ 😃.

## 02. What's wrong with human age

We have written code like this 👇

```cpp
1: #include <iostream>
2:
3: int main (int argc, char * argv[])
4: {
5:     int age = 21;
6:     std::cout << age << std::endl;
7:     return EXIT_SUCCESS;
8: }
```

Console Output

```con
21
```

### Solution 2: Commentry

Age of a human can never exceed three decimal digits and that also rarely beyond 140 or 150 😮, such a range of value can be stores in 1 byte. Considering this fact, using `int` as storage type specifier isn't good enough as it takes 4 bytes (those who consider memory as a precious resource 💰). Lets see what are the possible solutions 👇

### Solution 2.A : Decrease the amount of memory

WE can decrese the amount of memory required by changing the storage type specifier. Integer storege class comes in following flavours

| Type | Memory Usage |
|:-----|:-----:|
|__int64| 64 bit (8 bytes)|
|__int32| 32 bit (4 bytes)|
|__int16| 16 bit (2 bytes)|
|__int8| 8 bit (1 byte)|

We can decrease the memory storage to 1 byte by using `__int8`. Let's change it and see the result.

```cpp
01: #include <iostream>
02:
03: int main (int argc, char * argv[])
04: {
05:     __int8 age = 21;
06:
07:     std::cout <<  unsigned(age) << std::endl;
08:     std::cout <<  sizeof(age) << std::endl;
09:
10:     return EXIT_SUCCESS;
11: }
```

Console Output

```con
21
1
```

Voila! ✨ We are at correct result. The `age` varialbe is now taking 1 byte of memory instead of 4 bytes as earlier. We have [typecasted](http://www.cplusplus.com/doc/oldtutorial/typecasting/) the value to `unsigned` because `std::cout` treats every 8 bit value as character. Typecasting it to `unsigned` gives back a printable numerical value.

## 02. What's wrong with human age

We have written code like this 👇

```cpp
1: #include <iostream>
2:
3: int main (int argc, char * argv[])
4: {
5:     int age = 21;
6:     std::cout << age << std::endl;
7:     return EXIT_SUCCESS;
8: }
```

Console Output

```con
21
```

### Solution 3: Commentry

Age of a human can never exceed three decimal digits and that also rarely beyond 140 or 150 😮, such a range of value can be stores in 1 byte. Considering this fact, using `int` as storage type specifier isn't good enough as it takes 4 bytes (those who consider memory as a precious resource 💰). Lets see what are the possible solutions 👇

### Solution 3.A : Decrease the amount of memory

WE can decrese the amount of memory required by changing the storage type specifier. Integer storege class comes in following flavours

| Type | Memory Usage |
|:-----|:-----:|
|__int64| 64 bit (8 bytes)|
|__int32| 32 bit (4 bytes)|
|__int16| 16 bit (2 bytes)|
|__int8| 8 bit (1 byte)|

We can decrease the memory storage to 1 byte by using `__int8`. Let's change it and see the result.

```cpp
01: #include <iostream>
02:
03: int main (int argc, char * argv[])
04: {
05:     __int8 age = 21;
06:
07:     std::cout <<  unsigned(age) << std::endl;
08:     std::cout <<  sizeof(age) << std::endl;
09:
10:     return EXIT_SUCCESS;
11: }
```

Console Output

```con
21
1
```

Voila! ✨ We are at correct result. The `age` varialbe is now taking 1 byte of memory instead of 4 bytes as earlier. We have [typecasted](http://www.cplusplus.com/doc/oldtutorial/typecasting/) the value to `unsigned` because `std::cout` treats every 8 bit value as character. Typecasting it to `unsigned` gives back a printable numerical value.

>Hope you have liked the solutions and must have learnt some thing. Rest of the answers will be available to you in part 2 and 3 of this answer sheet.
>If you still have questions fell fee to connect. We will be happy to answer your questions.

</br></br></br>
[![Get in touch on Messenger](https://img.shields.io/static/v1.svg?label=Ask&nbsp;a&nbsp;Question&message=❓&logo=messenger&style=social)](https://m.me/programmingdays) 

[![Send me a message on WhatsApp](https://img.shields.io/static/v1.svg?label=Ask&nbsp;a&nbsp;Question&message=❓&color=1ebea5&logo=whatsapp&logoColor=white&labelColor=1ebea5)](https://wa.me/919458176671?text=I%20have%20a%20question.) 

---
</br></br>
![Copyright](https://img.shields.io/static/v1.svg?label=C&nbsp;codekata%20©️%20&message=%202019%20programmingDays&labelColor=informational&color=033450)
