/**
 * Description:
 *  小明种的韭菜可以割了，他需要至少m厘米长的韭菜。小明在割之前会设定一个高度h，然后将所有高度大于h厘米的韭菜，割掉它们高于h厘米的部分。
 *  例如，如果每个韭菜的高度分别为20，15，10和17，小明高度设为15，割完后剩下的高度将是15，15，10和15，而小明将从第1棵韭菜得到5厘米，从第4棵韭菜得到2厘米，共得到7厘米韭菜。
 *  小明还想要韭菜继续生长，所以他不会割掉过多的韭菜。帮助小明找到的最大的整数高度h，使得他能得到至少m厘米韭菜。换句话说，如果h再升高1厘米，则他将得不到m厘米韭菜。
 *
 * Input:
 *  第1行：2个整数n和m，n表示韭菜的数量（1<=n<=1000000）,m表示需要的韭菜总长度（1<=M<=2000000000）
 *  第2行：n个整数表示每棵韭菜的高度，值均不超过1000000000。所有韭菜长度之和大于m，因此必有解。
 *
 * Output:
 *  第1行：1个整数，表示可以设置的最高高度。
 *
 * Hints:
 *  1≤n,Q≤10<5>
 *  1≤ai,bi≤10<18>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 20
4 42 40 26 46
 *
 *  output:
36
 *
 */

#include <iostream>
using namespace std;
int n, m, h[1000010];

bool check(int x)
{
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] >= x) {
            sum += h[i] - x;
        }
    }
    return sum >= m;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    int l = 0, r = 1e9, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}