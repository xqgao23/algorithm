/**
 * Description:
 *  农夫知道一头牛的位置，想要抓住它。农夫和牛都位于数轴上，农夫起始位于点N(0≤N≤100000)，牛位于点K(0≤K≤100000)。农夫有两种移动方式：1、从X移动到X−1或X+1，每次移动花费一分钟2、从X移动到2×X，每次移动花费一分钟假设牛没有意识到农夫的行动，站在原地不动。农夫最少要花多少时间才能抓住牛？
 *
 * Input:
 *  两个整数，N，K
 *
 * Output:
 *  一个整数，农夫抓到牛所要花费的最小分钟数。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 17
 *
 *  output:
4
 *
 */

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int N = 1e5 + 10;
int n, k, dis[N];

int bfs()
{
    queue<int> q;
    memset(dis, -1, sizeof dis);
    q.push(n);
    dis[n] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (x == k) {
            return dis[k];
        }
        int nx = x + 1;
        if (nx <= 100000 && dis[nx] == -1) {
            q.push(nx);
            dis[nx] = dis[x] + 1;
        }
        nx = x - 1;
        if (nx >= 1 && dis[nx] == -1) {
            q.push(nx);
            dis[nx] = dis[x] + 1;
        }
        nx = 2 * x;
        if (nx <= 100000 && dis[nx] == -1) {
            q.push(nx);
            dis[nx] = dis[x] + 1;
        }
    }
    return -1;
}

int main()
{
    cin >> n >> k;
    cout << bfs() << endl;
    return 0;
}