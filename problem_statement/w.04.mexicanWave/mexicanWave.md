![alt text](http://programmingdays.com/img/62c218d0-fda7-4dd2-b49f-8628130c4c8f.png "programmingDays")

# C++ code kata: Week #4

Hello &#x1F44B;

The wave (known as a **[Mexican wave](https://en.wikipedia.org/wiki/Wave_(audience))** in the English-speaking world outside North America) is an example of metachronal rhythm achieved in a packed stadium when successive groups of spectators briefly stand, yell, and raise their arms. Immediately upon stretching to full height, the spectator returns to the usual seated position. 

![alt text](https://upload.wikimedia.org/wikipedia/commons/4/46/Big_Day_Out_%288392285402%29.jpg "Mexican Wave")

Fig. 1 People performing Mexican Wave on the big day out, 2013 in Sydney, Australia

# Ground Exercise

In today's exercise, you have to write a function `mexican_wave()` that will take a **single word string** as an argument and returns an array of strings, where each individual string is one wave. 

# Ground Exercise Rules
1. You have to pass a single word.
2. All the characters should be lowercase only.
3. You have to return a sequential container.  e.g. array or vector.
4. You cannot use any library other than the C/ C++ standard library.

The example below shows how we use the `mexican wave`. e.g. &#x1F447;

```C++
auto wave = mexican_wave("abcde")
# wave will contain
# {"Abcde", "aBcde", "abCde", "abcDe", "abcdE"}
```

# Surface #1

If you have completed **Ground Statement**, then for **surface # 1**  exercise your `mexican_wave` should accept whitespace characters also i.e. it should work with multi-word arguments. e.g. &#x1F447;

```C++
auto wave = mexican_wave("abcde fg")
# wave will contain
# {"Abcde fg", "aBcde fg", "abCde fg", "abcDe fg", "abcdE fg", "abcde Fg", "abcde fG"}
```

# Tools 

To write solutions you can download tools from:

| Tool | Usage | Download Location |
|:-----|:-----:|:-----------------:|
|Visual Studio Code |Lightweight program editor. |[Download](https://code.visualstudio.com/download)|
|GCC (Linux)|C / C++ Compiler.|[Download](https://gcc.gnu.org/)|
|MingGW (Windows)| C / C++ Compiler.|[Download](http://www.mingw.org/)|
|XCode toolkit (MacOS)| IDE with multi language support.|[Download](https://developer.apple.com/xcode/)|
|Catch2|C++ Test framework|[Download](https://github.com/catchorg/Catch2)| 

# Test Script 
Test Script for this week's problem can be downloaded from **[here](https://1drv.ms/u/s!An6FDnpXbnZ80jeSzHAGqHA7VUj-)**.

### All the best &#x1F91E;


##### _In case you have any difficulty using the tools or some questions related to this exercise. Reach us at_
#####  1. &#x1F4AC; programmingdays (Skype)