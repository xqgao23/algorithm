/**
 * Description:
 *  股市波荡起伏，这是接下来n天的股票信息。
 *  对于一天，可能会有的操作如下：
 *  1 X
 * Y，表示更新股票X(1≤X≤10<9>)的价格，更新后价格为Y(1≤Y≤10<9>)。（如果X不存在，则将其初始价格设为Y）
 *  2，查询当前所有股票中价格最低的股票的价格。
 *  3，查询当前所有股票中价格最高的股票的价格。
 *  对于每个操作2或者操作3，你需要输出对应的股票价格。
 *
 * Input:
 *  第一行一个整数n(1≤n≤5×10<5>)，表示一共有n天。
 *  接下来n行，每行为上述三种操作中的一种。
 *  数据保证合法，即当出现操作2或者操作3时，当前已经存在至少一支股票。
 *  输入量较大，建议使用scanf或者cin关闭流同步。
 *
 * Output:
 *  对于每个操作2或者操作3，输出一行，包含一个整数，表示对应查询的结果。
 *
 * Hints:
 *  1≤n≤5×10<5>, 1≤X≤10<9>,1≤Y≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
1 5 10
1 1000000000 5
2
1 1000000000 11
3
 *
 *  output:
5
11
 *
 */

#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<int, int> price, cnt;
int n, op, x, y;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d", &x, &y);
            if (price.count(x)) {
                int oldprice = price[x];
                price[x] = y;
                cnt[y]++;
                if (--cnt[oldprice] == 0) {
                    cnt.erase(oldprice);
                }
            } else {
                price[x] = y;
                cnt[y]++;
            }
        } else if (op == 2) {
            auto it = cnt.begin();
            printf("%d\n", it->first);
        } else {
            auto it = cnt.end();
            it--;
            printf("%d\n", it->first);
        }
    }
    return 0;
}