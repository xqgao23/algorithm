/**
 * Description:
 *  给定两个长度为N和M的字符串A和B，求既是A的子序列又是B的子序列的字符串长度最长是多少
 *
 * Input:
 *  第一行两个正整数N和M
 *  第二行包括一个长度为N的字符串，表示字符串A
 *  第三行包括一个长度为M的字符串，表示字符串B
 *  字符串均由小写字母构成
 *
 * Output:
 *  一个整数，即最长公共子序列的长度
 *
 * Hints:
 *  1≤N,M≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 5
acbd
abedc
 *
 *  output:
3
 *
 */
 
#include <iostream>
#include <algorithm>

using namespace std;

char A[1010], B[1010];
int n, m, f[1010][1010];

int main()
{
    cin >> n >> m >> (A + 1) >> (B + 1);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i] == B[j]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }

    cout << f[n][m] << endl;
    
    return 0;
}
