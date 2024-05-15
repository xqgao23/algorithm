/**
 * Description:
 *  你的朋友有一台声控打印机。当你念字母时，机器会把它们写刻在一张纸上。举个例子，如果你按这个顺序念“c”、“o”、“d”和“e”，那么机器就会在纸上写“code”。
 *  但是这台机器有个缺陷，如果你念w，它会写vv而不是w，如果你念m，它会写nn而不是m。其他字母和以前一样：如果你念的是“w”,“m”以外的字母，机器就会把它原封不动地写在纸上
 *  现在你在邮箱里收到了一封信，是你的朋友用他的机器写的。你需要求出所有原本可能的信息有多少种。由于答案可能很大，请输出答案对10<9>+7取模后的结果。
 *  如果没有一个字符串经过机器后能得到信的内容，请输出0。
 *
 * Input:
 *  第 1 行，1 个正整数 n，表示字符串的长度（1≤n≤10<5>）
 *  第 2 行，一个长度为 n 的字符串 s，表示收到的信息，s只包含小写字母。
 *
 * Output:
 *  输出我所有原本可能得到的信息有多少种（即多少个字符串经过机器后能得到我收到的信息），对10<9>+7取模。
 *
 * Hints:
 *  1≤N≤500, 1≤M≤200000, 1≤Li≤Ri≤N, 1≤Q≤100000,1≤p≤q≤N,
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
10
ovvokarinn
 *
 *  output:
4
 *
 *  2):
 *  input:
6
banana
 *
 *  output:
1
 *
 *  3):
 *  input:
3
nnn
 *
 *  output:
3
 *
 *  4):
 *  input:
6
amanda
 *
 *  output:
0
 *
 */

#include <iostream>
using namespace std;
typedef long long LL;
int n, mod = 1e9 + 7;
LL f[100010];
string s;

int main()
{
    cin >> n >> s;
    s = ' ' + s;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0 << endl;
            return 0;
        }
        f[i] = f[i - 1];
        if (i >= 2 && s[i] == 'v' && s[i - 1] == 'v') {
            f[i] = (f[i] + f[i - 2]) % mod;
        }
        if (i >= 2 && s[i] == 'n' && s[i - 1] == 'n') {
            f[i] = (f[i] + f[i - 2]) % mod;
        }
    }
    cout << f[n] << endl;
    return 0;
}