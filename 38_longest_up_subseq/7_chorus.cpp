/**
 * Description:
 *  小明有一个字符串，由小写英文字母组成。
 *  小明准备对他的字符串进行改造，改造的方法是删除字符串中间的一部分字符。小明希望改造完后，新的字符串中的相邻字符都满足左边的字符小于等于右边的字符（a < b < ... < z）。
 *  例如，对于字符串 happy，小明可以删除第一个字母，变成 appy，满足要求。或者小明删除第二字母，变成 hppy，也满足要求。小明还有其他方法使得结果满足要求。再如，对于字符串 autumn，可以删除 3 个字母变成 amn，或者删除 4 个字母变成 at。其他满足要求的方案还有很多。
 *  小明想知道，对于一个字符串，至少要删除多少个字母能满足要求。
 *  N位同学站成一排，音乐老师要请其中的N−K位同学出列，使得剩下的K位同学排成合唱队形。
 *  合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1,2,⋯,K，他们的身高分别为T1,T2,…,TK， 则他们的身高满足T1<T2<⋯<Ti-1<Ti>Ti+1>⋯>TK-1>TK(1≤i≤K)。
 *  你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。
 *
 * Input:
 *  第一行是一个整数N，表示同学的总数。
 *  第二行有n个整数，用空格分隔，第i个整数Ti是第i位同学的身高(厘米)
 *
 * Output:
 *  一个整数，最少需要几位同学出列。
 *
 * Hints:
 *  n≤10<5>；1≤Ti≤10<6>；
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
8
186 186 150 200 160 130 197 220
 *
 *  output:
4
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, t[100010], f[100010], g[100010], dp[100010], len;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++) {
        if (t[i] > dp[len]) {
            dp[++len] = t[i];
            f[i] = len;
        } else {
            int p = lower_bound(dp + 1, dp + len + 1, t[i]) - dp;
            dp[p] = t[i];
            f[i] = p;
        }
    }
    len = 0;
    for (int i = n; i >= 1; i--) {
        if (t[i] > dp[len]) {
            dp[++len] = t[i];
            g[i] = len;
        } else {
            int p = lower_bound(dp + 1, dp + len + 1, t[i]) - dp;
            dp[p] = t[i];
            g[i] = p;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i] + g[i] - 1);
    }
    cout << n - ans << endl;
    return 0;
}