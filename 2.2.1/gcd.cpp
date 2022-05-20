#include<iostream>
using namespace std;

unsigned gcd_rec(unsigned a, unsigned b, unsigned res) {
    
    unsigned rem_a = 0;
    unsigned rem_b = 0;
    
    rem_a = a % res;
    rem_b = b % res;
    
    if (rem_a == 0 && rem_b == 0)
        return res;
    
    return gcd_rec(a, b, res-1);
}

unsigned gcd(unsigned a, unsigned b)
{
    unsigned more = 0;
    unsigned less = 0;
    unsigned rem = 0;
    
    if (a == 0)
        return b;
    
    if (b == 0)
        return a;
    
    if (a == 1 || b == 1)
        return 1;
    
    if (a == b)
        return a;
    
    if (a > b) {
        more = a;
        less = b;
    } else {
        more = b;
        less = a;
    }
    
    return gcd_rec(a, b, a);
}

int main(){
    
    int a = 0;
    int b = 0;
    
    cout << "Введите 2 числа: ";
    cin >> a >> b;
    cout << "НОД(" << a << ", " << b << ") = " << gcd(a, b) << endl;
    
    return 0;
}
