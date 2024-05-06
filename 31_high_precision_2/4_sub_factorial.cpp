/**
 * Description:
 *  读入n, 然后读入n个非负整数a1,a2,…,an, 输出这些整数的阶乘之和.
 *  规定0的阶乘等于1
 *
 * Input:
 *  共两行
 *  第1行 , 1个正整数n
 *  第2行 , n个正整数a1,a2,...,an, 以空格分隔
 *
 * Output:
 *  输出n个正整数的阶乘之和
 *
 * Hints:
 *  0≤n≤100, 0≤ai≤200,保证输出不超过1000位
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
8 15 19 2 5
 *
 *  output:
121646408083240442
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;

void s2BIG(string s, int a[])
{ // 高精度输入
    int lena = s.size();
    for (int i = 1; i <= lena; i++) {
        a[i] = s[lena - i] - '0';
    }
    a[0] = lena;
}

void printBIG(int a[])
{ // 高精度输出
    int lena = a[0];
    for (int i = lena; i >= 1; i--) {
        cout << a[i];
    }
    cout << endl;
}

void addBIG(int a[], int b[], int c[])
{ // 高精+高精
    int lenc = max(a[0], b[0]), u = 0;
    for (int i = 1; i <= lenc; i++) {
        int t = a[i] + b[i] + u;
        c[i] = t % 10;
        u = t / 10;
    }
    if (u > 0) {
        c[++lenc] = u;
    }
    c[0] = lenc;
}

// 高精*单精
void mulBIG(int a[], int b, int c[])
{
    int lenc = a[0], u = 0;
    for (int i = 1; i <= lenc; i++) {
        int t = a[i] * b + u;
        c[i] = t % 10;
        u = t / 10;
    }
    while (u > 0) {
        c[++lenc] = u % 10;
        u /= 10;
    }
    c[0] = lenc;
}

string sa;
int n, f[210][1010], c[1010], x;

int main()
{
    s2BIG("1", f[0]);
    for (int i = 1; i <= 200; i++) {
        mulBIG(f[i - 1], i, f[i]);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        addBIG(c, f[x], c);
    }
    printBIG(c);
    return 0;
}