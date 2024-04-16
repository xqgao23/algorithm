/**
 * Description:
 *  河面上有N个木桩排成一排，且每个木桩上都有一个数字，木桩上的数字表示青蛙从当前木桩一次最多可跳跃的木桩个数（例如木桩上的数字为2，青蛙可以跳跃一个木桩也可以跳跃两个木桩）。青蛙只能从第一个木桩向最后一个木桩的方向跳跃。请你帮助青蛙计算出从第一个木桩跳跃到最后一个木桩最少需要跳跃几次。
 *  例如：N=5，5个木桩上的数字分别为2，1，5，1，3。
 *  第一次跳跃，青蛙从第一个木桩跳跃到第三个木桩，共跳了2个木桩；
 *  第二次跳跃，青蛙从第三个木桩跳跃到最后一个木桩，共跳了2个木桩；
 *  故最少需要跳跃2次可到达最后一个木桩。
 *
 * Input:
 *  第1行，1个正整数N
 *  第2行，N个正整数a1,a2,…,aN，表示每个木桩上的数
 *
 * Output:
 *  输出1个数，表示最少跳跃次数。
 *
 * Hints:
 *  1<=N<=10<5> 1<=ai<=100
 */

/**
 *  Samples:
 *  1):
 *  input:
5
2 1 5 1 3
 *
 *  output:
2
 *
 *  2):
 *  input:
10
4 1 3 4 3 4 3 3 3 2
 *
 *  output:
3
 *
 *  3):
 *  input:
17
2 1 4 3 1 1 1 1 6 5 1 1 2 3 2 4 1
 *
 *  output:
6
 *
 */

#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
const int N = 1e5 + 10;
int n, a[N], dis[N];

int bfs()
{
    queue<int> q;
    memset(dis, -1, sizeof dis);
    q.push(1);
    dis[1] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (x == n) {
            return dis[n];
        }
        for (int i = 1; i <= a[x]; i++) {
            int nx = x + i;
            if (nx <= 1e5 && dis[nx] == -1) {
                q.push(nx);
                dis[nx] = dis[x] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << bfs() << endl;
    return 0;
}