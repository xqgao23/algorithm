/**
 * Description:
 *  有一个函数 f(x)，初始是一个常数函数 f(x)=0。你要处理 Q 个任务，每个任务都是以下两种中的一种：
 *  （1）更新 1 a b：给你两个整数 a,b，定义 g(x)=f(x)+∣x−a∣+b。然后用 g(x) 替换 f(x)。
 *  （2）求值 2：输出使得 f(x) 取最小值的 x，和 f(x) 的最小值。如果有多个 x 可以使 f(x) 取到最小，取其中最小的 x。
 *  可以证明，求值时的输出一定是整数。
 *
 * Input:
 *  第1行，1个正整数 Q。
 *  接下来 Q 行，每行一个任务。第1个数表示任务种类，1表示更新，2表示求值。对于更新操作，后面还会有两个整数 a,b。
 *
 * Output:
 *  对每个求值操作，用一行输出两个整数，用空格隔开。分别表示使得 f(x) 取最小值的 x，和 f(x) 的最小值。如果有多个x 可以使 f(x) 取到最小，取其中最小的 x。
 *
 * Hints:
 *  1≤Q≤2*10<5>,-10<9>≤a,b≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
1 4 2
2
1 1 -8
2
 *
 *  output:
4 2
1 -3
 *
 *  2):
 *  input:
4
1 -1000000000 1000000000
1 -1000000000 1000000000
1 -1000000000 1000000000
2
 *
 *  output:
-1000000000 3000000000
 *
 */

// 100分
#include <iostream>
#include <queue>
using namespace std;
typedef long long LL;
LL n, sum1, sum2, sumb;
priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int> > q2;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int op, a, b;
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            sumb += b;
            sum1 += a;
            q1.push(a);
            if (q1.size() > q2.size() + 1) {
                q2.push(q1.top());
                sum1 -= q1.top();
                sum2 += q1.top();
                q1.pop();
            }
            if (q2.size() && q1.top() > q2.top()) {
                int x = q1.top();
                q1.pop();
                int y = q2.top();
                q2.pop();
                q1.push(y);
                q2.push(x);
                sum1 += y - x;
                sum2 += x - y;
            }
        } else {
            int x = q1.top();
            LL y = q1.size() * x - sum1 + sum2 - q2.size() * x + sumb;
            cout << x << " " << y << endl;
        }
    }
    return 0;
}