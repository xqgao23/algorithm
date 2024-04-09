/**
 * Description:
 *  Farmer John为了让自己从无穷无尽的犁田工作中解放出来，于是买了个新机器人帮助他犁田。这个机器人可以完成犁田的任务，可惜有一个小小的缺点：这个犁田机器人一次只能犁一个边的长度是整数的长方形的田地。
 *  因为FJ的田地有树和其它障碍物，所以FJ设定机器人去犁很多不同的长方形。这些长方形允许重叠。他给机器人下了 I 个指令，每个指令包含一个要犁长方形的地。这片田地由长方形的左下角和右上角坐标决定。他很好奇最后到底有多少个方格的地被犁过了。
 *  一般来说，田地被分割为很多小方格。这些方格的边和x轴或y轴平行。田地的宽度为X个方格，高度为Y个方格 (1 <= X <= 240;1 <= Y <= 240)。
 *  FJ执行了I(1<=I<=200) 个指令，每个指令包含 4 个整数：Xll,Yll,Xur,Yur(1<=Xll<=Xur;Xll<=Xur<=X;1<=Yll<=Yur;Yll<=Yur<=Y), 分别是要犁的长方形的左下角坐标和右上角坐标。机器人会犁所有的横坐标在 Xll...Xur 并且纵坐标在 Yll...Yur 范围内的所有方格的地。可能这个长方形会比你想象的多一行一列（就是说从第 Xll 列到第 Xur 列一共有 Xur−Xll+1 列而不是 Xur−Xll 列）。
 * 
 * Input:
 *  第1行3个整数X Y I.
 *  第2行到第I+1行: 第i行描述第i次犁田指令, 每行4个整数Xll,Yll,Xur,Yur。
 * 
 * Output:
 *  一个整数，代表被犁过的格子数。
 * 
 * Hints:
 *
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
6 4 2
1 1 2 4
1 3 5 4
 * 
 *  output:
14
 *
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

bool flag[250][250];

int main()
{
    int n, m, q;

    cin >> n >> m >> q;

    int cnt = 0;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (!flag[i][j]) {
                    cnt++;
                    flag[i][j] = true; 
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}