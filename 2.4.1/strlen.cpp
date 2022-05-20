#include<iostream>
using namespace std;

unsigned str_len(const char *str) {
    char *pos = (char *)str;
    while(*pos != 0)
        ++pos;
    return pos - str;
}

int main() {
    const char str[] = "Hello world!";
    
    cout << str_len(str) << endl;
    
    return 0;
}
