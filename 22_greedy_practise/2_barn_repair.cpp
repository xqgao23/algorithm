/**
 * Description:
 *  在一个月黑风高的暴风雨夜，Farmer John 的牛棚的屋顶、门被吹飞了
 * 好在许多牛正在度假，所以牛棚没有住满。
 *  牛棚一个紧挨着另一个被排成一行，牛就住在里面过夜。有些牛棚里有牛，有些没有。
 * 所有的牛棚有相同的宽度。 自门遗失以后，Farmer John
 * 必须尽快在牛棚之前竖立起新的木板。他的新木材供应商将会供应他任何他想要的长度，但是吝啬的供应商只能提供有限数目的木板。
 * Farmer John 想将他购买的木板总长度减到最少。
 *  给出 m,s,c，表示木板最大的数目、牛棚的总数、牛的总数；以及每头牛所在牛棚的编号，请算出拦住所有有牛的牛棚所需木板的最小总长度。
 *
 * Input:
 *  一行三个整数 m,s,c，意义如题目描述。
 *  接下来 c 行，每行包含一个整数，表示牛所占的牛棚的编号。
 *
 * Output:
 *  输出一行一个整数，表示所需木板的最小总长度。
 *
 * Hints:
 *  1≤m≤50，1≤c≤s≤200。
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 50 18
3
4
6
8
14
15
16
17
21
25
26
27
30
31
40
41
42
43
 *
 *  output:
25
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int m, s, c, ans, a[205], b[205];

bool cmp(int x, int y) { return x > y; }

int main()
{
    cin >> m >> s >> c;
    for (int i = 1; i <= c; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + c + 1);
    ans = a[c] - a[1] + 1;
    for (int i = 1; i < c; i++) {
        b[i] = a[i + 1] - a[i] - 1;
    }
    sort(b + 1, b + c, cmp);
    for (int i = 1; i < m; i++) {
        ans -= b[i];
    }
    cout << ans << endl;
    return 0;
}