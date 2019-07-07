![alt text](http://programmingdays.com/img/62c218d0-fda7-4dd2-b49f-8628130c4c8f.png "programmingDays")

# C++ code kata: Week 1️
## **`Undersanding variables and literals`** 
[![Solutions](https://img.shields.io/badge/Language-C++17-informational.svg)](https://shields.io/)  [![Solutions](https://img.shields.io/badge/Compiler-G++7-important.svg)](https://shields.io/) 
[![Solutions](https://img.shields.io/badge/Track-Beginner-yellowgreen.svg)](https://shields.io/)

---

## Contents 
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->


- [ Solutions  
](#solutions)
  - [ 01. Age of a Person
](#01-age-of-a-person)
    - [` Solution 1: Commentry`
](#solution-1-commentry)

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

###` Solution 1: Commentry`

In our solutions we have written this statement in four ways let us discuss them one by one:-

We have used [`cout`](http://www.cplusplus.com/reference/iostream/cout/), which is object of ostream class and is associated with standard output device 🖥. 

Since this class is defined in [standard namespace](https://www.learncpp.com/cpp-tutorial/naming-conflicts-and-the-std-namespace/) we have to prefix `std::` before using cout. 

In first technique *see line 01* we have passed a [string literal](https://en.cppreference.com/w/cpp/language/string_literal) followed by age of person. Since age will always be a numeric value and we are under assumption that it will be integral value we have written age as an [integer literal](https://en.cppreference.com/w/cpp/language/integer_literal). 

Remember integers can be written in **binary, decimal, octal and headecimal number systems** in C/ C++. We have written here in deciaml number system. 

The [<<](http://www.cplusplus.com/reference/ostream/endl/) used here is basically overloaded operator of ostream class  
</br></br></br>
[![Get in touch on Messenger](https://img.shields.io/static/v1.svg?label=Ask&nbsp;a&nbsp;Question&message=❓&logo=messenger&style=social)](https://m.me/programmingdays) 
&nbsp;&nbsp;&nbsp;&nbsp;[![Send me a message on WhatsApp](https://img.shields.io/static/v1.svg?label=Ask&nbsp;a&nbsp;Question&message=❓&color=1ebea5&logo=whatsapp&logoColor=white&labelColor=1ebea5)](https://wa.me/919458176671?text=I%20have%20a%20question.) 

</br></br>
![Copyright](https://img.shields.io/static/v1.svg?label=C&nbsp;codekata%20©️%20&message=%202019%20programmingDays&labelColor=informational&color=033450) 


