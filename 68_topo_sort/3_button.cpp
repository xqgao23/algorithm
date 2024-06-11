/**
 * Description:
 *  小K在遗迹探险时遇到了N个按钮，刚开始所有按钮都处于开状态，小Ｋ的经验告诉他把所有按钮都关上会有"好事"发生，可是有些按钮按下时会让其他一些已经闭合的按钮弹开。经过研究，每个按钮都对应着一个固定的弹开集合，这个按钮按下时，弹开集合中所有的按钮都会变为开状态。现在小Ｋ想知道是否能让所有的按钮变为闭状态。如果能，打印最少步数以及方案，否则，打印"no solution"。
 *
 * Input:
 *  第一行一个整数N，表示N个按钮；接下来N行，表示编号为1到N个按钮的弹开集合；格式为mi,B1,B2,B3,Bmi，表示编号为i的按钮按下，会让编号为B1,B2,B3,Bmi的按钮弹开。
 *
 * Output:
 *  如果无解，输出"no solution"，否则，请正常输出：第一行输出最少步数ans；第二行输出用空格隔开的ans个数，表示按顺序按下编号为这些数的按钮就可以解决。如果有多种方案，请输出字典序最小的方案。
 *
 * Hints:
 *  1≤n≤30000，0≤m1+m2+m3+...+mn≤1000000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6
2 2 3
0
2 4 5
0
0
0
 *
 *  output:
6
1 2 3 4 5 6
 *
 */

// 按下一个按钮时，要保证所有能够使这个按钮弹开的按钮都已经被按下。
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 3e4 + 10;
int n, rud[N], ans[N], cnt;
vector<int> g[N];

void topo_sort()
{
    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
        if (rud[i] == 0)
            q.push(-i);
    while (q.size()) {
        int x = -q.top();
        q.pop();
        ans[++cnt] = x;
        for (auto y : g[x])
            if (--rud[y] == 0)
                q.push(-y);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int m, b;
        cin >> m;
        for (int j = 1; j <= m; j++) {
            cin >> b;
            g[i].push_back(b);
            rud[b]++;
        }
    }
    topo_sort();
    if (cnt != n) {
        cout << "no solution" << endl;
        return 0;
    }
    cout << n << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
    return 0;
}