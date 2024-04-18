/**
 * Description:
 *  小猴顺利从清洗餐盘的工作过渡到了给餐盘消毒的工作！
 *  开始时，没有待消毒餐盘，之后会发生两种事件：
 *  1.一个新的待消毒餐盘加入：用一个正整数 a 表示，代表将一个餐盘放在餐盘顶端，且这个餐盘消毒完成需要的"消毒时间"是 a ；
 *  2.餐盘消毒：用一个负整数 b 表示，代表皮皮进行 ∣b∣ 分钟消毒。皮皮取出顶端餐盘，对它持续消毒，直到达到这个餐盘需要的"消毒时间"，然后再去拿下一个餐盘。如果没有餐盘了，就进入下一个事件。
 *  因为只能消毒 ∣b∣ 分钟，最后一个餐盘可能无法消毒足够的时间，那么这个餐盘要放回顶端，它所需的"消毒时间"要减去已经消毒的时间。
 *  两种事件一共发生了 n 次，请输出每次消毒完成的餐盘数量。
 *
 * Input:
 *  第 1 行，一个正整数 n ，为事件发生的次数；
 *  第 2
 * 行， n 个整数 x1,x2,…,xn 。若 xi>0 ，表示一个需要消毒 xi 分钟的餐盘放在餐盘顶端；若 xi<0 ，表示对餐盘顶端持续消毒 |xi∣|分钟。
 *
 * Output:
 *  对每次消毒，输出1行，每行包含一个整数，表示每次消毒完成的餐盘数量。
 *
 * Hints:
 *  1<=n<=1000; |xi|<=10<4>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
8
7 2 1 -6 5 -4 1 -8
 *
 *  output:
2
0
3
 *
 */

#include <iostream>
#include <stack>
using namespace std;
int n;
stack<int> st;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (a > 0) {
            st.push(a);
        } else {
            int cnt = 0, b = -a;
            while (st.size()) {
                if (b >= st.top()) {
                    b -= st.top();
                    cnt++;
                    st.pop();
                } else {
                    int x = st.top() - b;
                    st.pop();
                    st.push(x);
                    break;
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}