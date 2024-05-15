/**
 * Description:
 *  给你一个串，让你求出长度为 k 的回文子串有多少个。
 *  给出字符串 s，记 n 为字符串的长度，对 k=1∼n 分别求出长度 k 的回文子串的个数。（位置不同就算是不同的子串）
 *
 * Input:
 *  1 行，包含 1 个字符串s。
 *
 * Output:
 *  用 1 行输出 n 个整数，第 i 个整数表示长度 i 的回文子串的数量。数之间用空格分隔。
 *
 * Hints:
 *  字符串s只含小写英文字母，记n是字符串长度，1≤n≤5000。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
abba
 *
 *  output:
4 1 0 1
 *
 *  2):
 *  input:
abacaba
 *
 *  output:
7 0 3 0 1 0 1
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int f[5010][5010], cnt[5010];
string s;
// f[i][j]表示第i个到第j个字符组成的子串是否是回文

int main()
{
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        f[i][i] = 1;
        cnt[1]++;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i + 1]) {
            f[i][i + 1] = 1;
            cnt[2]++;
        }
    }
    for (int l = 3; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            if (s[i] == s[j] && f[i + 1][j - 1]) {
                f[i][j] = 1;
                cnt[l]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << " ";
    }
    return 0;
}