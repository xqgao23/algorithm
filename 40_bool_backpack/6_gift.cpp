/**
 * Description:
 *  芳芳是一对双胞胎的姐姐，最近儿童节快到了，芳芳决定给两个弟弟送儿童节礼物。为了送礼物，芳芳已经提前去商场采购了N件商品，第i件商品的价值为ai。芳芳决定将商品装入两份礼包，分别送给两个弟弟。为了防他们争抢，芳芳希望两份礼包的价值差尽可能小。但是芳芳购物已经很累了，所以分配礼物的工作就交给你了，你能编写程序帮助芳芳吗？
 *
 * Input:
 *  第一行一个整数 N，表示礼物数量。
 *  第二行N个整数，ai表示第i个礼物的价值。数字之间由空格分隔。
 *
 * Output:
 *  第一行，两个礼包的价值差。
 *
 * Hints:
 *  1≤N≤100, 0≤sum<ai>≤10000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
3 2 1 15 4
 *
 *  output:
5
 *
 *  2):
 *  input:
7
3 1 2 3 4 6 5
 *
 *  output:
0
 *
 */

#include <iostream>
using namespace std;
int n, a[105], f[105][10005], s;
// f[i][j] 表示前i个商品装入容量为j的背包中，能否恰好装满

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s / 2; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= a[i]) {
                f[i][j] |= f[i - 1][j - a[i]];
            }
        }
    }
    for (int j = s / 2; j >= 0; j--) {
        if (f[n][j]) // j s-j
        {
            cout << s - 2 * j << endl;
            break;
        }
    }
    return 0;
}