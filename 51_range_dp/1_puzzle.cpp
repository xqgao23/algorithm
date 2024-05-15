/**
 * Description:
 *  平方拼图是用一堆牌来玩的，这些牌排成一行，每一张牌都包含一个正整数。在移动过程中，玩家从一行中取出一张牌，并按所取牌上的数字与左右两张牌上的数字之和的平方来得分。如果取出最左的卡片，就只计算它和右边卡片之和的平方。取最右的卡片，就只计算它和左边卡片之和的平方。
 *  我们的目标是采取某种顺序取牌以尽量增加总得分。
 *  例如，如果一行中的牌包含数字20,1,50，玩家可能会拿先拿一张1的牌，然后拿20和50的牌，这样的得分为(20+1+50)<2>+(20+50)<2>+50<2>=5041+4900+2500=12441
 *  如果它按照相反的顺序拿牌，即先拿50，再拿20，最后拿1，这样的得分为(1+50)<2>+(20+1)<2>+1<2>=2601+441+1=3043
 *
 * Input:
 *  第一行为一个整数N(3≤N≤100)，表示卡牌的数量
 *  接下来N个数字，第i个数字ai(1≤ai≤100)表示第i张牌上的数字
 *
 * Output:
 *  一个数字，表示最大得分
 *
 * Hints:
 *  1≤n≤10<5>, 1≤hi≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
20 1 50
 *
 *  output:
12441
 *
 */

#include <iostream>
using namespace std;
int n, a[110], f[110][110];

int sqr(int x) { return x * x; }

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        f[i][i] = sqr(a[i - 1] + a[i] +
                      a[i + 1]);
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;
            for (int k = i; k <= j; k++) {
                f[i][j] = max(f[i][j], f[i][k - 1] + f[k + 1][j] + sqr(a[i - 1] + a[k] + a[j + 1]));
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}