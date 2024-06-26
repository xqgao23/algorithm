/**
 * Description:
 *  约翰准备了 n 份美味的零食来卖给奶牛们。每天约翰只会售出一份零食。这些零食有以下这些有趣的特性：
 *  （1）零食按照 1∼n 编号，它们被排成一列放在一个很长的盒子里。盒子的两端都有开口，约翰每天可以从盒子的任一端取出最外面的一个出售。
 *  （2）与好吃的奶酪相似，这些零食储存得越久就越好吃。这样约翰就可以把它们卖出更高的价钱。
 *  每份零食的初始价值不一定相同。约翰进货时，第 i 份零食的初始价值为 vi。第 i 份零食如果在第 a 天出售，则它的售价vi×a。
 *  约翰告诉了你所有零食的初始价值，并希望你能帮他计算一下，在这些零食全被卖出后，他最多能得到多少钱。
 *
 * Input:
 *  第 1 行, 1 个正整数 n。
 *  第 2 行, n 个正整数 v1,v2,...,vn.
 *
 * Output:
 *  输出约翰卖出所有零食后能得到的最大收益。
 *
 * Hints:
 *  1≤n≤2000, 1≤vi≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
1 3 1 5 2
 *
 *  output:
43
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, v[2010], f[2010][2010];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        f[i][i] = v[i] * n;
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            f[i][j] = max(f[i][j], f[i + 1][j] + v[i] * (n - l + 1));
            f[i][j] = max(f[i][j], f[i][j - 1] + v[j] * (n - l + 1));
        }
    }
    cout << f[1][n] << endl;
    return 0;
}