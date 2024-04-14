/**
 * Description:
 *  小猴有n种面值不同的钱币，具体地说，小猴有面值w1的钱币c1个，面值w2的钱币c2个,...,面值wn的钱币cn个.
 *  小猴想知道用手中的钱币，恰好凑出m的方法有多少种?
 *
 * Input:
 *  第1行两个正整数n,m,用空格分隔
 *  第2行n个正整数w1,w2,…,wn
 *  第3行n个正整数c1,c2,..,cn
 *
 * Output:
 *  一个整数, 恰好凑出m的方法数
 *
 * Hints:
 *  1≤n≤10;1≤m,wi<=10<6>互不相同;1≤ci≤5;
 */

/**
 *  Samples:
 *  1):
 *  input:
3 10
1 2 4
3 3 3
 *
 *  output:
4
 *
 */

#include <iostream>
using namespace std;
int n, m, w[20], c[20], p[20], ans;

void dfs(int step)
{
    if (step > n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += w[i] * p[i];
        }
        if (sum == m) {
            ans++;
        }
        return;
    }
    for (int i = 0; i <= c[step]; i++) {
        p[step] = i;
        dfs(step + 1);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}