/**
 * Description:
 *  某地临时居民想获得长期居住权就必须申请拿到红牌。获得红牌的过程是相当复杂 ，一共包括N个步骤。每一步骤都由政府的某个工作人员负责检查你所提交的材料是否符合条件。为了加快进程，每一步政府都派了M个工作人员来检查材料。不幸的是，并不是每一个工作人员效率都很高。尽管如此，为了体现“公开政府”的政策，政府部门把每一个工作人员的处理一个申请所花天数都对外界公开。
 *  为了防止所有申请人都到效率高的工作人员去申请。这M×N个工作人员被分成M个小组。每一组在每一步都有一个工作人员。申请人可以选择任意一个小组也可以更换小组。但是更换小组是很严格的，一定要相邻两个步骤之间来更换，而不能在某一步骤已经开始但还没结束的时候提出更换，并且也只能从原来的小组I更换到小组I+1,当然从小组M可以更换到小组1。对更换小组的次数没有限制。
 *  例如：下面是3个小组，每个小组4个步骤工作天数：
 *  小组1 : 2,6,1,8
 *  小组2 : 3,6,2,6
 *  小组3 : 4,2,3,6
 *  例子中，可以选择小组1来完成整个过程一共花了2+6+1+8=17天，也可以从小组2开始第一步，然后第二步更换到小组3，第三步到小组1，第四步再到小组2，这样一共花了3+2+1+6=12天。你可以发现没有比这样效率更高的选择。
 *  你的任务是求出完成申请所花最少天数。
 *
 * Input:
 *  第一行是两个正整数N和M,表示步数和小组数。接下来有M行，每行N个非负整数，第i+1(1≤i≤M)行的第j个数表示小组i完成第j步所花的天数，天数都不超过1000000。
 *
 * Output:
 *  一个正整数，为完成所有步所需最少天数。
 *
 * Hints:
 *  N,M≤2000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
4 3
2 6 1 8
3 6 2 6
4 2 3 6
 *
 *  output:
12
 *
 */

#include <algorithm>
#include <iostream>
using namespace std;
int n, m, a[2010][2010], f[2010][2010];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[j][i];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = min(f[i - 1][j], f[i - 1][((j - 1) % m + m - 1) % m + 1]) + a[i][j];
        }
    }
    int ans = 1e9;
    for (int j = 1; j <= m; j++) {
        ans = min(ans, f[n][j]);
    }
    cout << ans << endl;
    return 0;
}