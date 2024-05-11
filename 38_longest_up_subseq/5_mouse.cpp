/**
 * Description:
 *  给出n只老鼠的数据，分别是它们的体重和速度。
 *  为了证明越重的老鼠速度越慢，我们要找出一组数据，由若干个老鼠组成，保证老鼠的体重依次增加而速度依次减小。
 *  问最多能找出多少只老鼠？
 *
 * Input:
 *  第一行，一个整数n，表示老鼠的个数
 *  接下来n行，每行两个正整数wi,vi，分别表示老鼠的体重和速度
 *
 * Output:
 *  输出一个整数，最多能找出的老鼠个数
 *
 * Hints:
 *  1≤n≤1000；1≤wi,vi≤10000；
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
9
6008 1300
6000 2100
500 2000
1000 4000
1100 3000
6000 2000
8000 1400
6000 1200
2000 1900
 *
 *  output:
4
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, f[1010], ans;
struct node {
    int w, v;
} a[1010];

bool cmp(node x, node y)
{
    if (x.w != y.w) {
        return x.w < y.w;
    }
    return x.v < y.v;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].w >> a[i].v;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i].v < a[j].v) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}