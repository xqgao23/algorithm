/**
 * Description:
 *  FFT 组队赛开始了，某班准备选出三人组成一个小队参赛。教练事先让每位同学写下自己心目中的理想队员，每位同学只能写一名同学作为自己的理想队员。
 *  共有 n 名同学，我们给他们编号 1∼n。假设第 i 名同学写下的理想队员是 ai
 *  最终选出的队员 i,j,k 一定要满足：ai,aj,ak 的值恰好是 i,j,k 每种一个。这样能够保证队伍中每个人都和自己的理想队员组队，并且不会有某位队员受到过多偏爱。
 *  现在教练已经知道所有 a1,a2,…,an 的值。问有多少种组队的方案。
 *
 * Input:
 *  第 1 行，1 个正整数 n。
 *  第 2 行，n 个正整数a1,a2,...,an
 *
 * Output:
 *  1 个整数，满足要求的组队方案。
 *
 * Hints:
 *  3≤n≤2*10<5>, 1≤ai≤10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6
1 4 6 5 2 3
 *
 *  output:
2
 *
 *  2):
 *  input:
6
2 1 3 4 5 10000
 *
 *  output:
4
 *
 *  3):
 *  input:
15
10 6 7 5 6 11 3 8 9 1 2 11 13 14 15
 *
 *  output:
21
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;

int n, a[200010], ans;

bool check(int i, int j, int k)
{
    int x[] = {i, j, k};
    int y[] = {a[i], a[j], a[k]};
    
    sort(y, y + 3);
    
    for (int i = 0; i <= 2; i++) {
        if (x[i] != y[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (check(i, j, k)) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}