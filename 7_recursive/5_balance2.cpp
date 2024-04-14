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
int w1, w2, w3, w4, w5, cnt;

int main()
{
    cin >> w1 >> w2 >> w3 >> w4 >> w5;
    for (int a = -1; a <= 1; a++) {
        for (int b = -1; b <= 1; b++) {
            for (int c = -1; c <= 1; c++) {
                for (int d = -1; d <= 1; d++) {
                    for (int e = -1; e <= 1; e++) {
                        int cha = a * w1 + b * w2 + c * w3 + d * w4 + e * w5;
                        if (cha == 0) {
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}