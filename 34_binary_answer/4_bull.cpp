/**
 * Description:
 *  农夫约翰建造了一座有n间牛舍的小屋，牛舍排在一条直线上，第i间牛舍在xi的位置，但是约翰的m头牛对小屋很不满意，因此经常互相攻击。约翰为了防止牛之间互相伤害，因此决定把每头牛都放在离其它牛尽可能远的牛舍。也就是要最大化最近的两头牛之间的距离。
 *  牛们并不喜欢这种布局，而且几头牛放在一个隔间里，它们就要发生争斗。为了不让牛互相伤害。John决定自己给牛分配隔间，使任意两头牛之间的最小距离尽可能的大，那么，这个最大的最小距离是多少呢？
 *
 * Input:
 *  第一行用空格分隔的两个整数n和m；
 *  第二行为n个用空格隔开的整数，表示位置xi
 *
 * Output:
 *  输出仅一个整数，表示最大的最小距离值。
 *
 * Hints:
 *  0≤xi≤10<9>, 2≤n≤10<5>, 2≤m≤n
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 3
1 2 8 4 9
 *
 *  output:
3
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, m, x[100010];

bool check(int d)
{
    int cnt = 0, pos = -1e9;
    for (int i = 1; i <= n; i++) {
        if (x[i] - pos >= d) {
            cnt++;
            pos = x[i];
        }
    }
    return cnt >= m;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sort(x + 1, x + n + 1);
    int l = 1, r = 1e9, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}