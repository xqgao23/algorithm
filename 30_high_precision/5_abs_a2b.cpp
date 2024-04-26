/**
 * Description:
 *  输入两个正整数a和b, 计算 ∣a−b∣的值并输出
 *
 * Input:
 *  两行 , 每行一个正整数 , 分别代表a和b
 *
 * Output:
 *  一行 , 输出∣a−b∣的值
 *
 * Hints:
 *  1≤a,b≤10<10000>,
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
999999999999999999999999999
187654321987654321987654321
 *
 *  output:
812345678012345678012345678
 *
 *  2):
 *  input:
1
1000000000000000000000000
 *
 *  output:
999999999999999999999999
 *
 *  3):
 *  input:
7777777777777777777777777
7777777777777777777777779
 *
 *  output:
2
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

void subBIG(int a[], int b[], int c[])
{ // 高精-高精
    int lenc = max(a[0], b[0]), u = 0;
    for (int i = 1; i <= lenc; i++) {
        int t = a[i] - u;
        if (i <= b[0]) {
            t -= b[i];
        }
        if (t < 0) {
            u = 1;
            c[i] = t + 10;
        } else {
            u = 0;
            c[i] = t;
        }
    }
    while (c[lenc] == 0 && lenc > 1) {
        lenc--;
    }
    c[0] = lenc;
}

int cmpBIG(int a[], int b[])
{
    int lena = a[0], lenb = b[0];
    if (lena > lenb) {
        return 1;
    }
    if (lena < lenb) {
        return -1;
    }
    for (int i = lena; i >= 1; i--) {
        if (a[i] > b[i]) {
            return 1;
        }
        if (a[i] < b[i]) {
            return -1;
        }
    }
    return 0;
}

string sa, sb;
int a[1005], b[1005], c[1005];

int main()
{
    cin >> sa >> sb;
    s2BIG(sa, a);
    s2BIG(sb, b);
    if (cmpBIG(a, b) == 1) {
        subBIG(a, b, c);
    } else {
        subBIG(b, a, c);
    }
    printBIG(c);
    return 0;
}