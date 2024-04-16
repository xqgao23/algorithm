/**
 * Description:
 *  给出三个数a，b，k。
 *  有两种变换方式：
 *  	•	把a变成a−1
 *  	•	把a变成a−a%t，其中22≤t≤k, a%t表示a除以t的余数
 *  求a至少要经过几次变换才能变到b
 *
 * Input:
 *  3个正整数a, b, k
 *
 * Output:
 *  输出最少变换次数
 *
 * Hints:
 *  1<=b<=a<10<6>, 2<=k<=15
 */

/**
 *  Samples:
 *  1):
 *  input:
10 1 4
 *
 *  output:
6
 *
 *  2):
 *  input:
6 3 10
 *
 *  output:
2
 *
 */

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
long long a, b, k, m = 1;
bool vis[1000010];
struct node {
    int x, c;
};

int gcd(int x, int y)
{
    return x % y == 0 ? y : gcd(y, x % y);
}

int lcm(int x, int y)
{
    return x / gcd(x, y) * y;
}

int bfs(int x, int y)
{
    queue<node> q;
    memset(vis, 0, sizeof vis);
    node tt = {x, 0};
    q.push(tt);
    vis[x] = true;
    while (q.size()) {
        int now_x = q.front().x, now_c = q.front().c;
        q.pop();
        if (now_x == y) {
            return now_c;
        }
        int next_x = now_x - 1, next_c = now_c + 1;
        if (next_x >= 0 && !vis[next_x]) {
            node temp = {next_x, next_c};
            q.push(temp);
            vis[next_x] = 1;
        }
        for (int t = 2; t <= k; t++) {
            next_x = now_x - now_x % t;
            if (next_x >= 0 && !vis[next_x]) {
                node temp = {next_x, next_c};
                q.push(temp);
                vis[next_x] = true;
            }
        }
    }
    return 0;
}

int main()
{
    cin >> a >> b >> k;
    for (int i = 2; i <= k; i++) {
        m = lcm(m, i);
    }
    long long ans;
    if (a / m == b / m) {
        ans = bfs(a % m, b % m);
    } else {
        ans = bfs(a % m, 0) + (a / m - b / m - 1) * bfs(m, 0) + bfs(m, b % m);
    }
    cout << ans << endl;
    return 0;
}