/**
 * Description:
 *  要求找到一个正整数序列，满足序列中所有的数不超过n，序列长度为m，且除了第一个数外，所有的数都能被前一个数整除（即是前一个数的倍数）。
 *  我们想要知道这样的序列都有哪些，输出所有满足要求的序列。
 *
 * Input:
 *  第一行，两个正整数n,m
 *
 * Output:
 *  按字典序从小到大，每行输出一个满足要求的序列，数与数之间用空格分隔。
 *
 * Hints:
 *  1≤n≤40；1≤m≤20
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 3
 *
 *  output:
1 1 1
1 1 2
1 1 3
1 1 4
1 2 2
1 2 4
1 3 3
1 4 4
2 2 2
2 2 4
2 4 4
3 3 3
4 4 4
 *
 */

#include <algorithm>
#include <iostream>

using namespace std;
int n, m, p[30];

void dfs(int step)
{
    if (step > m) {
        for (int i = 1; i <= m; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        p[step] = i;
        if (step > 1 && i % p[step - 1] != 0) {
            continue;
        }
        dfs(step + 1);
    }
}

int main()
{
    cin >> n >> m;
    dfs(1);
    return 0;
}