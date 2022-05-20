#include <iostream>

using namespace std;

const size_t test_rows = 3;
const size_t test_cols = 3;

void print_array(const int * const * m, unsigned rows, unsigned cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++)
            cout << m[i][j];
        cout << endl;
    }
}

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** mt = new int * [cols];
    mt[0] = new int[cols * rows];
    for (size_t i = 1; i < cols; i++)
        mt[i] = mt[i - 1] + rows;
    
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            mt[j][i] = m[i][j];
    
    return mt;
}

int test_transpose() {
    
    return 0;
}

int main() {
    int m[test_rows][test_cols] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int * mp[test_rows];
    int ** arr = 0;
    
    for (size_t i = 0; i < test_rows; i++)
        mp[i] = m[i];
    
    arr = transpose(mp, test_rows, test_cols);
    
    print_array(arr, test_cols, test_rows);
    
    return 0;
}
