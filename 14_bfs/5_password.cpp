/**
 * Description:
 *  保险箱使用一个s位数字密码锁，从左至右记为第1∼s位，每个数字都是0∼9的整数。我们用一个整数x表示当前显示的s位数字（可能含有前导0），例如，如果s=6，1026表示001026。每次操作密码锁的方法有以下几种：
 *  （1）将x的第2∼s位向前移动一位，第1位移动到第s位。
 *  （2）将x变为x×k，其中2≤k≤t。如果得到的数超过s位，只保留最后s位。
 *  密码锁的初始状态只有第s位是1，第1∼s−1位都是0，能打开密码锁的密码用一个s位数p表示.
 * s,t由输入给出，问将p设为什么密码时，从初始状态出发，开锁需要的操作次数最多？如果有多种密码p需要最多操作次数，输出其中最小的p。
 *  例如s=2,t=9时，一种操作密码锁的方式如下：
 *  01 —x5—>05—x7—>35—移位—>53—x9—>77—x9—>93—x9—>37—x3—>11
 *  如果设置密码为11，至少需要7次操作。
 *
 * Input:
 *  两个整数s，t
 *
 * Output:
 *  输出一个s位数p，不足s位要补零
 *
 * Hints:
 *  2<=s<=6, 2<=t<=100
 */

/**
 *  Samples:
 *  1):
 *  input:
2 9
 *
 *  output:
11
 *
 */

#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
const int N = 1e6 + 10;
int s, t, m = 1, dis[N];

void bfs()
{
    queue<int> q;
    memset(dis, -1, sizeof dis);
    q.push(1);
    dis[1] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        int nx = x % (m / 10) * 10 + x / (m / 10);
        if (dis[nx] == -1) {
            q.push(nx);
            dis[nx] = dis[x] + 1;
        }
        for (int k = 2; k <= t; k++) {
            nx = x * k % m;
            if (dis[nx] == -1) {
                q.push(nx);
                dis[nx] = dis[x] + 1;
            }
        }
    }
}

int main()
{
    cin >> s >> t;
    for (int i = 1; i <= s; i++) {
        m *= 10;
    }
    bfs();
    int p, cnt = 0;
    for (int i = 0; i < m; i++) {
        if (dis[i] > cnt) {
            cnt = dis[i];
            p = i;
        }
    }
    printf("%0*d\n", s, p);
    return 0;
}