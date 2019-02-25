![alt text](http://programmingdays.com/img/62c218d0-fda7-4dd2-b49f-8628130c4c8f.png "programmingDays")

# C++ code kata: Week #4

Hello &#x1F44B;

The wave (known as a **[Mexican wave](https://en.wikipedia.org/wiki/Wave_(audience))** in the English-speaking world outside North America) is an example of metachronal rhythm achieved in a packed stadium when successive groups of spectators briefly stand, yell, and raise their arms. Immediately upon stretching to full height, the spectator returns to the usual seated position. 

![alt text](https://upload.wikimedia.org/wikipedia/commons/4/46/Big_Day_Out_%288392285402%29.jpg "Mexican Wave")

Fig. 1 People performing Mexican Wave on the big day out, 2013 in Sydney, Australia

# Ground Exercise

In today's exercise &#x1F3C3; you have to write a function `mexican_wave()` that will take a **single word string** as an argument and returns an array of strings, where each individual string is one wave. 

The example below shows how we use  `mexican_wave`. e.g. &#x1F447;

```C++
auto wave = mexican_wave("abcde")
# wave will contain
# {"Abcde", "aBcde", "abCde", "abcDe", "abcdE"}
```

# Surface #1

If you have completed **Ground Exercise**, then for **Surface # 1**  exercise your `mexican_wave` should accept whitespace characters also i.e. it should work with multi-word arguments. e.g. &#x1F447;

```C++
auto wave = mexican_wave("abcde fg")
# wave will contain
# {"Abcde fg", "aBcde fg", "abCde fg", "abcDe fg", "abcdE fg", "abcde Fg", "abcde fG"}
```

#  Rules &#x1F4DC;
1. All the characters should be lowercase only.
2. You have to return a sequential container.  e.g. array or vector.
3. You cannot use any library other than the C/ C++ standard library.

# Tools &#x1F6E0;

To write solutions you can download tools from:

| Tool | Usage | Download Location |
|:-----|:-----:|:-----------------:|
|Visual Studio Code |Lightweight program editor. |[Download](https://code.visualstudio.com/download)|
|GCC (Linux)|C / C++ Compiler.|[Download](https://gcc.gnu.org/)|
|MingGW (Windows)| C / C++ Compiler.|[Download](http://www.mingw.org/)|
|XCode toolkit (MacOS)| IDE with multi language support.|[Download](https://developer.apple.com/xcode/)|
|Catch2|C++ Test framework|[Download](https://github.com/catchorg/Catch2)| 

# Test Script &#x1F489;
Test Script for this week's problem can be downloaded from **[here](https://1drv.ms/u/s!An6FDnpXbnZ80kn5g1XGO_rWprbl)**.

# Sensei Says &#x1F94B;
**_"What you learn is not what you read or listened to, but rather what you attempted at..."_**

**[Progressive learning](https://en.wikipedia.org/wiki/Progressive_education)** 


If you feel the exercise a little bit difficult to solve do not get disheartened. The whole idea behind these programming exercises is not to solve them but rather attempt them.

Try to attempt them in as many ways as possible, you will learn new techniques that will be very helpful to you in the long run especially in the work field.

We will present you with **solution mail/document** also. The solution will show you various ways to solve a problem and why a technique is better than the last one. 

We encourage you to make notes from the solution provided and try to apply what you have learnt in the future exercise.

**What I will gain from these exercises ?**
1. A better and faster way to solve the exercise.
1. Reusable components like containers, algorithms etc. that you can apply to the problem at hand rather than designing your own.
1. Confidence and attitude to solve a problem in new ways, instead of trying monotonous techniques.
1. Writing the robust and quality software using **[test driven development](https://en.wikipedia.org/wiki/Test-driven_development)**.
 

### All the best &#x1F91E;


##### _In case you have any difficulty using the tools or some questions related to this exercise. Reach us at_
#####  1. &#x1F4AC; programmingdays (Skype)