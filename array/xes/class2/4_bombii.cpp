/**
 * Description:
 *  一个城市遭到了M次轰炸，每次都炸了一个每条边都与边界平行的矩形
 *  在轰炸后，有N个关键点，指挥官想知道，它们有没有受到过轰炸，如果有，被炸了几次，最后一次是第几轮。
 * 
 * Input:
 *  第一行，两个整数：M,N
 *  以下M行，每行四个整数：x1、y1、x2、y2，表示被轰炸的矩形的左上角坐标和右下角坐标（比如1 3 7 10就表示被轰炸的地方是从(1,3)到(7,10)的矩形）。
 *  再以下N行，每行两个整数，表示这个关键点的坐标。
 * 
 * Output:
 *  共N行，
 *  每行第一个字符为YES或NO，表示是否被轰炸，若为YES，在一个空格后为两个整数，表示被炸了几次和最后一次是第几轮
 * 
 * Hints:
 *  1<=N,M<=2000
 *  1<=x1,y1,x2,y2<=2147483647
 * 
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
1 1
1 1 10 10
11 11
 * 
 *  output:
NO
 *
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, x1[2010], x2[2010], y1[2010], y2[2010];

int main()
{
    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }
    
    for (int i = 1; i <= n; i++) {
        int x, y;
        
        cin >> x >> y;

        int cnt = 0, last;
        
        for (int j = 1; j <= m; j++) {
            if (x1[j] <= x && x <= x2[j] && y1[j] <= y && y <= y2[j]) {
                cnt++;
                last = j;
            }
        }
        if (cnt == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES " << cnt << " " << last << endl;
        }
    }
    
    return 0;
}