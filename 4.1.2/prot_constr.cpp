#include <iostream>
#include <cstring>

using namespace std;

struct Foo {
        void say() const { std::cout << "Foo says: " << msg << "\n"; }
    protected:
        Foo(const char *msg) : msg(msg) { }
    private:
        const char *msg;
    };

void foo_says(const Foo &foo) { foo.say(); }


// Вам нужно определить функцию get_foo, как описано в задании,
// чтобы компилировался и работал как ожидается следующий код:
//
// foo_says(get_foo("Hello!"));


Foo get_foo(const char *msg) {
    struct Bar : Foo {
        Bar(const char *msg) : Foo(msg) { }
    };
    
    Bar bar(msg);
    
    return (Foo) bar;
}

int main() {
    
    cout << "Size of Foo: " << sizeof(Foo) << endl;
    cout << "Size of char *: " << sizeof(char *) << endl;
    
    foo_says(get_foo("Hello!"));
    
    return 0;
}
