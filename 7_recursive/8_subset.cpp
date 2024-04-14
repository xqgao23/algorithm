/**
 * Description:
 *  写一个递归函数，枚举n个数x1,…,xn中取若干个数的每种方法（子集枚举）. 对每种方法把取出的数从小到大排序，若两种方法中前k−1个数的选取情况相同，则取了第k个数的在前. 例如对n=4,X={100,20,3,4},应该按如下顺序给出结果
 *  {100,20,3,4},{100,20,3},{100,20,4},{100,20},{100,3,4},{100,3},{100,4},{100},{20,3,4},{20,3},{20,4},{20},{3,4},{3},{4},{}.
 *
 * Input:
 *  第一行一个正整数n
 *  第二行n个正整数, x1,...,xn.
 *
 * Output:
 *  输出2<n>行, 每行一个子集, 按题目要求顺序.
 *
 * Hints:
 *  1<=n<=12, 1<=xi<=10<7> 对于空集，需要输出一个空行
 */

/**
 *  Samples:
 *  1):
 *  input:
4
100 20 3 4
 *
 *  output:
100 20 3 4
100 20 3
100 20 4
100 20
100 3 4
100 3
100 4
100
20 3 4
20 3
20 4
20
3 4
3
4
 *
 */

#include <iostream>
using namespace std;
int n, a[20], p[20];

void dfs(int step)
{
    if (step > n) {
        for (int i = 1; i <= n; i++) {
            if (p[i]) {
                cout << a[i] << " ";
            }
        }
        cout << endl;
        return;
    }
    p[step] = 1;
    dfs(step + 1);
    p[step] = 0;
    dfs(step + 1);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1);
    return 0;
}