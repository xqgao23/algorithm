/**
 * Description:
 *  考虑x轴上的点组成的集合S，你需要写一个数据结构，支持以下操作：
 *  （1）+ x：添加一个坐标为x的点到集合S中。
 *  （2）- n：删除第n次添加的点，添加操作按顺序从1编号，其他操作不参与计数。
 *  （3）? x：计算S集合中，与x的距离最大的点的距离，保证询问时，集合S中，至少有一个点。
 *  两个点x1和x2的距离等于坐标之差的绝对值：|x1-x2∣。
 *
 * Input:
 *  第 1 行，1 个正整数 Q，表示操作的总数。
 *  接下来 Q 行，每行包含一条操作。
 *
 * Output:
 *  对每个询问操作，输出最大的距离。
 *
 * Hints:
 *  1≤Q≤2×10<5>
 *  −10<9>≤x≤10<9>, 1≤n≤ 添加操作次数
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
+ 8
+ -1
? 5
- 2
? -100
 *
 *  output:
6
108
 *
 *  2):
 *  input:
6
+ 5
? 2
+ 999999999
+ -3
- 2
? 2
 *
 *  output:
3
5
 *
 */

#include <cmath>
#include <iostream>
#include <queue>
using namespace std;
struct node {
    int id, x;
    bool operator<(const node &_) const
    {
        return x < _.x;
    }
};

int n, ans, cnt, f[200010];
priority_queue<node> q1, q2;

int main()
{
    cin >> n;
    while (n--) {
        char op;
        int x;
        cin >> op >> x;
        if (op == '+') {
            node t = {++cnt, x};
            node tt = {cnt, -x};
            q1.push(t);
            q2.push(tt);
        } else if (op == '-') {
            f[x] = 1;
        } else {
            while (f[q1.top().id]) {
                q1.pop();
            }
            ans = abs(q1.top().x - x);
            while (f[q2.top().id]) {
                q2.pop();
            }
            ans = max(ans, abs(x + q2.top().x));
            cout << ans << endl;
        }
    }
    return 0;
}