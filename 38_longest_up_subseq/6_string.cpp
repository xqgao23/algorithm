/**
 * Description:
 *  小明有一个字符串，由小写英文字母组成。
 *  小明准备对他的字符串进行改造，改造的方法是删除字符串中间的一部分字符。小明希望改造完后，新的字符串中的相邻字符都满足左边的字符小于等于右边的字符（a < b < ... < z）。
 *  例如，对于字符串 happy，小明可以删除第一个字母，变成 appy，满足要求。或者小明删除第二字母，变成 hppy，也满足要求。小明还有其他方法使得结果满足要求。再如，对于字符串 autumn，可以删除 3 个字母变成 amn，或者删除 4 个字母变成 at。其他满足要求的方案还有很多。
 *  小明想知道，对于一个字符串，至少要删除多少个字母能满足要求。
 *
 * Input:
 *  输入一行包含一个字符串。
 *
 * Output:
 *  输出一行，包含一个整数，表示最少要删除的字母个数。
 *
 * Hints:
 *  字符串的长度不超过 100000。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
happy
 *
 *  output:
1
 *
 *  2):
 *  input:
autumn
 *
 *  output:
3
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, f[100010], len;
string s;

int main()
{
    cin >> s;
    n = s.size();
    s = '?' + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] >= f[len]) {
            f[++len] = s[i];
        } else {
            int p = upper_bound(f + 1, f + len + 1, s[i]) - f;
            f[p] = s[i];
        }
    }
    cout << n - len << endl;
    return 0;
}