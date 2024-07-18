/**
 * Description:
 *  一个商人穿过一个N×N的正方形的网格，去参加一个非常重要的商务活动。他要从网格的左上角进，右下角出。每穿越中间1个小方格，都要花费1个单位时间。商人必须在(2N-1)个单位时间穿越出去。而在经过中间的每个小方格时，都需要缴纳一定的费用。
 *  这个商人期望在规定时间内用最少费用穿越出去。请问至少需要多少费用？
 *  注意：不能对角穿越各个小方格（即，只能向上下左右四个方向移动且不能离开网格）。
 *
 * Input:
 *  第一行是一个整数，表示正方形的宽度N (1≤N<100)；
 *  后面N行，每行N个不大于100的整数，为网格上每个小方格的费用。
 *
 * Output:
 *  至少需要的费用。
 *
 * Hints:
 *  样例中，最小值为109=1+2+5+7+9+12+19+21+33。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
1  4  6  8  10 
2  5  7  15 17 
6  8  9  18 20 
10 11 12 19 21 
20 23 25 29 33
 *
 *  output:
109
 *
 */

#include <iostream>
#include <cstring>

using namespace std;

int a[101][101];
int dp[101][101];

int main()
{
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = a[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[n][n] << endl;

    return 0;
}