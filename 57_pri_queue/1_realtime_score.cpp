/**
 * Description:
 *  某次体育赛事采用了一种奇怪的评分系统，评分系统支持以下几种操作：
 *  （1）一名评委给出自己的分数。用字符串score跟着一个数字si表示，si表示分数，score和si之间有一个空格。
 *  （2）去掉当前所有分数中最高的一个。用字符串delete表示。
 *  （3）计算当前所有分数的平均分。用字符串display表示。
 *  一共会有m次操作。对于所有display操作，输出当前所有分数的平均分，四舍五入保留3位小数。
 *
 * Input:
 *  第一行一个正整数m；
 *  接下来m行，每行一个操作。
 *
 * Output:
 *  对于每个display操作，输出当前所有分数的平均分。
 *  以浮点数形式输出，保留3位小数，四舍五入。
 *
 * Hints:
 *  1≤m≤100000, 1≤si≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
score 6
score 5
delete
score 1
display
 *
 *  output:
3.000
 *
 *  2):
 *  input:
5
1 1 0 0 0
 *
 *  output:
0
 *
 */

#include <iostream>
#include <queue>
using namespace std;
int n, x;
long long sum;
string s;
priority_queue<int> q;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (s == "score") {
            cin >> x;
            q.push(x);
            sum += x;
        } else if (s == "delete") {
            sum -= q.top();
            q.pop();
        } else {
            printf("%.3lf\n", 1.0 * sum / q.size());
        }
    }
    return 0;
}