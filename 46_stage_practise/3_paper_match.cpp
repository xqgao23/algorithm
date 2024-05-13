/**
 * Description:
 *  给你两个字符串A和B，代表两名涉嫌作弊的学生的论文。
 *  对于任意两个字符串C和D，定义它们的相似度F(C,D)=4×LCS(C,D)−∣C∣−∣D∣，其中LCS(C,D)表示C和D的最长公共子序列的长度，∣C∣和∣D∣表示C和D的长度。
 *  给出字符串A和B，计算它们的相似度F(A,B)。
 *
 * Input:
 *  第一行两个整数n(1≤n≤5000)和m(1≤m≤5000)，表示A和B的长度。
 *  第二行一个字符串A。
 *  第三行一个字符串B。
 *  字符串仅由小写字母组成。
 *
 * Output:
 *  一个整数，表示A和B的相似度F(A,B)
 *
 * Hints:
 *  1≤M≤10<5>, 0≤N≤10, 0≤Di,ni≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 5
abba
babab
 *
 *  output:
3
 *
 *  2):
 *  input:
7 7
uiibwws
qhtkxcn
 *
 *  output:
-14
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, m, f[5010][5010];
char A[5010], B[5010];

int main()
{
    cin >> n >> m >> (A + 1) >> (B + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(max(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1] + (A[i] == B[j]));
        }
    }
    cout << 4 * f[n][m] - n - m << endl;
    return 0;
}