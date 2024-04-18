/**
 * Description:
 *  大数学家高斯小时候偶然间发现一种有趣的自然数集合Blah，对于以a为基的集合Ba定义如下：
 *  (1)a是集合Ba的基，且a是Ba的第一个元素；
 *  (2)如果x在集合Ba中，则2x+1和3x+1也都在集合Ba中；
 *  (3)没有其他元素在集合Ba中了。
 *  现在小高斯想知道如果将集合Ba中元素按照升序排列，第n个元素会是多少？
 *
 * Input:
 *  输入只有一行,
 * 包括两个数字，以空格分隔，集合的基a(1≤a≤50)以及所求元素序号n(1≤n≤10<6>)
 *
 * Output:
 *  输出集合Ba的第n个元素值
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
1 100
 *
 *  output:
418
 *
 *  2):
 *  input:
28 5437
 *
 *  output:
900585
 *
 */

#include <iostream>
#include <queue>
using namespace std;
int n, a;
queue<int> q1, q2;

int main()
{
    cin >> a >> n;
    q1.push(2 * a + 1);
    q2.push(3 * a + 1);
    for (int i = 2; i <= n; i++) {
        a = min(q1.front(), q2.front());
        if (a == q1.front()) {
            q1.pop();
        }
        if (a == q2.front()) {
            q2.pop();
        }
        q1.push(2 * a + 1);
        q2.push(3 * a + 1);
    }
    cout << a << endl;
    return 0;
}