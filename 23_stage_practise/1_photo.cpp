/**
 * Description:
 *  学校将在一天内举办 n
 * 个活动，已知每个活动开始时间和结束时间（精确到分钟的闭区间）。皮皮所在的校电视台的同学们负责给这些活动拍摄照片，每个活动都至少需要拍摄一次，由于校电视台的同学们需要尽量多的聚集开会，因此拍照最好大家在某一时间点一起出动，同时拍摄尽可能多的活动，已知拍摄人数和设备足够覆盖所有活动，且忽略拍摄花费的时间。大家决定提前规划好，出动尽量少的次数，完成拍摄。
 *
 * Input:
 *  第 1 行一个数字 n，表示要举办 n 个活动。1 <= N <= 1000
 *  第 2 行到第 n+1 行，每行两个时间表示活动开始时间和结束时间。
 *
 * Output:
 *  1行，1个数字，表示共需要出动的最少次数。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5
15:42 16:38
12:08 20:18
14:16 17:16
14:17 17:53
18:48 19:48
 *
 *  output:
2
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n;
struct node {
    int a, b;
} p[1010];

bool cmp(node x, node y) { return x.b < y.b; }

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        scanf("%d:%d %d:%d", &x1, &y1, &x2, &y2);
        p[i].a = x1 * 60 + y1;
        p[i].b = x2 * 60 + y2;
    }
    sort(p + 1, p + n + 1, cmp);
    int ans = 0, last = -1;
    for (int i = 1; i <= n; i++) {
        if (p[i].a > last) {
            ans++;
            last = p[i].b;
        }
    }
    cout << ans << endl;
    return 0;
}