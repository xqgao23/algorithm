/**
 * Description:
 *  依次读入一个整数序列，每当已经读入的整数个数为奇数时，输出已读入的整数构成的序列的中位数。
 *
 * Input:
 *  第一行一个整数N(1≤N≤10<5>)，表示序列长度。
 *  第二行N个整数Ai(1≤Ai≤10<9>)
 *
 * Output:
 *  输出⌊(N+1)/2⌋行（向下取整），第i行为A1到A2i-1的中位数。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
7
1 3 5 7 9 11 6
 *
 *  output:
1
3
5
6
 *
 */

#include <iostream>
#include <queue>
using namespace std;
int n, x;
priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int> > q2;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        q1.push(x);
        if (q1.size() > q2.size() + 1) {
            q2.push(q1.top());
            q1.pop();
        }
        if (q2.size() && q1.top() > q2.top()) {
            int a = q1.top();
            q1.pop();
            int b = q2.top();
            q2.pop();
            q1.push(b);
            q2.push(a);
        }
        if (i & 1) {
            cout << q1.top() << endl;
        }
    }
    return 0;
}