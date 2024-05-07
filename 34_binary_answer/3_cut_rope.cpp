/**
 * Description:
 *  有 N 条绳子，它们的长度分别为 Li。如果从它们中切割出 K 条长度相同的绳子，这 K 条绳子每条最长能有多长？(直接舍掉 2 位后的小数)。
 *
 * Input:
 *  第一行两个整数 N 和 K，接下来 N 行，描述了每条绳子的长度 Li
 *
 * Output:
 *  切割后每条绳子的最大长度。(直接舍掉 2 位后的小数)。
 *
 * Hints:
 *  0<Li≤100000.00, 0<n≤100000, 0<k≤10000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 11
8.02
7.43
4.57
5.39
 *
 *  output:
2.00
 *
 */

#include <iostream>
using namespace std;
int n, k, len[100010];

bool check(int m)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += len[i] / m;
    }
    return cnt >= k;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        double x;
        cin >> x;
        len[i] = x * 100;
    }
    int l = 0, r = 10000000, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    printf("%.2lf\n", l / 100.0);
    return 0;
}