#include <iostream>

using namespace std;

void reverse_input() {
    unsigned a = 0;
    
    cin >> a;
    
    if (a == 0)
        return;
    
    reverse_input();
    cout << a << " ";
}

int main()
{
    reverse_input();
    cout << endl;
    return 0;
}
