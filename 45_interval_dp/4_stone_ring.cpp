/**
 * Description:
 *  在一个圆形操场的四周摆放 N 堆石子，现要将石子有次序地合并成一堆.规定每次只能选相邻的2堆合并成新的一堆，并将新的一堆的石子数，记为该次合并的得分。
 *  试设计出一个算法，计算出将 N 堆石子合并成 1 堆的最小得分和最大得分。
 *
 * Input:
 *  数据的第 1 行是正整数 N，表示有 N 堆石子。
 *  第 2 行有 N 个整数，第 i 个整数 ai 表示第 i 堆石子的个数。
 *
 * Output:
 *  输出共 2 行，第 1 行为最小得分，第 2 行为最大得分。
 *
 * Hints:
 *  1≤N≤100, 0≤ai≤20
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
4 5 9 4
 *
 *  output:
43
54
 *
 */

#include <iostream>
#include <cstring>

using namespace std;

// 断环为链
int n, a[210], s[210], f[210][110], g[210][110];
// f[i][j]表示将[i,j]的石子合并为一堆的最大得分
// g[i][j]表示将[i,j]的石子合并为一堆的最小得分

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    
    for (int i = 1; i <= 2*n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    memset(g, 0x3f, sizeof g);

    for (int i = 1; i <= 2*n; i++) {
        g[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i + l - 1 <= 2*n; i++) {
            int j = i + l - 1;
            
            for (int k = i; k < j; k++) {
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
                g[i][j] = min(g[i][j], g[i][k] + g[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }

    int ans_min = 1e9, ans_max = 0;

    for (int i = 1; i <= n; i++) {
        ans_min = min(ans_min, g[i][i + n - 1]);
        ans_max = max(ans_max, f[i][i + n - 1]);
    }
    
    cout << ans_min << "\n" << ans_max << endl;
    return 0;
}