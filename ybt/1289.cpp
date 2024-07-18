/**
 * Description:
 *  某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。
 *  输入导弹依次飞来的高度(雷达给出的高度数据是不大于30000的正整数)，计算这套系统最多能拦截多少导弹。
 *
 * Input:
 *  第一行是一个整数N(不超过15)，表示导弹数。
 *  第二行包含N个整数，为导弹依次飞来的高度(雷达给出的高度数据是不大于30000的正整数)。
 *
 * Output:
 *  一个整数，表示最多能拦截的导弹数。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
8
389 207 155 300 299 170 158 65
 *
 *  output:
6
 *
 */

#include <iostream>

using namespace std;

int a[101];
int dp[101];

int main()
{
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] >= a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;

    return 0;
}