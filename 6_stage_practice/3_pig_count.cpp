/**
 * Description:
 *  拱猪是一种很有趣的扑克牌游戏。 即使你不知道它的玩法，你也可以由它的计分方式来了解它的趣味性。 假设在此我们仅考虑四个人的拱猪牌局，本题要求你根据下面的计分规则，在牌局结束时计算四位玩家所得分数。
 *	1.	我们分别以S,H,D,C来代表黑桃，红心，方块及梅花，并以数字1至13来代表 A、2、...、Q、K 等牌点，例如︰H1为红心A，S13为黑桃K。
 *	2.	牌局结束时，由各玩家持有的有关计分的牌（计分牌）仅有S12（猪），所有红心牌，D11（羊）及C10（加倍）等16张牌。其它牌均弃置不计。若未持有这 16张牌之任一张则以得零分计算。
 *	3.	若持有C10的玩家只有该张牌而没有任何其它牌则得+50 分，若除了C10还有其它计分牌，则将其它计分牌所得分数加倍计算。
 *	4.	若红心牌不在同一家，则H1至H13等13张牌均以负分计，其数值为−50,−2,−3,−4,−5,−6,−7,−8,−9,−10,−20,−30,−40。而且S12与D11分别以−100 及+100 分计算。
 *	5.	若红心牌H1至H13均在同一家，有下列情形：
 *
 *  o 所有红心牌以+200分计算。
 *  o 若 S12，D11皆在吃下所有红心牌之一家，则此玩家得 +500 分。
 *  o 而 C10 还是以前面所述原则计算之。
 *   例一：若各玩家持有计分牌如下：（每行代表一玩家所持有之牌）
 *   S12 H3 H5 H13
 *   D11 H8 H9
 *   C10 H1 H2 H4 H6 H7
 *   H10 H11 H12
 *   则各家之得分依序为：-148、+83、-138 及 -60。
 *   例二：若各玩家持有计分牌如下：（第四家未持有任何计分牌）
 *   H1 H2 H3 H4 H5 H6 H7 H8 H9 H10 H11 H12 H13
 *   S12 C10
 *   D11
 *   则各家之得分依序为：+200、-200、+100 及 0。
 *   例三：若有一玩家持有所有 16 张计分牌，则得 +1000 分。其余三家均得零分。
 *
 * Input:
 *  每个输入文件由多组测试数据构成。
 *  第一行一个正整数 T，表示测试数据有 T 组。
 *  接下来 4T 行，每 4 行表示一组测试数据。
 *  每组测试数据有四行，每一行第一个数为该玩家所持有计分牌总数，而后列出其所持有之所有计分牌，牌数与各计分牌均以一个或多个空格分开。相邻两组测试数据之间不会有空白行。
 *
 * Output:
 *  每一行输出一组测试数据对应的结果，依次输出各家所得分数，共4个整数(含正负号，0除外)，相邻两个整数之间以一个空格分开，符号和数字间不可以有空格。每组输出间不需要有空白行。
 *
 * Hints:
 *  1<=T<=100
 */

/**
 *  Samples:
 *  1):
 *  input:
3
4  S12    H3  H5   H13
3  D11 H8        H9
6  C10  H1  H2  H4  H6  H7
3  H10  H11  H12
13 H1 H2 H3 H4 H5 H6 H7 H8 H9 H10 H11 H12 H13  
2  S12 C10
1  D11
0
15 H1 H2 H3 H4 H5 H6 H7 H8 H9 H10 H11 H12 H13 S12 D11
0
1 C10
0
 *
 *  output:
-148 +83 -138 -60
+200 -200 +100 0
+500 0 +50 0
 *
 */

#include <iostream>
using namespace std;
int f[] = {0, -50, -2, -3, -4, -5, -6, -7, -8, -9, -10, -20, -30, -40};
int T, n;
int main()
{
    cin >> T;
    for (int c = 1; c <= 4 * T; c++) {
        cin >> n;
        int cntH = 0, s12 = 0, d11 = 0, c10 = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            char op;
            int x;
            cin >> op >> x;
            if (op == 'H') {
                cntH++;
                ans += f[x];
            }
            if (op == 'S') {
                s12 = 1;
                ans -= 100;
            }
            if (op == 'D') {
                d11 = 1;
                ans += 100;
            }
            if (op == 'C') {
                c10 = 1;
            }
        }
        if (n == 1 && c10) {
            ans = 25;
        }
        if (cntH == 13) {
            ans = 200;
            if (s12) {
                ans -= 100;
            }
            if (d11) {
                ans += 100;
            }
            if (s12 && d11) {
                ans = 500;
            }
        }
        if (c10) {
            ans *= 2;
        }
        if (ans > 0) {
            cout << "+";
        }
        cout << ans << " ";
        if (c % 4 == 0) {
            cout << endl;
        }
    }
    return 0;
}