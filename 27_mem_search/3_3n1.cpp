/**
 * Description:
 *  在正整数集上定义如下的迭代序列:n→n/2（若n为偶数）n→3n+1 （若n为奇数）
 *  从10开始应用上述规则，我们可以生成如下的序列:10→5→16→8→4→2→1
 *  可以看出这个序列(从10开始到1结束) 共有7项. 尽管还没有被证明, 但我们普遍认为,
 * 从任何数开始最终都能迭代至1. 给出多组询问, 每组询问有一个正整数x (x<=10<7>),
 * 你需要回答从x开始到1的序列的长度. 注: 序列开始生成后允许其中的项超过10<7>
 *
 * Input:
 *  第一行一个正整数Q,表示询问次数
 *  接下来Q行, 每行一个正整数xi
 *
 * Output:
 *  对每个询问，输出以xi开始到1的序列长度
 *
 * Hints:
 *  1≤Q≤10<6>, 1≤x≤10<7>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
2
5
13
 *
 *  output:
6
10
 *
 */

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int q, x, f[10000010];

int dfs(long long n)
{
    if (n > 1e7) {
        if (n % 2 == 0) {
            return dfs(n / 2) + 1;
        } else {
            return dfs(3 * n + 1) + 1;
        }
    }
    if (f[n] != -1) {
        return f[n];
    }
    if (n == 1) {
        return f[n] = 1;
    }
    if (n % 2 == 0) {
        return f[n] = dfs(n / 2) + 1;
    } else {
        return f[n] = dfs(3 * n + 1) + 1;
    }
}

int main()
{
    cin >> q;
    memset(f, -1, sizeof f);
    while (q--) {
        cin >> x;
        cout << dfs(x) << endl;
    }
    return 0;
}