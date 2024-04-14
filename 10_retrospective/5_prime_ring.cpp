/**
 * Description:
 *  输入正整数n，把整数1∼n组成一个环，使得相邻两个数之和均为质数。
 * 输出所有可行的排列方案，输出时从整数1开始逆时针排列，按字典序从小到大输出。
 *
 * Input:
 *  一个正整数n
 *
 * Output:
 *  每行输出一个可行的排列。
 *  输出时从整数1开始逆时针排列，按字典序从小到大输出。
 *
 * Hints:
 *  1≤n<=16
 */

/**
 *  Samples:
 *  1):
 *  input:
6
 *
 *  output:
1 4 3 2 5 6
1 6 5 2 3 4
 *
 */

#include <iostream>
using namespace std;
int n, p[20], vis[20];

bool isPrime(int x)
{
    if (x < 2) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int step)
{
    if (step > n) {
        if (isPrime(p[n] + 1)) {
            for (int i = 1; i <= n; i++) {
                cout << p[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (!vis[i] && isPrime(i + p[step - 1])) {
            p[step] = i;
            vis[i] = 1;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    p[1] = 1;
    dfs(2);
    return 0;
}
