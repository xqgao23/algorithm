/**
 * Description:
 *  有 n 个容量无穷大的水壶，它们从 1∼n 编号，初始时 i 号水壶中装有 Ai 单位的水。
 *  你可以进行不超过 k 次操作，每次操作需要选择一个满足 1≤x≤n−1 的编号 x，然后把 x 号水壶中的水全部倒入 x+1 号水壶中。
 *  最后你可以任意选择恰好一个水壶，并喝掉水壶中所有的水。现在请你求出，你最多能喝到多少单位的水。
 *
 * Input:
 *  第一行一个正整数 n，表示水壶的个数。
 *  第二行一个非负整数 k，表示操作次数上限。
 *  第三行 n 个非负整数，相邻两个数用空格隔开，表示水壶的初始装水量 A1,A2,…,An
 *
 * Output:
 *  输出共1行：
 *  第1行，1个正整数，为黑先生最少需要付的工资
 *
 * Hints:
 *  1≤n≤10<6>, 0≤k≤n−1，0≤Ai≤10<3>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
10
5
890 965 256 419 296 987 45 676 976 742
 *
 *  output:
3813
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, k, a[1000010], s[1000010];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = k + 1; i <= n; i++) {
        ans = max(ans, s[i] - s[i - k - 1]);
    }
    cout << ans << endl;
    return 0;
}