#include<iostream>

using namespace std;

unsigned str_len(const char *str) {
    char *pos = (char *)str;
    while(*pos != 0)
        ++pos;
    return pos - str;
}

bool is_substr(const char *str1, const char *str2) {
    int i = 0;
    
    while (*(str1 + i) == *(str2 + i)) {
        i++;
        
        if(*(str2 + i) == 0)
            return true;
    }
    
    return false;
}

int str_str(const char *text, const char *pattern)
{
    int text_len = str_len(text);
    int pattern_len = str_len(pattern);
    
    if(text_len < pattern_len)
        return -1;
    
    if(*pattern == 0)
        return 0;
    
    for(int i = 0; *(text + i) != 0; i++)
        if(is_substr((text + i), pattern))
            return i;
    
    return -1;
}

int main() {
    const char text[] = "Hello";
    const char pattern[] = "Hello world";
    
#ifdef DEBUG
    //-- Debugging here! --
    
    cout << "is_substr should be true and it's ";
    cout << is_substr(pattern, pattern) << endl;
    
    cout << "is_substr should be false and it's ";
    cout << is_substr(text, pattern) << endl;
    
    cout << "(0,1) is_substr should be false and it's ";
    cout << is_substr("", pattern) << endl;
    
    cout << "(1,0) is_substr should be false and it's ";
    cout << is_substr(text, "") << endl;
    
    cout << "(0,0) is_substr should be true and it's ";
    cout << is_substr("", "") << endl << endl;
    
    struct test{
        int ret_value;
        const char *text;
        const char *pattern;
    };
    test tests[] = {
        {0, "", ""}, //0
        {0, "a", ""}, //1
        {0, "a", "a"}, //2
        {-1, "a", "b"}, //3
        {0, "aa", ""}, //4
        {0, "aa", "a"}, //5
        {0, "ab", "a"}, //6
        {1, "ba", "a"}, //7
        {-1, "bb", "a"}, //8
        {0, "aaa", ""}, //9
        {0, "aaa", "a"}, //10
        {1, "abc", "b"}, //11
        {2, "abc", "c"}, //12
        {-1, "abc", "d"}, //13
        {-1, "a", "aa"}, //14
        {-1, "a", "ba"}, //15
        {-1, "a", "ab"}, //16
        {-1, "a", "bb"}, //17
        {-1, "a", "aaa"}, //18
        {-1, "aa", "aaa"}, //19
        {0, "aaa", "aaa"}, //20
        {0, "aaab", "aaa"}, //21
        {1, "baaa", "aaa"}, //22
        {1, "baaaa", "aaa"}, //23
        {1, "baaab", "aaa"}, //24
        {-1, "abd", "abc"}, //25
        {2, "ababc", "abc"}, //26
        {3, "abdabc", "abc"}, //27
        {-1, "", "a"}, //28
        {2, "asasaf", "asaf"}, //29
        {2, "ababac", "abac"} //30
    };
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        int ret = str_str(tests[i].text, tests[i].pattern);
        (tests[i].ret_value == ret) ? cout << "OK" : cout << "Failed";
        cout << " : " << i << " (" << tests[i].ret_value << " : " << ret << ")" << endl;
    }
    
    //-- No more debugging ;)
#endif
    
    cout << "Номер первого вхождения: " << str_str(text, pattern) << endl;
    
    return 0;
}
