/**
 * Description:
 *  呵呵，有一天我做了一个梦，梦见了一种很奇怪的电梯。大楼的每一层楼都可以停电梯，而且第i层楼(1≤i≤N)有一个数字ki(0≤Ki≤N)。电梯只有四个按钮：开，关，上，下。上下的层数等于当前楼层上的那个数字。当然，如果不能满足要求，相应的按钮就会失灵。例如：3,3,1,2,5代表了Ki(K1=3,K2=3,...)，从1楼开始。在1楼，按"上"可以到4楼，按"下"是不起作用的，因为没有−2楼。那么，从A楼到B楼至少要按几次按钮呢？
 *
 * Input:
 *  共二行。
 *  第一行为3个用空格隔开的正整数，表示N,A,B(1≤N≤200,1≤A,B≤N)。
 *  第二行为N个用空格隔开的非负整数，表示Ki
 *
 * Output:
 *  一行，即最少按键次数，若无法到达，则输出−1。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 1 5
3 3 1 2 5
 *
 *  output:
3
 *
 */

#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
int n, a, b, k[210], dis[210];

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
        int nx = x + k[x];
        if (nx <= n && dis[nx] == -1) {
            q.push(nx);
            dis[nx] = dis[x] + 1;
        }
        nx = x - k[x];
        if (x >= 1 && dis[nx] == -1) {
            q.push(nx);
            dis[nx] = dis[x] + 1;
        }
    }
    return -1;
}

int main()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    cout << bfs() << endl;
    return 0;
}