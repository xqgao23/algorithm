/**
 * Description:
 *  蚂蚁国由 N 个城镇组成。有 M 条道路连接着这些城镇，所有城镇之间可以互相到达。
 *  蚂蚁托尼和他的朋友们想要走遍国内的每一个角落。
 *  他们打算参观每一条路，而且每条路必须恰好被访问一次。然而，对于一个小团队来说，这可能是一个不可能完成的任务。因此，他们正尝试将所有人分成几个小组，每个小组可以从不同的城镇出发。现在托尼想知道，为了实现他们的目标，至少需要组成多少个蚂蚁小组。
 *
 * Input:
 *  输入第一行两个整数 N 和 M，表示点数和边数。
 *  接下来 M 行每行两个整数a,b，表示a,b之间有一条边。
 *
 * Output:
 *  输出一个数字，表示最少需要几个蚂蚁小组。
 *
 * Hints:
 *  1≤N≤1000，0≤M≤20000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 5
1 2
2 3
3 4
4 5
5 1
 *
 *  output:
1
 *
 *  2):
 *  input:
6 9
1 2
2 3
3 4
4 5
5 6
6 1
1 4
2 5
3 6
 *
 *  output:
3
 *
 */

#include <iostream>
using namespace std;
int n, m, d[1010], s;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        d[a]++;
        d[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] & 1) {
            s++;
        }
    }
    if (s == 0) {
        cout << 1 << endl;
    } else {
        cout << (s + 1) / 2 << endl;
    }
    return 0;
}