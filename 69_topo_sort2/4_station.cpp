/**
 * Description:
 *  一条单向的铁路线上，依次有编号为1,2,…,n的n个火车站。每个火车站都有一个级别，最低为 1 级。现有若干趟车次在这条线路上行驶，每一趟都满足如下要求：如果这趟车次停靠了火车站 x，则始发站、终点站之间所有级别大于等于火车站x 的都必须停靠。（注意：起始站和终点站自然也算作事先已知需要停靠的站点）
 *  例如，下表是5趟车次的运行情况。其中，前4 趟车次均满足要求，而第 5 趟车次由于停靠了 3 号火车站（2 级）却未停靠途经的 6 号火车站（亦为 2 级）而不满足要求。
 *  现有 m 趟车次的运行情况（全部满足要求），试推算这n 个火车站至少分为几个不同的级别。
 *
 * Input:
 *  第一行包含 2 个正整数 n,m，用一个空格隔开。
 *  第 i+1 行(1≤i≤m)中，首先是一个正整数 si (2≤si≤n)，表示第i 趟车次有si个停靠站；接下来有si 个正整数，表示所有停靠站的编号，从小到大排列。每两个数之间用一个空格隔开。输入保证所有的车次都满足要求。
 *
 * Output:
 *  一个正整数，即 n 个火车站最少划分的级别数。
 *
 * Hints:
 *  1 <= n，m <= 1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
9 2
4 1 3 5 6
3 3 5 6 
 *
 *  output:
2
 *
 *  2):
 *  input:
9 3
4 1 3 5 6
3 3 5 6
3 1 5 9 
 *
 *  output:
3
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 1010;
int n, m, x[1010], ind[N], g[N][N], vis[N], s, f[N];

void topo_sort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!ind[i]) {
            q.push(i);
            f[i] = 1;
        }
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int y = 1; y <= n; y++) {
            if (g[x][y]) {
                f[y] = max(f[y], f[x] + 1);
                if (--ind[y] == 0) {
                    q.push(y);
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        memset(vis, 0, sizeof vis);
        cin >> s;
        for (int j = 1; j <= s; j++) {
            cin >> x[j];
            vis[x[j]] = 1;
        }
        for (int j = x[1]; j <= x[s]; j++) {
            if (!vis[j]) {
                for (int k = 1; k <= s; k++) {
                    if (!g[j][x[k]]) {
                        g[j][x[k]] = 1;
                        ind[x[k]]++;
                    }
                }
            }
        }
    }
    topo_sort();
    cout << *max_element(f + 1, f + n + 1) << endl;
    return 0;
}