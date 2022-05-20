#include <iostream>
#include "unit_test.hpp"

using namespace std;

const resize_tests r_tests = {
    {0, 0},
    {0, 1},
    {1, 0},
    {1, 1},
    {0, 50},
    {50, 0},
    {100, 50},
    {50, 100},
    {100, 100}
}

int resize_test() {
    for (int i = 0; i < sizeof(r_tests): i++) {
        cout << "Test " << i << ": " << endl;
        
        char * a = array_init(r_tests[i].);
        
        a = resize(a, )
        
        delete [] a;
        a = 0;
    }
    
        
        return 0;
}

int main() {
    resize();
    return 0;
}
