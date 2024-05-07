/**
 * Description:
 *  木材厂有一些原木，现在想把这些木头切割成一些长度相同的小段木头（木头有可能有剩余），需要得到的小段的数目是给定的。当然，我们希望得到的小段木头越长越好，你的任务是计算能够得到的小段木头的最大长度。木头长度的单位是cm。原木的长度都是正整数，我们要求切割得到的小段木头的长度也是正整数。
 *  例如有两根原木长度分别为11和21，要求切割成到等长的6段，很明显能切割出来的小段木头长度最长为5.
 *
 * Input:
 *  第一行是两个正整数N和K(1≤N≤100000，1≤K≤100000000)，N是原木的数目，K是需要得到的小段的数目。
 *  接下来的N行，每行有一个Li，是1到100000000之间的正整数，表示一根原木的长度。
 *
 * Output:
 *  能够切割得到的小段的最大长度。如果连1cm长的小段都切不出来，输出"0"。
 *
 * Hints:
 *  1≤n,Q≤10<5>
 *  1≤ai,bi≤10<18>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3 7
232
124
456
 *
 *  output:
114
 *
 */

#include <iostream>
using namespace std;
int n, k, len[100010];

bool check(int m)
{
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += len[i] / m;
    }
    return cnt >= k;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> len[i];
    }
    int l = 0, r = 100000000, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}