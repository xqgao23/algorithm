/**
 * Description:
 *  输入两个正整数 a 和 b, 计算 a/b 的值并输出
 *
 * Input:
 *  两行 , 每行一个正整数 , 分别代表 a 和 b
 *
 * Output:
 *  输出a/b结果
 *
 * Hints:
 *  1≤a≤10<1000>
 *  1≤b≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
999999999999999999999999
9
 *
 *  output:
111111111111111111111111
 *
 *  2):
 *  input:
1634254846899862270311363684648
112233
 *
 *  output:
14561268494113694459841256
 *
 */

#include <algorithm>
#include <cstring>
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

// 高精/单精
void divBIG(int a[], int b, int c[])
{
    int lenc = a[0], r = 0;
    for (int i = lenc; i >= 1; i--) {
        int t = r * 10 + a[i];
        c[i] = t / b;
        r = t % b;
    }
    while (c[lenc] == 0 && lenc > 1) {
        lenc--;
    }
    c[0] = lenc;
}

string sa;
int a[1010], b, c[1010];

int main()
{
    cin >> sa >> b;
    s2BIG(sa, a);
    divBIG(a, b, c);
    printBIG(c);
    return 0;
}