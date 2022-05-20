#include <iostream>

using namespace std;

struct Cls {
    Cls(char c, double d, int i);
private:
    char c;
    double d;
    int i;
};

Cls::Cls(char c, double d, int i) : c(c), d(d), i(i) {}

// Эта функция должна предоставить доступ к полю c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т. е.
// доступ предоставляется на чтение и запись.
char &get_c(Cls &cls) {
    Cls * cls_ptr = & cls;
    char * c_ptr = (char *)cls_ptr;
    return *c_ptr;
}

// Эта функция должна предоставить доступ к полю d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т. е.
// доступ предоставляется на чтение и запись.
double &get_d(Cls &cls) {
    Cls * cls_ptr = & cls;
    double * d_ptr = (double *)cls_ptr + sizeof(char);
    return *d_ptr;
}

// Эта функция должна предоставить доступ к полю i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т. е.
// доступ предоставляется на чтение и запись.
int &get_i(Cls &cls) {
    Cls * cls_ptr = & cls;
    int * i_ptr = (int *)cls_ptr + sizeof(char) + sizeof(double) - 5;
    return *i_ptr;
}

int main() {
    
    Cls * test_obj = new Cls('G', 3.14, 4601110);
    
    cout << "c = " << get_c(*test_obj) << endl;
    cout << "d = " << get_d(*test_obj) << endl;
    cout << "i = " << get_i(*test_obj) << endl;
    
    delete test_obj;
    test_obj = 0;
    
    return 0;
}
