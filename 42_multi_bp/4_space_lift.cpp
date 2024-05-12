/**
 * Description:
 *  奶牛们要去太空了！它们打算用方块建造一座太空电梯。
 *  现在它们有 N 种方块，第 i 种方块有一个特定的高度 hi，一定的数量 ci。
 *  若干个方块叠起来就可以得到一个很高的电梯，但是为了防止宇宙射线破坏方块，第 i 种方块的任何部分不能放在电梯上超过高度 ai 的地方。
 *  请用这些方块堆出最高的太空电梯。
 *
 * Input:
 *  第一行，一个整数 N；
 *  第二行到 N+1 行，第 i+1 行三个整数 hi,ai,ci，数字之间用空格分隔。
 *
 * Output:
 *  共一行，一个整数，为太空电梯的高度。
 *
 * Hints:
 *  1≤N≤400, 1≤hi≤100, 1≤ci≤10, 1≤ai≤4*10<4>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
7 40 3
5 23 8
2 52 6
 *
 *  output:
48
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    int h, c, a;
} p[410];

int n, f[40010];

bool cmp(node x, node y)
{
    return x.a < y.a;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].h >> p[i].a >> p[i].c;
    }
    
    sort(p + 1, p + n + 1, cmp);

    f[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= p[i].c; k++) {
            for (int j = p[i].a; j >= p[i].h; j--) {
                f[j] |= f[j - p[i].h];
            }
        }
    }

    for (int i = 40000; i >= 1; i--) {
        if (f[i]) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}