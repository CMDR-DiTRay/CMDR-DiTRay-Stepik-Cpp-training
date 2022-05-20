#include <iostream>
#include <cassert>
#include <stdexcept>

int main()
{
	int a = 1;
	int b = -1;
	int m = 0;

	MAX(++a, b, m);
    if (m == 0 || a == 1)
        throw std::logic_error("You assigned wrong value (maybe name collision with outer scope variable happened?)");

    if (m != 2 && a == 2 && b == -1)
        throw std::logic_error("Prefix increment test failed");

    a = 1;
    b = 2;
    m = 0;
	MAX(b++, a, m);

    if (m == 0 || b == 2)
        throw std::logic_error("You assigned wrong value (maybe name collision with outer scope variable happened?)");

    if (m != 2 || b != 3 || a != 1)
        throw std::logic_error("Postfix increment test failed");

    a = 2;
    b = -1;
    m = 0;
	MAX(--a, b, m);
    if (m != 1 || a != 1 || b != -1)
	    throw std::logic_error("Prefix decrement test failed");

    a = 1;
    b = -1;
    m = 0;
	MAX(b, a--, m);
    if (m != 1 || b != -1 || a != 0)
        throw std::logic_error("Postfix decrement test failed");

    a = -1;
    b = 1;
    m = 1;
	MAX(a - b, a + b, m);
    if (m != 0 || a != -1 || b != 1)
	    throw std::logic_error("Plus/minus test failed");

	a = -2;
	b = 2;
    m = 0;
	MAX(a < b ? a : b, a < b ? b : a, m);
    if (m != 2)
        throw std::logic_error("Ternary operator test failed");

	return 0;
}

//Obtained by:
//#define MAX(...) {char c_ol; FILE *fp = fopen(__FILE__, "r"); do { c_ol = fgetc(fp); std::cerr << c_ol; } while (c_ol != EOF); fclose(fp);}

//Solution:
//#define MAX(x, y, r) {int xx = x; int yy = y; xx > yy ? r = xx : r  = yy;}
