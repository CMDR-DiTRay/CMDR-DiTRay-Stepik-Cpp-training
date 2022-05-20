#include <iostream>
#include "unit_test.hpp"

using namespace std;

const resize_tests r_tests[] = {
    {0, 0},
    {0, 1},
    {1, 0},
    {1, 1},
    {0, 50},
    {50, 0},
    {100, 50},
    {50, 100},
    {100, 100}
};

int resize_test() {
    int size = 0;
    int new_size = 0;
    
    for (int i = 0; i < sizeof(r_tests) / sizeof(r_tests[0]); i++) {
        size = r_tests[i].size;
        new_size = r_tests[i].new_size;
        
        cout << "Тест " << i+1 << " (";
        cout << size << ", " << new_size << "):" << endl;
        
        char * a = array_init(size);
        a = resize(a, size, new_size);
        
        if (a != 0)
            array_print(a, size, 1);
        else
            cout << "\t" << "Нулевой указатель!" << endl;
        
        delete [] a;
        a = 0;
    }
    
    
    return 0;
}

int main() {
    resize_test();
    return 0;
}
