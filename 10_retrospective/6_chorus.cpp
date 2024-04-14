/**
 * Description:
 *  现在小猴所在的小小动物园需要选拔合唱团参与节目表演，要求从动物园的n位小动物中，选出m个小朋友排成一行参加合唱比赛
 *  那么你能帮助小猴找到每一种排列方式吗？
 *   （小动物分别用编号1~n表示，不同顺序不是同一种排列方式）
 *  例如，在3个小动物中选择2个去参加比赛：
 *   1、2
 *   1、3
 *   2、1
 *   2、3
 *   3、1
 *   3、2
 *  一共有6种方法
 *
 * Input:
 *  2个正整数n, m
 *
 * Output:
 *  每行一个排列
 *
 * Hints:
 *  1≤m<=n<=15
 */

/**
 *  Samples:
 *  1):
 *  input:
4 2
 *
 *  output:
1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3
 *
 */

#include <iostream>
using namespace std;
int n, m, vis[20], p[20];

void dfs(int step)
{
    if (step > m) {
        for (int i = 1; i <= m; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            p[step] = i;
            vis[i] = 1;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    dfs(1);
    return 0;
}