#include <iostream>
using namespace std;

class Base{
    public:
    void f(){
        cout << "Base::f()" << endl;
    }
};

class Derived : public Base{
    public:
    void f(){
        cout << "Derived::f()" << endl;
    }
};

void f(){
    static int i = 3;
    cout << i;
    if (--i)f();
}

int main (int argc, char * argv[])
{
    // Derived obj;
    // obj.Base::f();
    int i;
    char s[] = "hello";
    for (i = 0; s[i]; ++i);
    cout << i << endl;
    
    i=0;
    while(s[i++]);
       cout << i << endl;

    return EXIT_SUCCESS;
}