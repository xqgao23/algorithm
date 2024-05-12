/**
 * Description:
 *  设A和B是两个字符串，我们要用最少的操作次数，将字符串A转换为字符串B
 *  操作分为三种：
 *  1、删除一个字符
 *  2、添加一个字符
 *  3、将一个字符改为另外一个字符
 *  注意：字符串均由小写字母构成
 *
 * Input:
 *  第一行为字符串A
 *  第二行为字符串B
 *  字符串长度均小于2000
 *
 * Output:
 *  只有一个正整数
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
sfdqxbw
gfdgw
 *
 *  output:
4
 *
 */
 
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char A[2010], B[2010];
int n, m, f[2010][2010];

int main()
{
    cin >> (A + 1) >> (B + 1);

    int n = strlen(A + 1), m = strlen(B + 1);
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i] == B[j]) {
                f[i][j] = f[i - 1][j - 1];
            } else {
                f[i][j] = min(min(f[i - 1][j - 1], f[i - 1][j]), f[i][j - 1]) + 1;
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
