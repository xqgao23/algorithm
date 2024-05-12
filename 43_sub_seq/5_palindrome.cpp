/**
 * Description:
 *  给出一个字符串，你可在任意位置添加字符，问最少再添加几个字符，可以使这个字符串成为回文字符串。
 *  例如，字符串"Ab3bd"可以添加两个字符，成为回文串"dAb3bAd". 也可以添加两个字符，成为回文串"Adb3bdA"
 *
 * Input:
 *  第1行1个正整数n，表示字符串长度
 *  第2行一个字符串，由英文字母和数字组成
 *
 * Output:
 *  输出一个整数，使字符串成为回文最少需要添加的字符数
 *
 * Hints:
 *  3≤N≤5000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
Ab3bd
 *
 *  output:
2
 *
 */
 
#include <iostream>
#include <algorithm>

using namespace std;

int n, f[5010][5010];
string s;

int main()
{
    cin >> n >> s;

    string t = s;

    s = ' ' + s;
    reverse(t.begin(), t.end());
    t = ' ' + t;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (t[i] == s[j]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }

    cout << n - f[n][n] << endl;
    return 0;
}
