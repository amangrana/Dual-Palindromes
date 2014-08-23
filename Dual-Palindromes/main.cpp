/*
 ID: dearxia1
 PROG: dualpal
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

char map[11] = "0123456789";

bool check(char *a)
{
    for (char *b = a + strlen(a) - 1; b > a; a ++, b --) {
        if (*a != *b)
            return false;
    }
    return true;
}

void trans(int a, int b, char *c)
{
    int digit = 0;
    while (a >= b) {
        c[digit ++] = map[a % b];
        a = a / b;
    }
    c[digit] = map[a];
    c[digit + 1] = '\0';
}

int main()
{
    //ofstream fout ("dualpal.out");
    //ifstream fin ("dualpal.in");
    int N, S, now = 0;
    char str[999];
    cin >> N >> S;
    for (int i = S + 1; N > 0; i ++) {
        now = 0;
        for (int j = 2; j <= 10; j ++) {
            trans(i, j, str);
            if (check(str))
                now ++;
            if (now > 1) {
                cout << i << '\n';
                N --;
                break;
            }
        }
    }
    return 0;
}
