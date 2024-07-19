/**
 * Description:
 *  鲁宾逊先生有一只宠物猴，名叫多多。这天，他们两个正沿着乡间小路散步，突然发现路边的告示牌上贴着一张小小的纸条：“欢迎免费品尝我种的花生！——熊字”。
 *  鲁宾逊先生和多多都很开心，因为花生正是他们的最爱。在告示牌背后，路边真的有一块花生田，花生植株整齐地排列成矩形网格（如图1）。有经验的多多一眼就能看出，每棵花生植株下的花生有多少。为了训练多多的算术，鲁宾逊先生说：“你先找出花生最多的植株，去采摘它的花生；然后再找出剩下的植株里花生最多的，去采摘它的花生；依此类推，不过你一定要在我限定的时间内回到路边。”
 *  我们假定多多在每个单位时间内，可以做下列四件事情中的一件：
 *  1)从路边跳到最靠近路边（即第一行）的某棵花生植株；
 *  2)从一棵植株跳到前后左右与之相邻的另一棵植株；
 *  3)采摘一棵植株下的花生；
 *  4)从最靠近路边（即第一行）的某棵花生植株跳回路边。
 *  现在给定一块花生田的大小和花生的分布，请问在限定时间内，多多最多可以采到多少个花生？注意可能只有部分植株下面长有花生，假设这些植株下的花生个数各不相同。
 *  例如在图2所示的花生田里，只有位于(2,5),(3,7),(4,2),(5,4)的植株下长有花生，个数分别为13,7,15,9。沿着图示的路线，多多在21个单位时间内，最多可以采到37个花生。
 *
 * Input:
 *  第一行包括三个整数，M, N和K，用空格隔开；表示花生田的大小为M×N（1≤M,N≤20），多多采花生的限定时间为K（0≤K≤1000）个单位时间。接下来的M行，每行包括N个非负整数，也用空格隔开；第i+1行的第j个整数Pij（0≤Pij≤500）表示花生田里植株(i,j)下花生的数目，0表示该植株下没有花生。
 *
 * Output:
 *  一行，这一行只包含一个整数，即在限定时间内，多多最多可以采到花生的个数。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6 7 21
0 0 0 0 0 0 0
0 0 0 0 13 0 0
0 0 0 0 0 0 7
0 15 0 0 0 0 0
0 0 0 9 0 0 0
0 0 0 0 0 0 0
 *
 *  output:
37
 *
 *  2):
 *  input:
6 7 20 
0 0 0 0 0 0 0 
0 0 0 0 13 0 0 
0 0 0 0 0 0 7 
0 15 0 0 0 0 0 
0 0 0 9 0 0 0 
0 0 0 0 0 0 0
 *
 *  output:
28
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int a[101][101];
struct node {
    int x;
    int y;
};

vector<node> p[501];

int dis(node t1, node t2)
{
    return abs(t1.x - t2.x) + abs(t1.y - t2.y) + 1 + t2.x;
}

int move(node t1, node t2)
{
    return abs(t1.x - t2.x) + abs(t1.y - t2.y) + 1;
}

int main()
{
    int m, n, k;

    cin >> m >> n >> k;

    int maxn = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            maxn = max(maxn, a[i][j]);
            node t;
            t.x = i;
            t.y = j;
            p[a[i][j]].push_back(t);
        }
    }

    int maxk = 0;
    node pre;
    pre.y = p[maxn].front().y;
    for (int i = maxn; i > 0; i--) {
        if (k <= 0) {
            break;
        }
        for (auto t : p[i]) {
            if (dis(pre, t) <= k) {
                maxk += i;
                k -= move(pre, t);
                pre.x = t.x;
                pre.y = t.y;
            } else {
                k = 0;
                break;
            }
        }
    }

    cout << maxk << endl;

    return 0;
}