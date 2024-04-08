/**
 * Description:
 *  冷月老师每周都会给同学们布置作业.
 *  冷月老师的班上有n名同学，本周冷月老师共布置了m道题目. 给定每位同学每道题目的得分，冷月老师给每位同学发放成绩单，包含他自己的成绩和班级平均分.
 * 
 * Input:
 *  输入由n+1行组成
 *  第一行为两个正整数n,m(n<=30,m<=10)
 *  接下来的n行每行有m个正整数，代表第n名同学每道题目的得分
 * 
 * Output:
 *  输入由n行组成
 *  第i行包含第i个同学m道题每题得分及每题班级平均分(平均分四舍五入保留2位小数)
 *
 * Hints:
 *
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
3 4
80 90 90 50
100 100 100 100
60 60 100 30
 * 
 *  output:
80(80.00) 90(83.33) 90(96.67) 50(60.00)
100(80.00) 100(83.33) 100(96.67) 100(60.00)
60(80.00) 60(83.33) 100(96.67) 30(60.00)
 *
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[35][15];
double b[15];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            b[j] += a[i][j];
        }
    }

    for (int j = 1; j <= m; j++) {
        b[j] /= n;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d(%.2lf) ", a[i][j], b[j]);
            // cout << a[i][j] << "(" << fixed << setprecision(2) << b[j] << ") ";
        }
        cout << endl;
    }
    return 0;
}