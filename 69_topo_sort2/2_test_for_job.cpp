/**
 * Description:
 *  Mr.Dog想要找一份工作赚钱养家，但是在应聘时遇到了这样一个测试：
 *  给定一张地图，上面给出了城市之间的单向道路（该地图没有环），每个城市都有一个权值，当你到达一个城市时，你会获得该城市的权值（注意该权值可能为负）。
 *  起点是 1 号城市，终点可以是任意城市，现在Mr.Dog的任务是从起点出发，到达一个终点，通过这条路径它能获得最大的权值。也就是说，Mr.dog可以选择任意一个终点，并使自己获得的权值和尽可能大。
 *  注意，1 号点也可以作为终点，此时权值和就是它自己的权值。
 *
 * Input:
 *  第一行两个整数 N(1≤N≤100000) 和 M(1≤M≤1000000)，表示城市的个数和道路的个数。
 *  接下来 N 行，每行一个整数ai(−20000≤ai≤20000)表示城市 i 的权值。
 *  接下来 M 行，每行两个整数 x 和 y，表示城市 x 到 y 有一条单向边。
 *
 * Output:
 *  请输出一个整数，表示Mr.Dog能获得的最大权值。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6 5
1
1
2
3
3
4
1 2
1 3
2 4
3 4
5 6
 *
 *  output:
6
 *
 *  2):
 *  input:
5 7
1
-2
3
-4
5
1 2
2 5
3 1
3 2
4 1
4 5
3 4
 *
 *  output:
4
 *
 */

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int n, m, a[N], ind[N], f[N], ans = -1e9;
vector<int> g[N];

void topo_sort()
{
    queue<int> q;
    memset(f, -0x3f, sizeof f);
    for (int i = 1; i <= n; i++)
        if (!ind[i])
            q.push(i);
    f[1] = a[1];
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto y : g[x]) {
            f[y] = max(f[y], f[x] + a[y]);
            if (--ind[y] == 0)
                q.push(y);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        ind[y]++;
    }
    topo_sort();
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}