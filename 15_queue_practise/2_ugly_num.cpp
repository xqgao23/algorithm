/**
 * Description:
 *  对于一给定的素数集合 S={p1,p2,…,pk},
 * 考虑一个正整数集合，该集合中任一元素的质因数全部属于S。这个正整数集合包括，p1,
 * p1*p2,p1*p1,p1*p2*p3 ...（还有其它）。该集合被称为 S 集合的"丑数集合"。注意：我们认为 1不是一个丑数。
 *  你的工作是对于输入的集合 S 去寻找"丑数集合"中的第 n 个"丑数"。
 *  补充：丑数集合中每个数从小到大排列，每个丑数都是素数集合中的数的乘积，第 n 个"丑数"就是在能由素数集合中的数相乘得来的（包括它本身）第 n 小的数。
 *
 * Input:
 *  输入的第一行是两个的整数，分别代表集合 S 的大小 k 和给定的参数 n。
 *  输入的第二行有 k 互不相同的整数，第 i 个整数代表 p_i。
 *
 * Output:
 *  输出一行一个整数，代表答案。
 *
 * Hints:
 *  1≤k≤100。1≤n≤10<5>, 2<=pi<2<31>，且 pi 一定为质数。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 19
2 3 5 7
 *
 *  output:
27
 *
 */

#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int k, n, p[110], s;
queue<int> q[110];

int main()
{
    cin >> k >> n;
    for (int i = 1; i <= k; i++) {
        cin >> p[i];
        q[i].push(p[i]);
    }
    for (int i = 1; i <= n; i++) {
        s = 2e9;
        for (int j = 1; j <= k; j++) {
            s = min(s, q[j].front());
        }
        for (int j = 1; j <= k; j++) {
            if (q[j].front() == s) {
                q[j].pop();
            }
            q[j].push(s * p[j]);
        }
    }
    cout << s << endl;
    return 0;
}