/**
 * Description:
 *  假设你有一条长度为 5 的木版，初始时没有涂过任何颜色。你希望把它的 5 个单位长度分别涂上红、绿、蓝、绿、红色，用一个长度为 5 的字符串表示这个目标：RGBGR。
 *  每次你可以把一段连续的木版涂成一个给定的颜色，后涂的颜色覆盖先涂的颜色。例如第一次把木版涂成 RRRRR，第二次涂成 RGGGR，第三次涂成 RGBGR，达到目标。
 *  现在有一个长为n的木板，用尽量少的涂色次数达到目标。
 *
 * Input:
 *  输入仅一行，包含一个长度为 n 的字符串，即涂色目标。字符串中的每个字符都是一个大写字母，不同的字母代表不同颜色，相同的字母代表相同颜色。
 *
 * Output:
 *  仅一行，包含一个数，即最少的涂色次数。
 *
 * Hints:
 *  1≤n≤400。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
RGBGR
 *
 *  output:
3
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
string s;
int f[410][410];
// f[i][j] 表示涂色s[i...j]需要的最少次数

int main()
{
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++) {
        f[i][i] = 1;
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            for (int k = i; k < j; k++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
            }
            if (s[i] == s[j]) {
                f[i][j]--;
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}