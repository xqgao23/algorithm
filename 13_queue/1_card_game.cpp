/**
 * Description:
 *  桌上有n张牌摞成一叠，从第一张牌（即位于顶面的牌）开始，从上往下依次编号为1∼n. 当至少还剩下两张牌时进行以下操作: 把最上面一张牌扔掉, 然后把新的最上面的牌放到整叠牌的最后.
 *  输入n,按顺序输出每次扔掉的牌和最后剩下的牌.
 *
 * Input:
 *  一个正整数n 1<=n<=50
 *
 * Output:
 *  输出两行
 *  第一行输出n−1个整数，用空格分隔，依次是每次扔掉的牌的编号
 *  第二行输出1个整数, 为最后剩下的牌的编号
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6
 *
 *  output:
1 3 5 2 6
4
 *
 *  2):
 *  input:
19
 *
 *  output:
1 3 5 7 9 11 13 15 17 19 4 8 12 16 2 10 18 14
6
 *
 */

#include <iostream>
#include <queue>

using namespace std;
int n;
queue<int> q;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (q.size() > 1) {
        cout << q.front() << " ";
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << endl << q.front() << endl;
    return 0;
}