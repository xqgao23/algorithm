/**
 * Description:
 *  输入一个不超过1000位的高精度数，并输出。
 *
 * Input:
 *  一个不超过1000位的正整数。
 *
 * Output:
 *  原样输出。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
12345678901234567890
 *
 *  output:
12345678901234567890
 *
 */

#include <iostream>
using namespace std;
int a[1010];

// 高精度输入
void s2BIG(string s, int a[])
{
    int lena = s.size();
    for (int i = 1; i <= lena; i++) {
        a[i] = s[lena - i] - '0';
    }
    a[0] = lena;
}

// 高精度输出
void printBIG(int a[])
{
    int lena = a[0];
    for (int i = lena; i >= 1; i--) {
        cout << a[i];
    }
    cout << endl;
}

int main()
{
    string s;
    cin >> s;
    s2BIG(s, a);
    printBIG(a);
    return 0;
}