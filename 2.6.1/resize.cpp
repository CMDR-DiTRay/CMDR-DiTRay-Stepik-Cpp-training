#include "resize.hpp"

using namespace std;

int main() {
    char * a = array_init(ARRAY_SIZE);
    
    a = resize(a, ARRAY_SIZE, NEW_ARRAY_SIZE);
    
    array_print(a, ARRAY_SIZE);
    
    delete [] a;
    a = 0;
    
    return 0;
}
