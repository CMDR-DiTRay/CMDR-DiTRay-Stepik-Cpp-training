#include <iostream>

using namespace std;

const int STRING_BLOCK = 8;

char *resize(const char *str, unsigned size, unsigned new_size) {
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

char *get_line() {
    char * line = new char[STRING_BLOCK];
    char tmp_char = '0';
    int len = 0;
    
    while (cin.get(tmp_char)) {
        
        if ((tmp_char == '\n') || (tmp_char == -1))
            tmp_char = 0;
        
        if ((len > 0) && (len % STRING_BLOCK == 0))
            line = resize(line, len, len + STRING_BLOCK);
        
        line[len] = tmp_char;
        
        if (tmp_char == 0)
            break;
        
        len++;
    }
    
    if (len % STRING_BLOCK == 0)
        line = resize(line, len, len + 1);
    
    line[len] = 0;
    
    return line;
}

int main() {
    
    char * str = 0;
    
    cout << "Введите строку:" << endl;
    str = get_line();
    cout << "Вы ввели:" << endl << str << endl;
    
    return 0;
}
