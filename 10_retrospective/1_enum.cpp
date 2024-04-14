/**
 * Description:
 *  写一个递归函数，枚举1∼n的所有排列方式（全排列枚举）.
 * 若两种排列方法中前k−1个数相同，则第k个数更小的在前.
 * 例如对n=3,应该按如下顺序给出结果{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}.
 *
 * Input:
 *  一个正整数n
 *
 * Output:
 *  n!行, 每行一个排列, 按题目要求顺序.
 *
 * Hints:
 *  1≤n<=8
 */

/**
 *  Samples:
 *  1):
 *  input:
3
 *
 *  output:
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
 *
 */

#include <iostream>

using namespace std;
int n, p[20], vis[20];

void dfs(int step)
{
    if (step > n) {
        for (int i = 1; i <= n; i++) {
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

    cin >> n;
    dfs(1);
    return 0;
}