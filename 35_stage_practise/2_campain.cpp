/**
 * Description:
 *  有 n 个候选人竞选班长，第 i 个人得票数为 ai，请你判断最后编号为多少的候选人得票数最高。
 *
 * Input:
 *  第 1 行，一个整数 n (n≤20)，表示1≤ai<10<100>)，表示第 i 个候选人的得票数，数据保证票数不会相同。
 *
 * Output:
 *  第 1 行，输出得票数最多的候选人的编号；
 *  第 2 行，输出该候选人的得票数。
 *
 * Hints:
 *  1≤T≤1000, 1≤a≤10<9>,0≤b≤10<9>,1≤p≤10<9>
 *  1≤ai,bi≤10<18>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
377
62
110
9
 *
 *  output:
1
377
 *
 */

// 高精度
#include <algorithm>
#include <cstdio>
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

int n, f[30][110], x;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        s2BIG(s, f[i]);
        if (cmpBIG(f[i], f[x]) == 1) {
            x = i;
        }
    }
    cout << x << endl;
    printBIG(f[x]);
    return 0;
}
