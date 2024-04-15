/**
 * Description:
 *  你现在有N根竹子，它们的长度分别是l1,l2,…,ln（单位cm）
 *  你的目的是使用这些竹子制作出长度为A,B,C的三根竹子。你可以使用以下3种魔法：
 *  （1）延长魔法：消耗1MP，选择1根竹子，将它的长度增加1cm
 *  （2）缩短魔法：消耗1MP，选择1根长度大于1cm的竹子，将它的长度减少1cm
 *  （3）合成魔法：消费10MP，将两根竹子合成一根，长度等于两根竹子之和。
 *  为了得到三根长度为A,B,C的竹子，最少需要消耗多少MP？
 *
 * Input:
 *  第1行，4个正整数N,A,B,C
 *  接下来N行，每行1个正整数li
 *
 * Output:
 *  需要消耗的最少MP
 *
 * Hints:
 *  3≤N≤8 1≤C<B<A≤1000 1<=li<=1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 100 90 80
100
100
90
80
 *
 *  output:
0
 *
 *  2):
 *  input:
5 100 90 80
98
40
30
21
80
 *
 *  output:
23
 *
 *  3):
 *  input:
8 1000 800 100
300
333
400
444
500
555
600
666
 *
 *  output:
243
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, A, B, C, a[20], ans = 1e9;

void dfs(int step, int la, int lb, int lc, int cnt)
{
    if (step > n) {
        if (la == 0 || lb == 0 || lc == 0) {
            return;
        }
        int sum = abs(A - la) + abs(B - lb) + abs(C - lc) + 10 * (cnt - 3);
        ans = min(ans, sum);
        return;
    }
    dfs(step + 1, la, lb, lc, cnt);
    dfs(step + 1, la + a[step], lb, lc, cnt + 1);
    dfs(step + 1, la, lb + a[step], lc, cnt + 1);
    dfs(step + 1, la, lb, lc + a[step], cnt + 1);
}

int main()
{
    cin >> n >> A >> B >> C;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0, 0, 0, 0);
    cout << ans << endl;
    return 0;
}