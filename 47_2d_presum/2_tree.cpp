/**
 * Description:
 *  某校大门外长度为L的马路上有一排树，每两棵相邻的树之间的间隔都是1米。我们可以把马路看成一个数轴，马路的一端在数轴0的位置，另一端在L的位置；数轴上的每个整数点，即0,1,2,⋯,L都种有一棵树。
 *  由于马路上有一些区域要用来建地铁。这些区域用它们在数轴上的起始点和终止点表示。已知任一区域的起始点和终止点的坐标都是整数，区域之间可能有重合的部分。现在要把这些区域中的树（包括区域端点处的两棵树）移走。你的任务是计算将这些树都移走后，马路上还有多少棵树。
 *
 * Input:
 *  第一行有2个整数L(1≤L≤10<6>)和M(1≤M≤10<5>)，L代表马路的长度，M代表区域的数目，L和M之间用一个空格隔开。
 *  接下来的M行每行包含2个不同的整数，用一个空格隔开，表示一个区域的起始点和终止点的坐标。
 *
 * Output:
 *  1个整数，表示马路上剩余的树的数目。
 *
 * Hints:
 *  1≤n,m≤1000000, 1≤l≤r≤n, -1000≤c,ai≤1000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
500 3
150 300
100 200
470 471
 *
 *  output:
298
 *
 */

#include <iostream>
using namespace std;
int L, m, d[1000010], ans;

int main()
{
    cin >> L >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        d[a + 1]++, d[b + 2]--;
    }
    for (int i = 1; i <= L + 1; i++) {
        d[i] += d[i - 1];
        if (d[i] == 0) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}