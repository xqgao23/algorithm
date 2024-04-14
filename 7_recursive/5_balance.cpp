/**
 * Description:
 *  你有5个重量不同的砝码和一个天平, 每个砝码可以放在左盘或者右盘或者不放.
 *  砝码重量为w1,w2,w3,w4,w5
 *  问有多少种放置砝码的方式，使得天平平衡?
 * （两边都不放任何砝码也算一种平衡方式）
 *
 * Input:
 *  一行, 5个正整数w1,w2,w3,w4,w5, 以空格分隔
 *
 * Output:
 *  输出使得天平平衡的放置方案数.
 *
 * Hints:
 *  1<=wi<=100
 */

/**
 *  Samples:
 *  1):
 *  input:
1 2 3 5 6
 *
 *  output:
13
 *
 */

#include <iostream>
using namespace std;
int n, w[20], p[20], ans;

void dfs(int step)
{
    if (step > n) {
        int cha = 0;
        for (int i = 1; i <= n; i++) {
            cha += p[i] * w[i];
        }
        if (cha == 0) {
            ans++;
        }
        return;
    }
    for (int i = -1; i <= 1; i++) {
        p[step] = i;
        dfs(step + 1);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}