/**
 * Description:
 *  皮皮又在清洗餐盘！这次为了让餐盘的清洗工作尽快结束，皮皮会一次清洗多个餐盘！开始时，没有待清洗餐盘，之后会发生两种事件：
 *  	1.
 * 一个需要清洗的餐盘：将编号为a 的餐盘放在这叠餐盘顶端。用一个字符串 dish
 * 和一个正整数a 表示，dish 和a 之间有一个空格。 2.
 * 清洗餐盘：清洗顶端的k 个餐盘。如果餐盘数量大于k 个，小猴取出顶端k 个餐盘，并按照取出的顺序依次清洗；如果餐盘数量少k 个，小猴就取出所有餐盘并依次清洗。用一个字符串
 * wash 和一个正整数k 表示，wash 和 k 之间有一个空格。保证 wash 操作时至少有 1
 * 个餐盘可以洗。 两种事件一共发生了 n 次，对每次 wash
 * 操作，输出此次清洗的餐盘编号。
 *
 * Input:
 *  第 1 行，一个正整数 n，为事件发生了次数；
 *  接下来 n 行，每行表示一个事件，格式见题目描述。
 *
 * Output:
 *  对每次 wash
 * 操作，用一行输出此次清洗的所有餐盘编号。餐盘编号按照清洗顺序输出，数之间用空格分隔。
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
wash 2
dish 4
dish 5
wash 3
 *
 *  output:
3 2
5 4 1
 *
 *  2):
 *  input:
5
dish 2
dish 1
wash 3
dish 3
wash 1
 *
 *  output:
1 2
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
        string op;
        cin >> op;
        if (op == "dish") {
            int x;
            cin >> x;
            st.push(x);
        } else {
            int k;
            cin >> k;
            for (int j = 1; st.size() && j <= k; j++) {
                cout << st.top() << " ";
                st.pop();
            }
            cout << endl;
        }
    }
    return 0;
}