/**
 * Description:
 *  小 A 有 n 个糖果盒，第 i 个盒中有 ai 颗糖果。
 *  小 A
 * 每次可以从其中一盒糖果中吃掉一颗，他想知道，要让任意两个相邻的盒子中糖的个数之和都不大于 x，至少得吃掉几颗糖。
 *
 * Input:
 *  输入的第一行是两个用空格隔开的整数，代表糖果盒的个数 n 和给定的参数 x。
 *  第二行有 n 个用空格隔开的整数，第 i 个整数代表第 i 盒糖的糖果个数 ai
 *
 * Output:
 *  输出一行一个整数，代表最少要吃掉的糖果的数量。
 *
 * Hints:
 *  2≤n≤10<5>, 0≤ai,x≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6 1
1 6 1 2 0 4
 *
 *  output:
11
 *
 */

#include <iostream>
using namespace std;
int n, x, a[100010];
long long ans;

int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] + a[i - 1] > x) {
            int t = a[i] + a[i - 1] - x;
            a[i] -= t;
            ans += t;
        }
    }
    cout << ans << endl;
    return 0;
}