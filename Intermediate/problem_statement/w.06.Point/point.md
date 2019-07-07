![alt text](http://programmingdays.com/img/62c218d0-fda7-4dd2-b49f-8628130c4c8f.png "programmingDays")

# C++ code kata: Week #6

Hello &#x1F44B;

In two-dimensional **[Euclidean](https://en.wikipedia.org/wiki/Euclidean_geometry)** space, a **[point](https://en.wikipedia.org/wiki/Point_(geometry))** is represented by an ordered pair (x,y) of numbers, where the first number conventionally represents the horizontal and is often denoted by x, and the second number conventionally represents the vertical and is often denoted by y. .

# Ground Exercise

In today's exercise &#x1F3C3; you have to create a class called `Point` that may take **zero or two integers** as arguments. The points can be initialized while the creation or later. You also have to write a method such that point can identify its quadrant. The quadrants will go as follows

|X-coordinate|Y-coordinate| Quadrant|
|:-|:-|:-|
|Positive|Positive|First|
|Negative|Positive|Second|
|Negative|Negative|Third|
|Positive|Negative|Fourth|

The example below shows how we write `Point()`. e.g. &#x1F447;

```C++
auto pt1 = Point(12, 4);

cout << pt1;
// x:12 y:4
cout << pt1.quadrant()
// First
```

Moreover, a new `Point` can be created from an existing point. The point class should also have the ability to provide console output.

```C++
auto pt2 = Point(-34, 56);
auto pt3 = Point(pt2);

cout << pt2;
// x:-34 y:56

cout << pt3;
// x:-34 y:56

pt3.x(45);

cout << pt2;
// x:-34 y:56

cout << pt3;
// x:45 y:56

cout << pt2.quadrant();
// Second

cout << pt3.quadrant();
// First

```

# Rules &#x1F4DC;

1. You have to pass either zero or two integers only while object creation.
1. All co-ordinates are in integers only.
1. The return value will be either true or False.
1. You cannot use any library other than the C/ C++ standard library.

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

Test Script for this week's problem can be downloaded from **[here](https://1drv.ms/u/s!An6FDnpXbnZ80mv-6gVzmdRqA3fJ)**.

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
