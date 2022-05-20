#pragma once
#include <iostream>

using namespace std;

#define ARRAY_SIZE 100
#define NEW_ARRAY_SIZE 50

char *resize(const char *str, unsigned size, unsigned new_size)
{
    int res_size = 0;
    
    if (size == new_size)
        return (char *)str;
    
    if (new_size == 0) {
        delete [] str;
        return 0;
    }
    
    char * new_str = new char[new_size];
    
    if (size > new_size)
        res_size = new_size;
    else
        res_size = size;
    
    for (int i = 0; i < res_size; i++)
        new_str[i] = str[i];
    
    delete [] str;
    str = 0;
    
    return new_str;
}

char *array_init(unsigned size) {
    char * a = new char[size];
    
    for (int i = 0; i < size; i++)
        a[i] = (i % 10) + 48;
    
    return a;
}

void array_print(const char * a, unsigned size) {
    for (int i = 0; i < size + 3; i++)
        cout << "a[" << i << "] = " << a[i] << endl;
}
