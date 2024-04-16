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

#include <queue>
#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e6 + 10;
int a, b, k, dis[N];

int bfs()
{
    queue<int> q;
    memset(dis, -1, sizeof dis);
    q.push(a);
    dis[a] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (x == b) {
            return dis[b];
        }
        int nx = x - 1;
        if (nx >= 1 && dis[nx] == -1) {
            q.push(nx);
            dis[nx] = dis[x] + 1;
        }
        for (int t = 2; t <= k; t++) {
            nx = x - x % t;
            if (nx >= 1 && dis[nx] == -1) {
                q.push(nx);
                dis[nx] = dis[x] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    cin >> a >> b >> k;
    cout << bfs() << endl;
    return 0;
}