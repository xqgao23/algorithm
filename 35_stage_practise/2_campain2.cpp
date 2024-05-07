/**
 * Description:
 *  有 n 个候选人竞选班长，第 i 个人得票数为 ai，请你判断最后编号为多少的候选人得票数最高。
 *
 * Input:
 *  第 1 行，一个整数 n (n≤20)，表示1≤ai<10<100>)，表示第 i 个候选人的得票数，数据保证票数不会相同。
 *
 * Output:
 *  第 1 行，输出得票数最多的候选人的编号；
 *  第 2 行，输出该候选人的得票数。
 *
 * Hints:
 *  1≤T≤1000, 1≤a≤10<9>,0≤b≤10<9>,1≤p≤10<9>
 *  1≤ai,bi≤10<18>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4
377
62
110
9
 *
 *  output:
1
377
 *
 */

// 字符串string
#include <iostream>
using namespace std;
int n, x;
string s[25];

int cmp(string a, string b)
{
    if (a.size() != b.size()) {
        return a.size() > b.size();
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return a[i] > b[i];
        }
    }
    return 0;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        if (cmp(s[i], s[x])) {
            x = i;
        }
    }
    cout << x << endl;
    cout << s[x] << endl;
    return 0;
}