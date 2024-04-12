/**
 * Description:
 *  到了收获的季节, 香蕉园里有n棵香蕉树排成一列, 树上分别结了a1,a2,…,an个香蕉.
 *  小猴只能收获相邻的连续若干棵香蕉树上的香蕉，且必须收获至少K个香蕉. 但是小猴不满足于此，他想知道要收获至少K个香蕉，一共有多少种不同的收法.（只要起点终点不完全相同就认为是不同的收获方法）
 *  请写程序帮他确定不同的收获方法数吧.
 * 
 * Input:
 *  输入共两行:
 *  第1行，以空格分隔的两个正整数n,K,分别表示香蕉数树的棵数和小猴需要收获的香蕉个数.
 *  第2行，以空格分隔的n个正整数a1,a2,…an, 依次表示每棵树上的香蕉个数.
 * 
 * Output:
 *  输出共1行,1个正整数，为收获至少K个香蕉的不同方法数.
 * 
 * Hints:
 *  1<=ai<=10<5>, 1<=n<=10<5>, 1<=K<=10<10>
 *
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
10 51235
10 4152 987 48541 412 51 2 88999 4000 44444
 * 
 *  output:
32
 *
 *  2):
 *  input:
5 10
5 1 3 4 2
 * 
 *  output:
3
 *
 */

// 尺取 + 前缀和 + break 100分
#include <iostream>

using namespace std;

int n, a[100010];
long long k, s[100010], ans;

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i]; // 前缀和预处理
    }

    int last = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = last; j <= n; j++) {
            long long sum = s[j] - s[i - 1]; // 前缀和计算a[i]~a[j]的元素之和
            if (sum >= k) {
                ans += n - j + 1;
                last = j;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

