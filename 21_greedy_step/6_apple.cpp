/**
 * Description:
 *  你想要吃X个红苹果和Y个绿苹果。
 *  目前有A个红苹果，美味度分别是p1,p2,…,pA;B个绿苹果，美味度分别是q1,q2,…,qB；C个无色苹果，美味度分别是r1,r2,…,rC。
 *  无色苹果可以染色成红苹果或者绿苹果。选择若干个（可以是0个）无色苹果，染成合适的颜色，使得你可以吃到X个红苹果和Y个绿苹果，并且使得吃到的苹果的美味度总和最大。输出最大的总和。
 *
 * Input:
 *  第1行，5个整数X，Y，A，B，C
 *  第2行，A个整数p1,p2,...,pA
 *  第3行，B个整数q1,q2,...,qB
 *  第4行，C个整数r1,r2,...,rC
 *
 * Output:
 *  可以吃到的最大的美味度总和
 *
 * Hints:
 *  1≤X≤A≤10<5>, 1≤Y≤B≤10<5>, 1≤C≤10<5>, 1<=pi,qi,ri<=10<9>
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
1 2 2 2 1
2 4
5 1
3
 *
 *  output:
12
 *
 *  2):
 *  input:
2 2 2 2 2
8 6
9 1
2 1
 *
 *  output:
25
 *
 *  3):
 *  input:
2 2 4 4 4
11 12 13 14
21 22 23 24
1 2 3 4
 *
 *  output:
74
 *
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int x, y, a, b, c;
struct node {
    int c, v;
} t[300010];

bool cmp(node x, node y) { return x.v > y.v; }

int main()
{
    cin >> x >> y >> a >> b >> c;
    for (int i = 1; i <= a; i++) {
        cin >> t[i].v;
        t[i].c = 1;
    }
    for (int i = a + 1; i <= a + b; i++) {
        cin >> t[i].v;
        t[i].c = 2;
    }
    for (int i = a + b + 1; i <= a + b + c; i++) {
        cin >> t[i].v;
        t[i].c = 3;
    }

    sort(t + 1, t + a + b + c + 1, cmp);
    int A = 0, B = 0, R = 0;
    long long ans = 0;
    for (int i = 1; i <= a + b + c; i++) {
        if (A + B + R == x + y) {
            break;
        }

        if (t[i].c == 1 && A < x) {
            ans += t[i].v;
            A++;
        } else if (t[i].c == 2 && B < y) {
            ans += t[i].v;
            B++;
        } else if (t[i].c == 3) {
            ans += t[i].v;
            R++;
        }
    }
    cout << ans << endl;
    return 0;
}