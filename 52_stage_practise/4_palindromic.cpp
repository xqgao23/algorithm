/**
 * Description:
 *  现在有一个长为M的字符串S，只由N种小写字母组成。（1≤N≤26）
 *  你可以在任意的位置插入字符，也可以删除任意位置的字符。插入的字符也必须是给定的N种小写字母的某一个。
 *  你的目的是通过插入和删除，让字符串S成为一个回文串。但是插入或删除一个字符有各自的代价cost（插入和删除所需代价可能不同），你要求出使S成为回文串所需要的最小代价。
 *
 * Input:
 *  第1行，2个正整数N,M
 *  第2行，1个字符串S
 *  接下来N行，每行包含一个字符和两个正整数。字符是一个小写字母，第1个整数表示插入1个这个字母需要的代价，第2个整数表示删除1个这个字母需要的代价。
 *
 * Output:
 *  1个整数，使S成为回文串需要的最少代价。
 *
 * Hints:
 *  1≤N≤26, 1≤M≤2000, 1≤cost≤10000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 4
abcb
a 1000 1100
b 350 700
c 200 800
 *
 *  output:
900
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, a[130], b[130], f[2010][2010];
string s;

int main()
{
    cin >> n >> m >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        char ch;
        int x, y;
        cin >> ch >> x >> y;
        a[ch] = x;
        b[ch] = y;
    }
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= m; i++) {
        f[i][i] = 0;
    }
    for (int l = 2; l <= m; l++) {
        for (int i = 1; i + l - 1 <= m; i++) {
            int j = i + l - 1;
            if (s[i] == s[j]) {
                f[i][j] = l == 2 ? 0 : f[i + 1][j - 1];
            }
            f[i][j] = min(f[i][j], f[i + 1][j] + a[s[i]]);
            f[i][j] = min(f[i][j], f[i + 1][j] + b[s[i]]);
            f[i][j] = min(f[i][j], f[i][j - 1] + a[s[j]]);
            f[i][j] = min(f[i][j], f[i][j - 1] + b[s[j]]);
        }
    }
    cout << f[1][m] << endl;
    return 0;
}