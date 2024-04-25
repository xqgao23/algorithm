/**
 * Description:
 *  第一次世界大战期间,Lanchester F.W. 提出了预测战争结局的数学模型.
 *  用xi和yi表示时刻t时交战双方的兵力, 则t+1时刻交战双方的兵力由下式算出:
 *  xt+1 = xt - ⌈yt/B⌉
 *  yt+1 = yt - ⌈xt/A⌉
 *  其中A,B是代表双方战斗力的常数.
 *  其中⌈x⌉ 表示不小于 x 的最小整数.
 *  如果一方兵力小于等于0,战争就结束了，我们想知道胜利的一方还剩下多少兵力.
 *  给定A,B,给出Q组询问，每组包括双方的起始兵力.
 * 对于每组询问输出胜利一方和胜利方剩下的兵力.
 *
 * Input:
 *  第1行,3个正整数A,B,Q
 *  接下来Q行，每行两个正整数x,y
 *
 * Output:
 *  对于每组询问输出1行:
 *  第一个字符输出胜利方'X'或'Y', 接下来1个正整数输出胜利方剩下的兵力,
 * 用空格分隔. 如果双方兵力同时小于等于0, 输出一行"EVEN".
 *
 * Hints:
 *  1≤Q≤5*10<5>, 1≤x,y,A,B≤2000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
15 9 4
142 113
122 22
167 82
9 9
 *
 *  output:
Y 11
X 116
X 121
EVEN
 *
 */

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int A, B, Q, f[2010][2010], INF = 0x3f3f3f3f;

int dfs(int x, int y)
{
    if (f[x][y] != INF) {
        return f[x][y];
    }
    if (x == 0 || y == 0) {
        return f[x][y] = x - y;
    }
    int xx = x - (y + B - 1) / B, yy = y - (x + A - 1) / A;
    if (xx < 0) {
        xx = 0;
    }
    if (yy < 0) {
        yy = 0;
    }
    return f[xx][yy] = dfs(xx, yy);
}

int main()
{
    memset(f, 0x3f, sizeof f);
    cin >> A >> B >> Q;
    while (Q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int ans = dfs(x, y);
        if (ans > 0) {
            cout << "X " << ans << "\n";
        } else if (ans < 0) {
            cout << "Y " << -ans << "\n";
        } else {
            cout << "EVEN"
                 << "\n";
        }
    }
    return 0;
}