/**
 * Description:
 *  军训中,n个排各自组成了一个m×k的方阵，并依次入场. 现在，连长宣布每个方阵的第i行，第j列的人为方阵长，并让他们按方阵入场顺序在主席台前成一列，听候调遣. 以士兵编号的形式给出每个方阵的人员，输出方阵长所组成的队列.
 * 
 * Input:
 *  输入的第一行上有3个整数，依次为n,m,k.
 *  之后n×m行，每行k个以空格隔开的正整数，为按顺序入场的n个方阵的士兵编号. 最后还有一行，为两个整数
 *  n,m,k<=20, i <= m, j <= k.
 * 
 * Output:
 *  一行,n个整数，各位方阵长的编号
 * 
 * Hints:
 * 
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
3 4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
41 42 43 44
45 46 47 48
49 50 51 52
53 54 55 56
101 102 103 104
105 106 107 108
109 110 111 112
113 114 115 116
2 3
 * 
 *  output:
7 47 107
 *
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int num[25][25][25];

int main()
{
    int n, m, k;
    
    cin >> n >> m >> k;

    for(int t = 1; t <= n; t++) {
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= k; j++) {
                cin >> num[t][i][j];
            }
        }
    }

    int x, y;
    cin >> x >> y;
    for(int i = 1; i <= n; i++) {
        cout << num[i][x][y] << " ";
    }
    cout << endl;

    return 0;
}