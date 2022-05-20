#include<iostream>
using namespace std;

char * eoln_pos(const char *str) {
    char *pos = (char *)str;
    while(*pos != 0)
        ++pos;
    return pos;
}

void str_cat(char *to, const char *from)
{
    int from_len = eoln_pos(from) - from;
    to = eoln_pos(to);
    
    for(int i = 0; i <= from_len; i++)
        *(to + i) = *(from + i);
}

int main() {
    char to[256] = "HelloHelloHelloHelloHello";
    const char from[] = "world";
    
    to[5] = 0;
    
    str_cat(to, from);
    cout << "Ответ: \"" << to << "\"" << endl;
    
    return 0;
}
