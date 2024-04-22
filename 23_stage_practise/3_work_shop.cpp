/**
 * Description:
 *  你被任命为AtCoder王国的问题工房的管理官，得意忘形的你接下了很多工作。
 *  以现在的时刻为0时刻，你接下了N个工作，编号1∼N。完成第i个工作需要Ai时间，并且最后完成期限是Bi时刻（恰好在时刻Bi完成也可以）。你不能同时做两件或更多的工作，但是可以完成一件工作后，立刻开始下一件工作。
 *  请编程判断所有工作能否在各自的最后期限内完成。
 *
 * Input:
 *  输入包含多组数据
 *  第1行，1个正整数T，表示有T组数据
 *  每一组数据包含3行：
 *  第1行，1个正整数N
 *  第2行，N个整数A1,A2,...,AN.
 *  第3行，N个整数B1,B2,...,BN.
 *
 * Output:
 *  对每组数据，用一行输出结果。如果能在各自的最后期限内完成所有工作，输出Yes；否则输出No。
 *
 * Hints:
 *  1≤T≤5, 1≤N≤2×10<5>
 *  1≤Ai,Bi≤10<9>(1≤i≤N)
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2
5
2 1 1 4 3
4 9 8 9 12
3
334 334 334
1000 1000 1000
 *
 *  output:
Yes
No
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int T, n;
struct node {
    int a, b;
} p[200010];

bool cmp(node x, node y) { return x.b < y.b; }

bool check()
{
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += p[i].a;
        if (sum > p[i].b) {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i].a;
        }
        for (int i = 1; i <= n; i++) {
            cin >> p[i].b;
        }
        sort(p + 1, p + n + 1, cmp);
        if (check()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}