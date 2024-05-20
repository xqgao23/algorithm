/**
 * Description:
 *  Logo 语言命令可以指挥海龟在屏幕中爬行。本问题只使用 Logo 语言的三个语句：前进 FD，倒退 BK 和重复 REPEAT，因此，海龟只在一条直线上来回爬行。输入一行 logo 的命令行，输出海龟在屏幕中离开原来位置的距离（假设屏幕很大，可以让海龟移动最多 10<9> 的距离）。
 *  例如：
 *  输入 FD 100，输出：100。
 *  输入 FD 100 BK 150， 输出：50。
 *  输入 REPEAT 5[FD 100 BK 50]， 输出：250。
 *  输入 REPEAT 5[FD 50 REPEAT 10[FD 100]]， 输出：5250。
 *
 * Input:
 *  一行，一个字符串，符合上述规定的 logo 命令行。
 *
 * Output:
 *  一个数据，海龟离开原来位置的距离。
 *
 * Hints:
 *  输入的数据绝对值不超过 100。海龟在移动过程中离开原点的距离不会超过10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
FD 100 BK 150
 *
 *  output:
50
 *
 *  2):
 *  input:
REPEAT 5[FD 100 BK 50]
 *
 *  output:
250
 *
 *  3):
 *  input:
REPEAT 5[FD 50 REPEAT 10[FD 100]]
 *
 *  output:
5250
 *
 *  4):
 *  input:
REPEAT 2[BK 5 REPEAT 3[FD 7]] BK 10 REPEAT 4[]
 *
 *  output:
22
 *
 */

#include <iostream>
using namespace std;

int dfs()
{
    string s;
    char c;
    int ans = 0, k = 0;
    while (c = cin.get()) {
        if (c == ']' || c == '\n') {
            break;
        }
        if (c == ' ') {
            continue;
        }
        cin >> s >> k;
        if (c == 'R') {
            cin >> c;
            ans += k * dfs();
        }
        if (c == 'F') {
            ans += k;
        }
        if (c == 'B') {
            ans -= k;
        }
    }
    return ans;
}

int main()
{
    cout << abs(dfs()) << endl;
    return 0;
}