/**
 * Description:
 *  由于无敌的凡凡在2005年世界英俊帅气男总决选中胜出，Yali Company总经理Mr.Z心情好，决定给每位员工发奖金。公司决定以每个人本年在公司的贡献为标准来计算他们得到奖金的多少。
 *  于是Mr.Z下令召开m方会谈。每位参加会谈的代表提出了自己的意见："我认为员工a的奖金应该比b高！"Mr.Z决定要找出一种奖金方案，满足各位代表的意见，且同时使得总奖金数最少。每位员工奖金最少为100元。
 *
 * Input:
 *  第一行两个整数n,m，表示员工总数和代表数；
 *  以下m行，每行2个整数a,b，表示某个代表认为第a号员工奖金应该比第b号员工高。
 *
 * Output:
 *  若无法找到合理方案，则输出"Poor Xed"；否则输出一个数表示最少总奖金。
 *
 * Hints:
 *  1≤n≤10000, 1≤m≤20000
 */

/**
 *  Samples:
 *  1):
 *  input:
6 8
1 4
2 5
2 3
3 5
3 4
4 5
6 2
1 6
 *
 *  output:
615
 *
 *  2):
 *  input:
4 4
1 2
2 3
3 4
3 1
 *
 *  output:
Poor Xed
 *
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e4 + 10;
int n, m, rud[N], f[N], ans, cnt;
vector<int> g[N];

void topo_sort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (rud[i] == 0) {
            q.push(i);
            cnt++;
            f[i] = 100;
        }
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto y : g[x]) {
            f[y] = max(f[y], f[x] + 1);
            if (--rud[y] == 0) {
                q.push(y);
                cnt++;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        rud[u]++;
    }
    topo_sort();
    if (cnt != n) {
        cout << "Poor Xed" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        ans += f[i];
    cout << ans << endl;
    return 0;
}