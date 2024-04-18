/**
 * Description:
 *  某城市有一个火车站，铁轨铺设如图所示。有 n 节车厢从A方向驶入车站，按进站顺序编号为 1∼n 。你的任务是判断能否让它们按照某种特定顺序进入B方向的铁轨并驶出车站。例如，出栈顺序 (5,4,1,2,3) 是不可能的，但 (5,4,3,2,1) 是可能的。
 *  为了重组车厢，你可以借助中转站C。这是一个可以停放任意多节车厢的车站，但由于末端被封死，驶入C的车厢必须按照相反的顺序驶出C。对于每个车厢，一旦进入C就不能再回到A了；一旦从C移入B，也不能再回到C了。换句话说，车厢的移动只能从A到C或者从C到B。
 *
 * Input:
 *  第1行，1个正整数 Q。
 *  接下来 Q 行，每行第 1 个数 n 表示车厢数量，接下来 n 个数 a1,a2,…,an 表示出站顺序。
 *
 * Output:
 *  输出 Q 行，对每组数据，用一行输出 Yes 或 No。
 *
 * Hints:
 *  1<=Q<=10, 1<=n<=10000, a1,a2,...,an是1-n的一个排列
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2
5 5 4 1 2 3
5 5 4 3 2 1
 *
 *  output:
No
Yes
 *
 */

#include <iostream>
#include <stack>

using namespace std;
int q, n, a[10010];

bool check()
{
    stack<int> st;
    int x = 1;
    for (int i = 1; i <= n; i++) {
        if (x <= a[i]) {
            while (x <= a[i]) {
                st.push(x);
                x++;
            }
        }
        if (st.top() == a[i]) {
            st.pop();
        } else {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (check()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}