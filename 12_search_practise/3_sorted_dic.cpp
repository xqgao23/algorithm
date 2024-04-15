/**
 * Description:
 *  给出 1∼N 的两个排列 P 和 Q，若 P 是字典序第 a 个排列，Q 是字典序第 b 个排列。求 ∣a−b∣。
 *
 * Input:
 *  第 1 行，1 个正整数 N。
 *  第 2 行，N 个正整数, p1,p2,…,pn.
 *  第 2 行，N 个正整数q,q2,…,qn.
 *
 * Output:
 *  一个正整数|a-b|
 *
 * Hints:
 *  2<=N<=8, 1<=pi<=N且互不相同, 1<=qi<=N且互不相同
 */

/**
 *  Samples:
 *  1):
 *  input:
3
1 3 2
3 1 2
 *
 *  output:
3
 *
 *  2):
 *  input:
8
7 3 5 4 2 1 6 8
3 8 2 5 4 6 7 1
 *
 *  output:
17517
 *
 *  3):
 *  input:
3
1 2 3
1 2 3
 *
 *  output:
0
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
int n, P[10], Q[10], vis[10], f[10], cnt, a, b;

bool check(int x[])
{
    for (int i = 1; i <= n; i++) {
        if (f[i] != x[i]) {
            return false;
        }
    }
    return true;
}

void dfs(int step)
{
    if (step > n) {
        cnt++;
        if (check(P)) {
            a = cnt;
        }
        if (check(Q)) {
            b = cnt;
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            f[step] = i;
            vis[i] = 1;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> Q[i];
    }
    dfs(1);
    cout << abs(a - b) << endl;
    return 0;
}