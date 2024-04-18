/**
 * Description:
 *  皮皮在大排档兼职洗碗工，他身边有一堆餐盘要洗。客人们吃完饭之后，要洗的盘子会放在这叠餐盘的顶端，而皮皮洗盘子的时候总会取出这叠餐盘最顶上的盘子来洗。开始时，没有待清洗餐盘，之后会发生两种事件：
 *	1.	一个需要清洗的餐盘：将编号a 的餐盘放在这叠餐盘顶端。用一个字符串
 *dish 和一个a 表示，dish 和a 之间有一个空格。 2.
 *清洗餐盘：清洗顶端的一个餐盘。用一个字符串 wash 表示。保证 wash
 *操作时一定有餐盘可以洗。 两种事件一共发生了 n 次，对每次 wash
 *操作，输出每次清洗的餐盘编号
 *
 * Input:
 *  第 1 行，一个正整数 n，为事件发生了次数；
 *  接下来 n 行，每行表示一个事件，格式见题目描述。
 *
 * Output:
 *  对每次 wash 操作，用一行输出清洗的餐盘编号。
 *
 * Hints:
 *  1<=n<=1000; 1<=a<=10<6>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
7
dish 1
dish 2
dish 3
wash
dish 4
wash
dish 5
 *
 *  output:
3
4
 *
 *  2):
 *  input:
5
dish 3
dish 2
dish 1
wash
wash
 *
 *  output:
1
2
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
        string op;
        cin >> op;
        if (op == "dish") {
            int x;
            cin >> x;
            st.push(x);
        } else {
            cout << st.top() << endl;
            st.pop();
        }
    }
    return 0;
}