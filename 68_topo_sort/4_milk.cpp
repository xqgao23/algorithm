/**
 * Description:
 *  Farmer John的N头奶牛（1≤N≤10<5>），仍然编号为1…N，正好闲得发慌。因此，她们发展了一个与Farmer John每天早上为她们挤牛奶的时候的排队顺序相关的复杂的社会阶层。
 *  经过若干周的研究，Farmer John对他的奶牛的社会结构总计进行了M次观察（1≤M≤50,000）。每个观察结果都是他的某些奶牛的一个有序序列，表示这些奶牛应该以与她们在序列中出现的顺序相同的顺序进行挤奶。比方说，如果Farmer John的一次观察结果是序列2、5、1，Farmer John应该在给奶牛5挤奶之前的某个时刻给奶牛2挤奶，在给奶牛1挤奶之前的某个时刻给奶牛5挤奶。
 *  Farmer John的观察结果是按优先级排列的，所以他的目标是最大化X的值，使得他的挤奶顺序能够符合前X个观察结果描述的状态。当多种挤奶顺序都能符合前X个状态时，Farmer John相信一个长期以来的传统——编号较小的奶牛的地位高于编号较大的奶牛，所以他会最先给编号最小的奶牛挤奶。更加正式地说，如果有多个挤奶顺序符合这些状态，Farmer John会采用字典序最小的那一个。挤奶顺序x的字典序比挤奶顺序y要小，如果对于某个j, xi = yi 对所有i≤j成立，并且xj <= yj （也就是说，这两个挤奶顺序到某个位置之前都是完全相同的，在这个位置上x比y要小）。
 *  请帮助Farmer John求出为奶牛挤奶的最佳顺序。
 *
 * Input:
 *  第一行包含N和M。接下来的M行，每行描述了一个观察结果。第i+1行描述了观察结果i，第一个数是观察结果中的奶牛数量mi ，后面是一列mi 个整数，给出这次观察中奶牛的顺序。所有mi 的和至多为200,000。
 *
 * Output:
 *  输出N个空格分隔的整数，给出一个1…N的排列，为Farmer John给他的奶牛们挤奶应该采用的的顺序。
 * 
 *  Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 3
3 1 2 3
2 4 2
3 3 4 1
 *
 *  output:
1 4 2 3
 *
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int n, m, rud[N], ans[N], cnt;
vector<int> g[N], p[N];

void build(int mid)
{
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        rud[i] = 0;
        g[i].clear();
    }
    for (int i = 1; i <= mid; i++)
        for (auto j = 0; j < p[i].size() - 1; j++) {
            g[p[i][j]].push_back(p[i][j + 1]);
            rud[p[i][j + 1]]++;
        }
}

bool check(int mid)
{
    build(mid);
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (rud[i] == 0)
            q.push(i);
    while (q.size()) {
        int x = q.front();
        q.pop();
        cnt++;
        for (auto y : g[x])
            if (--rud[y] == 0)
                q.push(y);
    }
    return cnt == n;
}

void topo_sort(int mid)
{
    build(mid);
    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
        if (rud[i] == 0)
            q.push(-i);
    while (q.size()) {
        int x = -q.top();
        q.pop();
        ans[++cnt] = x;
        for (auto y : g[x])
            if (--rud[y] == 0)
                q.push(-y);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int mi, x;
        cin >> mi;
        for (int j = 1; j <= mi; j++) {
            cin >> x;
            p[i].push_back(x);
        }
    }
    int l = 1, r = m, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    topo_sort(l);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
    return 0;
}
