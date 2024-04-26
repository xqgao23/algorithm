/**
 * Description:
 *  因某些不可抗力, 今年世界邀请赛总决赛无法举行了.
 * 主办方决定用投票的方式，从总决赛的两支队伍(A和B)中选出冠军.
 * 给出每次投票是投给哪个队的, 以及票数. 判断哪个队伍总得票多,
 * 并输出这个队伍的总得票数.
 *
 * Input:
 *  第1行, 一个正整数n
 *  接下来n行, 每行代表一次投票. 第一个字符(A或B)表示投给哪支队伍,
 * 接下来是一个正整数表示此次投票数, 中间用空格分隔.
 *
 * Output:
 *  第1行, 输出1个字符表示得票多的队伍
 *  第2行, 输出得票多的队伍的总得票数
 *
 * Hints:
 *  1≤n≤1000, 得票数≤10<1000>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
A 1528
B 1421
B 9999
A 9000
 *
 *  output:
B
11420
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
int n, a[1005], b[1005], x[1005];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char op;
        string s;
        cin >> op >> s;
        s2BIG(s, x);
        if (op == 'A') {
            addBIG(a, x, a);
        } else {
            addBIG(b, x, b);
        }
    }
    if (cmpBIG(a, b) == 1) {
        cout << "A" << endl;
        printBIG(a);
    } else {
        cout << "B" << endl;
        printBIG(b);
    }
    return 0;
}