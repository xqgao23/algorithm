/**
 * Description:
 *  在 a1,a2,…,an 中 , 一个 k 长度子序列指 ai1,ai2,…,aik, 使得1≤i1<i2<⋯<ik≤n.
 *  在 b1,b2,…,bm 中 , 一个 k 长度子序列指 bi1,bi2,…,bik, 使得 1≤i1<i2<…<ik≤m.
 *  以下将ai1,ai2,…,aik称作数组c，bj1,bj2,…,bjt称作数组d。c,d分别是a,b的子序列，对应地，称a,b分别是c,d的父序列。
 *  如果a,b两个原数组完全相同，即m=n且a1=b1,a2=b2,…,an=bm，则称数组
 *  a （也就是数组b）是c和d的n⻓度的公共父序列。
 *  求n的最小值（即求c和d的最短公共父序列⻓度）。
 *
 * Input:
 *  输入共 3 行：
 *  第 1 行， 2 个用空格隔开的正整数k,l，分别为数组c中的元素的个数和数组d中的元素的个数；
 *  第 2 行，k个用空格隔开的正整数c1,c2,...,ck
 *  第 3 行，l个用空格隔开的正整数d1,d2,...,dl.
 *
 * Output:
 *  一个正整数 ans ，为n的最小值（即求c和d的最短公共父序列长度）。
 *
 * Hints:
 *  5≤k,l≤3000 ， 1≤ci,dj≤10000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
11 9
2 9 8 8 4 5 10 9 11 11 9
6 2 7 9 5 8 4 5 3
 *
 *  output:
15
 *
 */
 
#include <iostream>
#include <cstring>

using namespace std;

int n, m, A[3010], B[3010], f[3010][3010];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int j = 1; j <= m; j++) {
        cin >> B[j];
    }

    memset(f, 0x3f, sizeof f);
    
    for (int i = 0; i <= n; i++) {
        f[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        f[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i] == B[j]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
