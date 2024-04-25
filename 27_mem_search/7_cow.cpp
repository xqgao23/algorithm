/**
 * Description:
 *  农夫约翰有 3 个容量分别为 a,b,c 升的桶。
 *  最初 a,b 桶都是空的，而 c 桶是装满牛奶的。有时，农夫把牛奶从一个桶倒到另一个桶中，直到被灌桶装满或原桶空了。并且每次倒牛奶，牛奶不会有损失。
 *  写一个程序去帮助农⺠找出当 a 桶是空的时候，c 桶中牛奶所剩量的所有可能性。
 *
 * Input:
 *  单独的 1 行包括 3 个整数 a,b,c。
 *
 * Output:
 *  只有 1 行，升序地列出当 a 桶是空的时候，c 桶牛奶所剩量的所有可能性。
 *
 * Hints:
 *  1≤a,b,c≤20
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
8 9 10
 *
 *  output:
1 2 8 9 10
 *
 *  2):
 *  input:
2 5 10
 *
 *  output:
5 6 7 8 9 10
 *
 */

#include <cstring>
#include <iostream>
using namespace std;
int a, b, c, t, s[25], f[25][25][25];

void dfs(int x, int y, int z)
{
    if (f[x][y][z] != -1) {
        return;
    }
    f[x][y][z] = 1;
    if (x == 0) {
        s[z] = 1;
    }
    t = min(x, b - y);
    dfs(x - t, y + t, z);
    t = min(x, c - z);
    dfs(x - t, y, z + t);
    t = min(y, a - x);
    dfs(x + t, y - t, z);
    t = min(y, c - z);
    dfs(x, y - t, z + t);
    t = min(z, a - x);
    dfs(x + t, y, z - t);
    t = min(z, b - y);
    dfs(x, y + t, z - t);
}

int main()
{
    cin >> a >> b >> c;
    memset(f, -1, sizeof f);
    dfs(0, 0, c);
    for (int i = 0; i <= c; i++) {
        if (s[i] == 1) {
            cout << i << " ";
        }
    }
    return 0;
}