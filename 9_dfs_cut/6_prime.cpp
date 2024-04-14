/**
 * Description:
 *  农民约翰的母牛总是产生最好的肋骨. 你能通过农民约翰和美国农业部标记在每根肋骨上的数字认出它们.
 *  农民约翰确定他卖给买方的是真正的质数肋骨, 是因为从右边开始切下肋骨, 每次还剩下的肋骨上的数字都组成一个质数.
 *  举例来说:对于从左到右的四根肋骨7,3,3,1,全部肋骨上的数字7331是质数;三根肋骨 733 是质数;二根肋骨73 是质数;当然，最后一根肋骨 7 也是质数. 因此7331 被叫做长度 4 的特殊质数.
 *  写一个程序对给定的肋骨的数目n,求出所有的特殊质数.
 *
 * Input:
 *  一个正整数n
 *
 * Output:
 *  输出为若干行:
 *  按从小到大的顺序输出长度为n的特殊质数，每行一个
 *
 * Hints:
 *  1<=n<=8
 */

/**
 *  Samples:
 *  1):
 *  input:
4
 *
 *  output:
2333
2339
2393
2399
2939
3119
3137
3733
3739
3793
3797
5939
7193
7331
7333
7393
 *
 */

#include <iostream>
using namespace std;
int n;

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

void dfs(int step, int x)
{
    if (step > n) {
        cout << x << endl;
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (isPrime(x * 10 + i)) {
            dfs(step + 1, x*10+i);
        }
    }
}

int main()
{
    cin >> n;
    dfs(1, 0);
    return 0;
}