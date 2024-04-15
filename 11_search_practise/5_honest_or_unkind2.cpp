/**
 * Description:
 *  N个人以1∼N编号。分为一定会说真话的"诚实的人"，和有可能说谎的"不诚实的人"两种。
 *  第i个人做出了Ai条证言，第i个人做出的第j条证言用两个整数xij,
 * yij表示。yij=1代表证言是"第xij个人是诚实的人”，yij=0代表证言是"第xij个人是不诚实的人"。
 *  N个人中，"诚实的人"最多有多少个？
 *
 * Input:
 *  第1行，1个正整数N
 *  接下来N组数据，第i组数据代表第i个人
 *  每组数据的第1行是1个整数Ai
 *  接下来Ai行，每行两个整数xij,yij
 *
 * Output:
 *  "诚实的人"的最多人数
 *
 * Hints:
 *  1<=N<=15, 0<=Ai<=N-1 1<=xij<=N;xij!=i;xij1!=xij2(j1!=j2) yij=0,1
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
1
2 1
1
1 1
1
2 0
 *
 *  output:
2
 *
 *  2):
 *  input:
3
2
2 1
3 0
2
3 1
1 0
2
1 1
2 0
 *
 *  output:
0
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, a[20], x[20][20], y[20][20], p[20], ans;

bool check()
{
    for (int i = 1; i <= n; i++) {
        if (p[i]) {
            for (int j = 1; j <= a[i]; j++) {
                if (p[x[i][j]] != y[i][j]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void dfs(int step, int c)
{
    if (step > n) {
        if (check()) {
            ans = max(ans, c);
        }
        return;
    }
    p[step] = 1;
    dfs(step + 1, c + 1);
    p[step] = 0;
    dfs(step + 1, c);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j <= a[i]; j++) {
            cin >> x[i][j] >> y[i][j];
        }
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}