/**
 * Description:
 *  农夫约翰有N头奶牛，编号从1到N，打算进行叠罗汉的杂技表演。
 *  进行叠罗汉表演时，奶牛站在彼此的身上，形成一个有一定高度的垂直堆叠。
 *  奶牛们正在试图弄清楚它们在这个堆叠中的位置顺序。
 *  奶牛们有自己的重量Wi和力量Si，一头奶牛倒下的风险等于它身上所有奶牛（不包括它自己）的重量和减去它的力量。
 *  你的任务是确定奶牛的顺序，使奶牛的风险值中的最大值尽可能小。
 *
 * Input:
 *  第一行包括一个整数N，表示奶牛的数量，其中1≤N≤50000
 *  接下来N行，每行两个整数，表示奶牛的重量Wi和力量Si，其中1≤Wi≤10000 1≤Si≤10<9>
 *
 * Output:
 *  输出一个整数，表示最大风险值的最小可能值
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
10 3
2 5
3 3
 *
 *  output:
2
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
struct node {
    int w, s;
} p[50010];
int n;

bool cmp(node x, node y)
{
    return x.w + x.s < y.w + y.s;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].w >> p[i].s;
    }
    sort(p + 1, p + n + 1, cmp);
    int ans = -1e9, sum = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, sum - p[i].s);
        sum += p[i].w;
    }
    cout << ans << endl;
    return 0;
}