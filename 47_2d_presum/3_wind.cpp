/**
 * Description:
 *  IOI国的风一直是从海上向陆地方向吹的。风从地点0开始，按顺序吹过地点1,2,⋯,n。地点0的海拔高度a0=0，地点i的海拔高度是ai。
 *  风沿着地表吹过时，温度会随着高度变化而变化。在地点0的风的温度是0度，对所有的i(0≤i≤n−1)，从地点i到地点i+1时，风的温度变化如下：
 *  如果ai<ai+1，风的温度下降(ai+1 −ai)×S度。
 *  如果ai≥ai+1，风的温度上升(ai −ai+1)×T度。
 *  IOI国的地壳变动很剧烈，你知道了最近Q天每天的地壳变动信息。第j天（1≤j≤Q），地点Lj∼Rj（包括端点）的海拔高度会变化xj。（如果xj非负表示上升xj，如果xj是负数表示下降∣xj∣）
 *  你的任务是在每天的地壳变动后，输出地点n处的风的温度。
 *
 * Input:
 *  第1行，4个整数n,Q,S,T
 *  接下来n+1行，每行1个整数ai，分别表示地点0,1,2,⋯,n的海拔高度。
 *  接下来Q行，每行3个整数Lj,Rj,xj，表示第j天的地壳变动信息。
 *
 * Output:
 *  输出Q行，每行1个整数，第j行表示第j天地壳变动后，地点n的温度。
 *
 * Hints:
 *  1≤n,Q≤2*10<5>, 1≤S,T≤10<6>, a0=0, -10<6>≤ai≤10<6>(1≤i≤n),  1≤Lj≤Rj≤n, -10<6>≤xj≤10<6>(1≤j≤Q),
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 5 1 2
0
4
1
8
1 2 2
1 1 -2
2 3 5
1 2 -1
1 3 5
 *
 *  output:
-5
-7
-13
-13
-18
 *
 */

#include <iostream>
using namespace std;
typedef long long LL;
int n, q, s, t;
LL a[200010], d[200010], ans;

LL cal(LL x)
{
    if (x > 0) {
        return -x * s;
    }
    return -x * t;
}

int main()
{
    cin >> n >> q >> s >> t;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        d[i] = a[i] - a[i - 1];
        ans += cal(d[i]);
    }
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        ans -= cal(d[l]);
        d[l] += x;
        ans += cal(d[l]);
        if (r < n) {
            ans -= cal(d[r + 1]);
            d[r + 1] -= x;
            ans += cal(d[r + 1]);
        }
        cout << ans << endl;
    }
    return 0;
}