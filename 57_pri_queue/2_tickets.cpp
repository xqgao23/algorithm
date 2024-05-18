/**
 * Description:
 *  一个体育馆有m行座位，第i行有xi个空座位。
 *  售价的规则是：如果这一行还有k个空座，那么这行的座位的价格就是k元。
 *  体育馆想要把自己的票卖更多的钱，所以对每个前来买票的人，只会售出当前最贵的座位。
 *  现在有n个人排队来买票，问这n个人买票的总花费是多少？
 *
 * Input:
 *  第1行，两个数m,n
 *  第2行，m个数x1,x2,…,xm,表示每行的座位数。
 *
 * Output:
 *  输出n个人买票的总花费
 *
 * Hints:
 *  1≤m≤10<6>, 1≤n≤10<6>, 1≤xi≤10<6>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 4
1 2 4
 *
 *  output:
11
 *
 */

#include <iostream>
#include <queue>
using namespace std;
int m, n, x;
long long ans;
priority_queue<int> q;

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        q.push(x);
    }
    for (int i = 1; i <= n; i++) {
        int t = q.top();
        q.pop();
        ans += t;
        q.push(t - 1);
    }
    cout << ans << endl;
    return 0;
}