/**
 * Description:
 *  企鹅皮皮从小就是一个淘气的孩子。现在，他已经长大了，需要自己建一个新家了。
 *  你知道企鹅的家是用小石块在地面上铺出来的吧?为了让自己的家看起来更漂亮，皮皮找了很多种不同颜色的石块，并把它们铺成一圈一圈的：先找某种颜色的一颗放中心，在它周围铺上一圈第二种颜色的，再在周围铺上一圈第三种颜色的⋯
 *  这当然是一个漂亮的家。
 *  你能用你的知识，让计算机画出皮皮的家么?
 * 
 * Input:
 *  只有一个整数n(1<=n<=26)，表示皮皮的家是由多少圈石块组成的
 * 
 * Output:
 *  输出皮皮家的示意图。用字母"A"表示第一种颜色的石块，用字母"B"表示第二种颜色的石块⋯以此类推
 * 
 * Hints:
 *
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
4
 * 
 *  output:
DDDDDDD
DCCCCCD
DCBBBCD
DCBABCD
DCBBBCD
DCCCCCD
DDDDDDD
 *
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

char a[60][60];

int main()
{
    int n;
    cin >> n;

    for (int k = 1; k <= n; k++) {
        char c = 'A' + n - k;
        for (int i = k; i <= 2*n - k; i++) {
            for (int j = k; j <= 2*n - k; j++) {
                a[i][j] = c;
            }
        }
    }

    for (int i = 1; i <= 2*n-1; i++) {
        for (int j = 1; j <= 2*n-1; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}