/**
 * Description:
 *  今年音乐节，苹果君开始准备舞台。 舞台由上中下3部分组成.
 *  舞台3个部分的零件分别有N个,编号为1∼N.
 *  第i个上部零件的尺寸为Ai,第i个中部零件的尺寸为Bi, 第i个下部零件的尺寸为Ci.
 *  为了组成一个舞台,
 *  中部零件的尺寸必须比上部零件尺寸大,下部零件的尺寸必须比中部零件尺寸大.
 *  苹果君能够组成多少个不同的舞台? 相同的舞台是指上中下部编号对应相等的舞台.
 *
 * Input:
 *  第一行一个整数N
 *  第二行N个整数A1,A2,...,AN
 *  第三行N个整数B1,B2,...,BN
 *  第四行N个整数C1,C2,...CN
 *
 * Output:
 *  输出不同舞台的个数
 *
 * Hints:
 *  1≤N≤10<5>
 *  1≤Ai,Bi,Ci≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2
1 5
2 4
3 6
 *
 *  output:
3
 *
 *  2):
 *  input:
3
1 1 1
2 2 2
3 3 3
 *
 *  output:
27
 *
 *  3):
 *  input:
6
3 14 159 2 6 53
58 9 79 323 84 6
2643 383 2 79 50 288
 *
 *  output:
87
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, a[100010], b[100010], c[100010];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    sort(a + 1, a + n + 1);
    sort(c + 1, c + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = lower_bound(a + 1, a + n + 1, b[i]) - a - 1;
        int y = n - (upper_bound(c + 1, c + n + 1, b[i]) - c) + 1;
        ans += 1ll * x * y;
    }
    cout << ans << endl;
    return 0;
}