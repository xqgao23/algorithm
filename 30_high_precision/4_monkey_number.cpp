/**
 * Description:
 *  小猴发明了一种表示数字的方法 :
 * 给出一个开头数 L 和一个结尾数 R (L<R) ，小猴将L到R的十进制数从左到右写在一起得到的数字记为(L∼R)
 *  (4∼8)表示45678, (8∼12)表示89101112,(98∼110)表示9899100101102103104105106107108109110.
 *  小猴现在有两个这样表示的正整数 , 他想计算两个正整数的和
 *
 * Input:
 *  输入有2行 , 每行2个正整数 :
 *  第1行2个正整数L1, R1,以空格分隔
 *  第2行2个正整数L2,R2,以空格分隔
 *  表示小猴想要计算(L1~R1)+(L2~R2)
 *
 * Output:
 *  输出一行 , 两个正整数之和的十进制表示
 *
 * Hints:
 *  1≤L1<R1≤999, 1≤L2<R2≤999
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 14
22 25
 *
 *  output:
234567891033353739
 *
 *  2):
 *  input:
35 52
82 99
 *
 *  output:
1182022242628303234363840424446485051
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

int L1, R1, L2, R2;
int a[3010], b[3010], c[3010];
string sa, sb;

int main()
{
    cin >> L1 >> R1 >> L2 >> R2;
    for (int i = L1; i <= R1; i++) {
        sa += to_string(i);
    }
    for (int i = L2; i <= R2; i++) {
        sb += to_string(i);
    }
    s2BIG(sa, a);
    s2BIG(sb, b);
    addBIG(a, b, c);
    printBIG(c);
    return 0;
}