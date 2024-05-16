/**
 * Description:
 *  农夫约翰建造了一座有n间牛舍的小屋，牛舍排在一条直线上，从左到右编号为 1∼n。
 *  但是约翰的m头牛对小屋很不满意，只要有两头牛之间的牛舍数量小于 k，他们就会互相攻击。住在同一间牛舍更是不行。
 *  约翰为了防止牛之间互相攻击，有多少种安排牛入住牛舍的方法？答案可能很大，你只需要输出答案除以 10<9>+7 的余数。
 *
 * Input:
 *  三个整数n,m,k
 *
 * Output:
 *  输出答案除以10<9>+7的余数
 *
 * Hints:
 *  1≤n≤5000, m,k≤n
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
10 3 2
 *
 *  output:
20
 *
 *  2):
 *  input:
10 5 0
 *
 *  output:
252
 *
 *  3):
 *  input:
17 5 3
 *
 *  output:
1
 *
 */

#include <iostream>
using namespace std;
int n, m, k, C[5010][5010], mod = 1e9 + 7;

void init()
{
    for (int i = 0; i <= 5000; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    init();
    cout << C[n - k * (m - 1)][m] << endl;
    return 0;
}