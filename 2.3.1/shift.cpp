#include<iostream>

using namespace std;

void rotate_once(int a[], unsigned size) {
    int t = 0;
    
    t = a[0];
    for (int i = 0; i < size-1; i++)
        a[i] = a[i+1];
    a[size-1] = t;
}

void rotate(int a[], unsigned size, int shift)
{
    if (shift / size > 0)
        shift %= size;
    
    if (shift == 0)
        return;
    
    for (int i = 0; i < shift; ++i)
        rotate_once(a, size);
}

void print_array(int a[], unsigned size) {
    for (int i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    unsigned size = 5;
    int shift = 0;
    
    
    
    cout << "Введите размер сдвига: ";
    cin >> shift;
    
    rotate (a, size, shift);
    print_array(a, size);
    cout << endl;
     
    return 0;
}
