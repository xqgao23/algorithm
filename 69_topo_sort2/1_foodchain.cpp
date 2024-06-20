/**
 * Description:
 *  你知道食物链吗？Delia生物考试的时候，数食物链条数的题目全都错了，因为她总是重复数了几条或漏掉了几条。于是她来就来求助你，然而你也不会啊！写一个程序来帮帮她吧。
 *  给你一个食物网，你要求出这个食物网中最大食物链的数量。（这里的“最大食物链”，指的是生物学意义上的食物链，即最左端是不会捕食其他生物的生产者，最右端是不会被其他生物捕食的消费者。）
 *  Delia 非常急，所以你只有 1秒的时间。由于这个结果可能过大，你只需要输出总数模上 80112002 的结果。
 *
 * Input:
 *  第一行，两个正整数 n、m，表示生物种类 n 和吃与被吃的关系数 m。
 *  接下来 m 行，每行两个正整数，表示被吃的生物A和吃A的生物B。
 *
 * Output:
 *  一行一个整数，为最大食物链数量模上80112002 的结果。
 *
 * Hints:
 *  1≤n≤5000, 1≤m≤500000。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 7
1 2
1 3
2 3
3 5
2 5
4 5
3 4
 *
 *  output:
5
 *
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 5010, MOD = 80112002;
int n, m, ind[N], outd[N], cnt[N], ans;
vector<int> g[N];

void topo_sort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!ind[i]) {
            q.push(i);
            cnt[i] = 1;
        }
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto y : g[x]) {
            cnt[y] = (cnt[y] + cnt[x]) % MOD;
            if (--ind[y] == 0)
                q.push(y);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        ind[b]++;
        outd[a]++;
    }
    topo_sort();
    for (int i = 1; i <= n; i++) {
        if (!outd[i]) {
            ans = (ans + cnt[i]) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}