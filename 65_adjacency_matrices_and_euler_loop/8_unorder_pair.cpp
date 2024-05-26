/**
 * Description:
 *  给定 n 个无序字母对（区分大小写，无序即字母对中的两个字母可以位置颠倒）。请构造一个有 (n+1) 个字母的字符串使得每个字母对都在这个字符串中出现。
 *
 * Input:
 *  第一行输入一个正整数 n。
 *  第二行到第 (n+1) 行每行两个字母，表示这两个字母需要相邻。
 *
 * Output:
 *  输出满足要求的字符串。
 *  如果没有满足要求的字符串，请输出 No Solution。
 *  如果有多种方案，请输出字典序最小的方案（即满足前面的字母的 ASCII 编码尽可能小）。
 *
 * Hints:
 *  2≤N≤1500
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
aZ
tZ
Xt
aX
]
 *
 *  output:
XaZtX
 *
 */

#include <iostream>
using namespace std;
int n, g[130][130], d[130], cnt;
char p[1500];

void dfs(int x)
{
    for (int i = 1; i <= 127; i++) {
        if (g[x][i]) {
            g[x][i]--;
            g[i][x]--;
            dfs(i);
        }
    }
    p[++cnt] = x;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        g[s[0]][s[1]]++;
        g[s[1]][s[0]]++;
        d[s[0]]++;
        d[s[1]]++;
    }
    int st = 0, c = 0;
    while (!d[st]) {
        st++;
    }
    for (int i = 1; i <= 127; i++) {

        if (d[i] & 1) {
            st = i;
            break;
        }
    }
    for (int i = 1; i <= 127; i++) {
        if (d[i] & 1) {
            c++;
        }
    }
    if (c != 2 && c != 0) {
        cout << "No Solution" << endl;
        return 0;
    }
    dfs(st);
    if (cnt != n + 1) {
        cout << "No Solution" << endl;
        return 0;
    }
    for (int i = n + 1; i; i--) {
        cout << p[i];
    }
    cout << endl;
    return 0;
}