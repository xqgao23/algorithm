/**
 * Description:
 *  选手在我们 USACO 的竞赛中的得分越多我们越高兴。
 *  我们试着设计我们的竞赛以便人们能尽可能的多得分,这需要你的帮助。
 *  我们可以从几个种类中选取竞赛的题目，这里的一个“种类”是指一个竞赛题目的集合，解决集合中的题目需要相同多的时间并且能得到相同的分数。
 *  你的任务是写一个程序来告诉 USACO 的职员,应该从每一个种类中选取多少题目，使得解决题目的总耗时在竞赛规定的时间里并且总分最大。
 *
 * Input:
 *  选手在我们 USACO 的竞赛中的得分越多我们越高兴。
 *  我们试着设计我们的竞赛以便人们能尽可能的多得分,这需要你的帮助。
 *  我们可以从几个种类中选取竞赛的题目，这里的一个“种类”是指一个竞赛题目的集合，解决集合中的题目需要相同多的时间并且能得到相同的分数。
 *  你的任务是写一个程序来告诉 USACO 的职员,应该从每一个种类中选取多少题目，使得解决题目的总耗时在竞赛规定的时间里并且总分最大。
 *  输入的第一行是用空格隔开的两个整数，分别代表竞赛时间 m 和题目类 n。
 *  第 2 到第 (n+1) 行，每行两个用空格隔开的整数，第 (i+1) 行的整数 pi,ti 分别代表解决第 i 类题得到的分数和需要花费的时间。
 *  既然是某一类题目，那么这一类题目可以重复选择。
 *
 * Output:
 *  输出一行一个整数，代表最大的总分。
 *
 * Hints:
 *  1≤n,m≤10<4>, 1≤pi, ti≤10<4>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
300 4
100 60
250 120
120 100
35 20
 *
 *  output:
605
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int m, n, w[10010], v[10010], f[2][10010]; // f[i][j] 表示前i种题目用时为j的最大得分

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i & 1][j] = f[i - 1 & 1][j];
            if (j >= w[i]) {
                f[i & 1][j] = max(f[i & 1][j], f[i & 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << f[n & 1][m] << endl;
    return 0;
}