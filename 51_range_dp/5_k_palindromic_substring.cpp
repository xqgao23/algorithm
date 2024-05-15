/**
 * Description:
 *  给你一个串，让你求出k阶回文子串有多少个。k阶回文的定义是如下：
 *  （1）所有回文串都是1阶回文。
 *  （2）如果一个回文串是k阶回文，那么它首先是一个回文串，并且它的左半边是一个k−1阶回文。（k≥2）
 *  这里字符串的左半边指的是长度为一半（向下取整）的前缀。例如"aabaa"的左半边是"aa"。
 *  需要注意如果一个字串是k阶回文，那他同时也是k−1阶以及更低阶的回文。
 *  给出字符串s，记n为字符串的长度，对k=1∼n分别求出k阶子串的个数。（位置不同就算是不同的子串）
 *
 * Input:
 *  1 行，包含 1 个字符串s。
 *
 * Output:
 *  用1行输出n个整数，第i个整数表示i阶回文子串的数量。数之间用空格分隔。
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
6 1 0 0
 *
 *  2):
 *  input:
abacaba
 *
 *  output:
12 4 1 0 0 0 0
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int f[5010][5010], cnt[5010];
string s;
// f[i][j]表示第i个到第j个字符组成的子串的阶数

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
            f[i][i + 1] = 2;
            cnt[2]++;
        }
    }
    for (int l = 3; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            if (s[i] == s[j] && f[i + 1][j - 1]) {
                f[i][j] = f[i][i + l / 2 - 1] + 1;
                cnt[f[i][j]]++;
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        cnt[i] += cnt[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << " ";
    }
    return 0;
}