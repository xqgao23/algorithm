/**
 * Description:
 *  某部队进行新兵队列训练，将新兵从一开始按顺序依次编号，并排成一行横队。
 *  训练的规则如下：从队列头部开始从一至二报数，凡报到二的出列，剩下的向编号小的方向靠拢。再从队列头开始进行一至三报数，凡报到三的出列，剩下的编号小的方向靠拢。继续从头开始进行一至二报数......
 *  以后从头开始轮流进行一至二报数、一至三报数直到剩下的人数不超过三人为止
 *
 * Input:
 *  第一行包含一个整数T(1≤T≤100)，表示一共有T组测试用例。
 *  接下来T行，每行一个整数n(1≤n≤5000)，表示有n个新兵。
 *
 * Output:
 *  对于每个测试用例输出一行，每行输出剩下的新兵的编号，编号之间用一个空格隔开。
 *
 * Hints:
 *  1≤T≤100，1≤n≤5000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
2
4
20
40
 *
 *  output:
1 2
1 3
1 7 19
1 19 37
 *
 */

#include <iostream>
#include <list>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        list<int> ls;
        for (int i = 1; i <= n; i++) {
            ls.push_back(i);
        }
        int k = 2;
        while (ls.size() > 3) {
            int c = 0;
            for (auto it = ls.begin(); it != ls.end(); it++) {
                if (++c % k == 0) {
                    it = ls.erase(it);
                    it--;
                }
            }
            k = 5 - k;
        }
        for (auto it : ls) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}