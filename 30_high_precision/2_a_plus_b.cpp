/**
 * Description:
 *  输入两个正整数 a 和 b, 计算 a+b 的值并输出
 *
 * Input:
 *  两行 , 每行一个正整数 , 分别代表 a 和 b
 *
 * Output:
 *  一行 , 输出 a+b 的结果
 *
 * Hints:
 *  1≤a,b≤10<1000>
 */

/**
 *  Samples:
 *  1):
 *  input:
999999999999999999999999
1
 *
 *  output:
1000000000000000000000000
 *
 *  2):
 *  input:
14561268494113694459841256
98745632145555569812221111
 *
 *  output:
113306900639669264272062367
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
        int t = u;
        if (i <= a[0]) {
            t += a[i];
        }
        if (i <= b[0]) {
            t += b[i];
        }
        c[i] = t % 10;
        u = t / 10;
    }
    if (u > 0) {
        c[++lenc] = u;
    }
    c[0] = lenc;
}

string sa, sb;
int a[1005], b[1005], c[1005];

int main()
{
    cin >> sa >> sb;
    s2BIG(sa, a);
    s2BIG(sb, b);
    addBIG(a, b, c);
    printBIG(c);
    return 0;
}