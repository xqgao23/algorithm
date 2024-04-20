/**
 * Description:
 *  马上又到了一年一度的新年联欢, 小明作为班里的班长, 负责组织策划新年联欢活动,
 * 他决定采购一些奖品奖励积极参与每个活动项目的同学. 为了激励更多的人参与活动,
 * 需要采购的奖品数目越多越好. 班费中可支出的钱数为m元,
 * 现给定商店中n种可作为奖品的物品的价格和库存数量, 怎样才能购得最多的物品数?
 *
 * Input:
 *  输入共有n+1行
 *  第一行包含两个正整数m,n (1≤m≤10000,1≤n≤100),
 * 表示可支出的费用m和可购买的物品种类n种.
 *  接下来n行，每行两个数pi和ai，表示第i种商品的单价和库存数量。（(1≤pi≤10000,1≤ai≤100)
 *
 * Output:
 *  仅一个整数, 表示最多可以购买的物品数量.
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
500 6
100 3
20 15
50 10
35 5
5 6
60 2
 *
 *  output:
25
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
struct node {
    int p, c;
} a[110];
int n, m;

bool cmp(node x, node y)
{
    return x.p < y.p;
}

int main()
{
    cin >> m >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].p >> a[i].c;
    }

    sort(a + 1, a + n + 1, cmp);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (m <= a[i].p * a[i].c) {
            ans += m / a[i].p;
            break;
        }
        ans += a[i].c;
        m -= a[i].p * a[i].c;
    }

    cout << ans << endl;
    return 0;
}