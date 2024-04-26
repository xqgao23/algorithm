/**
 * Description:
 *  一位母亲需要 m 升牛奶。她有两个桶，大小分别为 x,y 升。
 *  她只能执行如下操作合计不超过 k 次：
 *  （1） 将任意一个桶中装满牛奶。
 *  （2） 将任意一个桶中的牛奶倒空
 *  （3） 将一个桶里的奶倒入另一个桶中，直到这个桶倒空或另一个桶被倒满。
 *  这位母亲意识到她可能无法在两个桶中刚好装下合计 m 升牛奶，假设她经过不超过 k 次操作后，两个桶中牛奶合计有 m’升，请你求出 m 和 m,
 * m’ 之差（大减小）可能的最小值。
 *
 * Input:
 *  1行，4个整数x,y,k,m
 *
 * Output:
 *  1个整数，输出 m 和 m’ 之差（大减小）可能的最小值
 *
 * Hints:
 *  1≤m≤200, 1≤x,y,k≤100
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
14 50 2 32
 *
 *  output:
18
 *
 */

#include <iostream>
using namespace std;
int x, y, k, t, m, f[110][110], ans = 1e9;

void dfs(int a, int b, int c)
{
    if (f[a][b] || c > k) {
        return;
    }
    f[a][b] = 1;
    ans = min(ans, abs(a + b - m));
    dfs(x, b, c + 1);
    dfs(a, y, c + 1);
    dfs(0, b, c + 1);
    dfs(a, 0, c + 1);
    t = min(a, y - b);
    dfs(a - t, b + t, c + 1);
    t = min(b, x - a);
    dfs(a + t, b - t, c + 1);
    f[a][b] = 0; // 可能1步走到的位置，之前要更多的步数走到，然后标记已经
                 // 走了，后面不能走了
}

int main()
{
    cin >> x >> y >> k >> m;
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}