/**
 * Description:
 *  有 n 个人，他们的体重分别是 a1,
 * a2,…,an。有无数多艘船可以用，每艘船最多只能坐下总重量不超过 k 的人，且最多只能坐两人。要让 n 人全部坐到船上，最少需要多少艘船？
 *
 * Input:
 *  输入共 n+1 行：
 *  第 1 行，2 个用空格隔开的整数 n,k，表示人数和船的承重；
 *  之后 n 行，每行 1 个整数，分别表示 n 个人的体重。
 *
 * Output:
 *  输出共 1 行，1 个整数，为所求的最少船数
 *
 * Hints:
 *  1≤n≤200000; 1<=每个人的体重<=k
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
10 10
1
6
1
6
10
9
6
4
4
7
 *
 *  output:
6
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, k, a[200010];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        if (a[l] + a[r] <= k) {
            ans++;
            l++;
            r--;
        } else {
            ans++;
            r--;
        }
    }
    cout << ans << endl;
    return 0;
}