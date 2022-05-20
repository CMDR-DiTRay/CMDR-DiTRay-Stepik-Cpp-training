#include <iostream>

using namespace std;

const unsigned test_rows = 10;
const unsigned test_cols = 15;

void print_array(const int * const * m, unsigned rows, unsigned cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++)
            cout << m[i][j];
        cout << endl;
    }
}

void update_min(int *m[],
                size_t row,
                size_t col,
                int * min_val,
                size_t * min_row)
{
    if (m[row][col] < *min_val) {
        *min_val = m[row][col];
        if (*min_row != row)
            *min_row = row;
    }
}

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min_val = INT_MAX;
    size_t min_row = 0;
    int * tmp_addr = 0;
    
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            update_min(m, i, j, &min_val, &min_row);
    
    if (min_row != 0) {
        tmp_addr = m[0];
        m[0] = m[min_row];
        m[min_row] = tmp_addr;
    }
}

int main() {
    int m[test_rows][test_cols] =
        {
            {10,10,10,10,10,10,10,9,10,10,10,10,10,10,10},
            {9,9,9,9,9,9,9,9,9,8,9,9,9,9,9},
            {8,8,8,8,8,8,8,7,8,8,8,8,8,8,8},
            {7,7,7,7,7,6,7,7,7,7,7,7,7,7,7},
            {6,6,6,5,6,6,6,6,6,6,6,6,6,6,6},
            {5,5,5,5,5,5,5,5,5,5,4,5,5,5,5},
            {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
            {3,3,3,3,3,3,2,3,3,-3,3,3,3,3,3},
            {2,2,2,2,2,2,2,1,2,2,2,2,2,2,2},
            {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1}
        };
    int * mp[test_rows];
    
    for (size_t i = 0; i < test_rows; i++)
        mp[i] = m[i];
    
    swap_min(mp, test_rows, test_cols);
    
    print_array(mp, test_rows, test_cols);
    
    return 0;
}
