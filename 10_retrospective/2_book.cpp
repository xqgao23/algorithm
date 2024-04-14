/**
 * Description:
 *  学校放寒假时，信息学奥赛辅导老师有1,2,3......x本书，要分给参加培训的x个人，每人只能选一本书，但是每人有两本喜欢的书。老师事先让每个人将自己喜欢的书填写在一张表上。然后根据他们填写的表来分配书本，希望设计一个程序帮助老师求出所有可能的分配方案，使每个学生都满意
 *
 * Input:
 *  第1行：一个数x
 *  第2行到第1+x行：每行两个数，表示第i个人喜欢的书的序号
 *
 * Output:
 *  只有一个数：总方案数total。
 *
 * Hints:
 *  x<=20
 */

/**
 *  Samples:
 *  1):
 *  input:
5
1 3
4 5
2 5
1 4
3 5
 *
 *  output:
2
 *
 */

#include <iostream>
using namespace std;
int x, a[30], b[30], vis[30], ans;

void dfs(int step)
{
    if (step > x) {
        ans++;
        return;
    }
    for (int i = 1; i <= x; i++) {
        if (!vis[i] && (a[step] == i || b[step] == i)) {
            vis[i] = 1;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    cin >> x;
    for (int i = 1; i <= x; i++) {
        cin >> a[i] >> b[i];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}