/**
 * Description:
 *  为了考验门派弟子的实力，昆仑派举行了青山大会，门派内顶尖的N位弟子为了自己的排位进行了一系列对决。在赛场上，N(1≤N≤100)位弟子按照1…N编号。每位弟子的实力各不相同，并且没有哪两位弟子的水平不相上下。也就是说，弟子们的实力有明确的排名。整个比赛分为了若干轮，其中每一轮都是两名指定编号的弟子之间的对决，如果编号为A的弟子实力比编号为B的弟子强，那么在他们的对决中，编号为A的弟子总是能胜出。
 *  现在，昆仑派掌门想知道弟子们实力的具体排名，于是他找来了M(1≤M≤4500)轮比赛的结果，希望你能根据这些信息，推断出尽可能多的弟子排名，比赛结果保证不会自相矛盾。
 *
 * Input:
 *  第一行2个空格隔开的整数：N,M。
 *  第2到M+1行，每行两个不同整数A,B表述某一轮比赛的弟子编号以及结果（编号为A的弟子胜利）。
 *
 * Output:
 *  仅一个整数，表示可以确定排名的弟子数目。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 5
4 3
4 2
3 2
1 2
2 5
 *
 *  output:
2
 *
 */

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
int n, m, vis[110], s[110], t[110], ans;
vector<int> g[110];

void dfs(int x, int st)
{
    if (vis[x]) {
        return;
    }
    vis[x] = 1;
    s[st]++; // 记录起点能到的点数(包括自己)
    t[x]++; //记录能到达x的点数(包括自己)
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        dfs(y, st);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] + t[i] == n + 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}