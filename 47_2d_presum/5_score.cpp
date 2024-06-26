/**
 * Description:
 *  我们已经举办了很多次月赛，现在老师想知道在最近两次月赛中，成绩达到一定分数的同学有多少人。
 *  共有n名同学参加了最近两次月赛，现在知道每个人两次月赛的成绩。给出两个值A和B，老师想知道，第1次月赛成绩大于等于A且第2次月赛成绩大于等于B的同学有多少人？数据包含多次询问。
 *
 * Input:
 *  第1行，1个正整数n，表示两次月赛都参加了的同学的人数。
 *  第2行，n个整数x1,x2,…,xn, xi表示第i名同学第1次月赛的成绩，数之间用空格分隔。
 *  第3行，n个整数y1,y2,…,yn,yi表示第i名同学第2次月赛的成绩，数之间用空格分隔。
 *  第4行，1个正整数Q，表示有Q次询问
 *  第5到Q+4行，每行两个整数A,B，第i+4行的两个整数A,B表示询问第1次月赛成绩大于等于A且第2次月赛成绩大于等于B的同学有的人数。
 *
 * Output:
 *  输出Q行，每行一个整数，第i行输出第i次询问的答案
 *
 * Hints:
 *  1≤N≤10<6>, 1≤Q≤10<5>, 0≤xi,yi,A,B≤500
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6
10 0 6 1 2 7
8 10 9 8 3 7
3
5 5
0 10
10 10
 *
 *  output:
3
1
0
 *
 */

#include <iostream>
using namespace std;
const int N = 1e6 + 10, M = 510;
int n, x[N], y[N], q, a[M][M], s[M][M];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        a[x[i] + 1][y[i] + 1]++;
    }
    for (int i = 1; i <= 501; i++) {
        for (int j = 1; j <= 501; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << s[501][501] - s[a][501] - s[501][b] + s[a][b] << endl;
    }
    return 0;
}