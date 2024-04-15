/**
 * Description:
 *  农民约翰以拥有世界上最健康的奶牛为傲.
 * 他知道每种饲料中所包含的牛所需的最低的维他命量是多少.
 * 请你帮助农夫喂养他的牛，以保持它们的健康，使喂给牛的饲料的种数最少.
 *  给出牛所需的最低的维他命量，输出喂给牛需要哪些种类的饲料，且所需的饲料剂量最少.
 *  维他命量以整数表示，每种饲料最多只能对牛使用一次，数据保证存在解.
 *
 * Input:
 *  第1行：一个整数V(1≤V≤25),表示需要的维他命的种类数.
 *  第2行：V个整数(1≤每个数≤1000),表示牛每天需要的每种维他命的最小量.
 *  第3行：一个整数G(1≤G≤15),表示可用来喂牛的饲料的种数.
 *  下面G行，第n行表示编号为n饲料包含的各种维他命的量的多少.
 *
 * Output:
 *  输出只有一行，包括
 *  牛必需的最小的饲料种数P
 *  后面有P个数，表示所选择的饲料编号（按从小到大排列）.
 *  如果有多个解，输出饲料序号最小的（即字典序最小）.
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
100 200 300 400
3
50  50  50  50
200 300 200 300
900 150 389 399
 *
 *  output:
2 1 3
 *
 */

#include <iostream>
using namespace std;
int V, G, v[30], g[20][30], vis[20], P = 1e9, ans[20];

bool check()
{
    for (int i = 1; i <= V; i++) {
        int s = 0;
        for (int j = 1; j <= G; j++) {
            if (vis[j]) {
                s += g[j][i];
            }
        }
        if (s < v[i]) {
            return false;
        }
    }
    return true;
}

void dfs(int step, int c)
{
    if (step > G) {
        if (check() && P > c) {
            P = c;
            for (int i = 1; i <= G; i++) {
                ans[i] = vis[i];
            }
        }
        return;
    }
    vis[step] = 1;
    dfs(step + 1, c + 1);
    vis[step] = 0;
    dfs(step + 1, c);
}

int main()
{
    cin >> V;
    for (int i = 1; i <= V; i++) {
        cin >> v[i];
    }
    cin >> G;
    for (int i = 1; i <= G; i++) {
        for (int j = 1; j <= V; j++) {
            cin >> g[i][j];
        }
    }
    dfs(1, 0);
    cout << P << " ";
    for (int i = 1; i <= G; i++) {
        if (ans[i]) {
            cout << i << " ";
        }
    }
    return 0;
}