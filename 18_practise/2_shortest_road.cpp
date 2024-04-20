/**
 * Description:
 *  瓦西里有一个数a,他想把这个数变成b，为此他可以做两种变换.
 *  1.把现有的数x乘以p，变为px;
 *  2.把现有的数x增加q，变为x+q;
 *  例如a=2,b=104,p=3,q=5你可以以如下的方式把a变成b
 *  2 -> 6 -> 11 -> 33 -> 99 -> 104
 *  你需要帮瓦西里判断一下，把a变成b至少需要多少步变换。
 *
 * Input:
 *  1行，4个整数a,b,p,q
 *
 * Output:
 *  输出需要的最少变换次数；如果无法变成b，输出−1。
 *
 * Hints:
 *  1<=a<=b<=10<6>, 2<=p<=10<6>, 1<=q<=10<6>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2 105 2 6
 *
 *  output:
-1
 *
 *  1):
 *  input:
2 104 3 5
 *
 *  output:
5
 *
 */

#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 1e6 + 10;
int a, b, p, q, dis[N];

int bfs()
{
    queue<int> Q;
    memset(dis, -1, sizeof dis);
    Q.push(a);
    dis[a] = 0;
    while (Q.size()) {
        int x = Q.front();
        Q.pop();
        if (x == b) {
            return dis[x];
        }
        long long nx = 1ll * p * x;
        if (nx <= 1e6 && dis[nx] == -1) {
            Q.push(nx);
            dis[nx] = dis[x] + 1;
        }
        nx = x + q;
        if (nx <= 1e6 && dis[nx] == -1) {
            Q.push(nx);
            dis[nx] = dis[x] + 1;
        }
    }
    return -1;
}

int main()
{
    cin >> a >> b >> p >> q;
    cout << bfs() << endl;
    return 0;
}