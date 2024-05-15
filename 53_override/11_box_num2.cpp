/**
 * Description:
 *  帅帅经常跟同学玩一个矩阵取数游戏：对于一个给定的 n×m 的矩阵，矩阵中的每个元素 ai,j 均为非负整数。游戏规则如下：
 *  	1.	每次取数时须从每行各取走一个元素，共n 个。经过 m 次后取完矩阵内所有元素；
 *  	2.	每次取走的各个元素只能是该元素所在行的行首或行尾；
 *  	3.	每次取数都有一个得分值，为每行取数的得分之和，每行取数的得分 = 被取走的元素值 ×2<i>，其中 i 表示第 i 次取数（从 1 开始编号）；
 *  	4.	游戏结束总得分为 m 次取数得分之和。
 *  帅帅想请你帮忙写一个程序，对于任意矩阵，可以求出取数后的最大得分。
 *
 * Input:
 *  输入包括 n+1 行：
 *  第一行为两个用空格隔开的整数 n 和 m。
 *  第 2∽n+1 行为 n×m 矩阵，其中每行有 m 个用单个空格隔开的非负整数。
 *
 * Output:
 *  输出仅包含1行，为一个整数，即输入矩阵取数后的最大得分。
 *
 * Hints:
 *  1≤n,m≤80, 0≤ai,j≤1000,
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 3
1 2 3
3 4 2
 *
 *  output:
82
 *
 */

// __int128版本
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, a[85][85];
__int128 f[85][85], ans, p[85];

void cal()
{
    p[0] = 1;
    for (int i = 1; i <= m; i++) {
        p[i] = p[i - 1] * 2;
    }
}

void print(__int128 x)
{
    if (x > 9) {
        print(x / 10);
    }
    putchar(x % 10 + '0');
}

__int128 getv(int a[])
{
    memset(f, 0, sizeof f);
    for (int i = 1; i <= m; i++) {
        f[i][i] = f[i][i] + p[m] * a[i];
    }
    for (int l = 2; l <= m; l++) {
        for (int i = 1; i + l - 1 <= m; i++) {
            int j = i + l - 1;
            f[i][j] = max(f[i][j], f[i + 1][j] + p[m - l + 1] * a[i]);
            f[i][j] = max(f[i][j], f[i][j - 1] + p[m - l + 1] * a[j]);
        }
    }
    return f[1][m];
}

int main()
{
    cin >> n >> m;
    for (int i = 1;
         i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    cal();
    for (int i = 1; i <= n; i++) {
        ans = ans + getv(a[i]);
    }
    print(ans);
    return 0;
}