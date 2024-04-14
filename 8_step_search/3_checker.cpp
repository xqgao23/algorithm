/**
 * Description:
 *  记S(A)是大小为n的集合A中所有元素的和。若任取A的任意两个非空子集B和C都满足下列条件，我们称A是一个特殊的和集：S(B)！=S(C)；也就是说，任意子集的和不相同。
 *  例如，{4,5,6,7,8}不是一个特殊和集，因为4+5+6=7+8；{14,15,16,17,18}也不是一个特殊和集，因为14+18=15+17；而
 *  {14,15,16,27,38}满足上述条件。
 *  输入中包含了若干组3至15个元素的集合，对每一个集合，判断是否满足条件。
 *
 * Input:
 *  第1行，1个正整数T，表示有T个集合
 *  接下来T行，每行第1个数为n，表示集合中元素的个数，后面n个数表示集合的元素a1,…,an.
 *
 * Output:
 *  对每个集合，判断是否满足条件，满足输出Yes，不满足输出No
 *
 * Hints:
 *  1<=T<=20, 2<=n<=15, 1<=ai<=10<8>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
5 4 5 6 7 8
5 14 15 16 17 18
5 14 15 16 27 38
 *
 *  output:
No
No
Yes
 *
 */

#include <algorithm>
#include <iostream>

using namespace std;
int t, n, a[20], p[20], c[32770], cnt;

void dfs(int step)
{
    if (step > n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (p[i]) {
                sum += a[i];
            }
        }
        c[++cnt] = sum;
        return;
    }
    for (int i = 0; i <= 1; i++) {
        p[step] = i;
        dfs(step + 1);
    }
}

bool check()
{
    sort(c + 1, c + cnt + 1);
    for (int i = 2; i <= cnt; i++) {
        if (c[i] == c[i - 1]) {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cnt = 0;
        dfs(1);
        if (check()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}