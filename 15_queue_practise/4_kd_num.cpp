/**
 * Description:
 *  一个只由 0∼9 数码组成的数,首位不为0,
 * 如果任意两个相邻数码之差的绝对值都不超过 d,则称这个数是一个"d好数"。
 *  给出d和k，输出从小到大排序的第k个d好数
 *
 * Input:
 *  1行，2个整数d，k
 *
 * Output:
 *  1个整数，表示第k个d好数
 *
 * Hints:
 *  1≤d≤9。1≤k≤10<5>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
1 100000
 *
 *  output:
3234566667
 *
 *  2):
 *  input:
1 15
 *
 *  output:
23
 *
 *  3):
 *  input:
5 308
 *
 *  output:
433
 *
 */

#include <iostream>
#include <queue>
using namespace std;
typedef long long LL;
int d, k, cnt;

LL bfs()
{
    queue<LL> q;
    for (int i = 1; i <= 9; i++) {
        q.push(i);
    }
    while (q.size()) {
        LL x = q.front();
        q.pop();
        if (++cnt == k) {
            return x;
        }
        int g = x % 10;
        for (int i = 0; i <= 9; i++) {
            if (abs(g - i) <= d) {
                LL nx = x * 10 + i;
                q.push(nx);
            }
        }
    }
    return 0;
}

int main()
{
    cin >> d >> k;
    cout << bfs() << endl;
    return 0;
}