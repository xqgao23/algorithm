/**
 * Description:
 *  有 2<n>(n≤7) 个国家参加世界杯决赛圈且进入淘汰赛环节。我已经知道各个国家的能力值，且都不相等。能力值高的国家和能力值低的国家踢比赛时高者获胜。1 号国家和 2 号国家踢一场比赛，胜者晋级。3 号国家和 4 号国家也踢一场，胜者晋级……晋级后的国家用相同的方法继续完成赛程，直到决出冠军。给出各个国家的能力值，请问亚军是哪个国家？
 *
 * Input:
 *  第一行，一个正整数n；
 *  第二行，每行2<n>个数表示每个国家的能力值。
 *
 * Output:
 *  输出一行，共一个数，表示获得亚军的是第几个国家。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
4 2 3 1 10 5 9 7
 *
 *  output:
1
 *
 */

#include <iostream>
#include <string>
using namespace std;

double dfs(string s)
{
    int p1 = 0, p2 = 0;
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '-' || s[i] == '+') {
            p1 = i;
        }
        if (s[i] == '*' || s[i] == '/') {
            p2 = i;
        }
    }
    if (p1 > 0) {
        double x = dfs(s.substr(0, p1)), y = dfs(s.substr(p1 + 1));
        if (s[p1] == '+') {
            return x + y;
        }
        return x - y;
    } else if (p2 > 0) {
        double x = dfs(s.substr(0, p2)), y = dfs(s.substr(p2 + 1));
        if (s[p2] == '*') {
            return x * y;
        }
        return x / y;
    } else {
        return stod(s);
    }
}

int main()
{
    string s;
    cin >> s;
    printf("%.3lf\n", dfs(s));
    return 0;
}