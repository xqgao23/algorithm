/**
 * Description:
 *  有一个H行W列像素组成的图像，从上往下数第i行，从左往右数第j列的像素用a<i,j>来表示。
 *  图像只由黑白两种颜色组成，a<i,j>=0表示黑色，a<i,j>=1表示白色。
 *  现在小猴想要压缩这个图像，他打算按照如下方法压缩:
 *  如果存在相邻的两行完全一样，就删除其中一行。
 *  如果存在相邻的两列完全一样，就删除其中一列。
 *  重复以上操作直到无法再进行删除为止，可以证明最终结果和删除顺序无关。
 * 
 * Input:
 *  第一行，2个整数 H,W。
 *  接下来H行，每行W个整数，表示图像。0表示黑色，1表示白色，数与数之间用空格分隔。
 * 
 * Output:
 *  输出压缩后的图像，数与数之间用空格分隔。
 * 
 * Hints:
 *  1 <= H, W <= 50
 *
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
3 3
1 1 0
1 1 0
0 0 1
 * 
 *  output:
1 0
0 1
 *
 *  2):
 *  input:
6 6
1 0 1 1 0 0
0 1 1 1 0 0
1 1 0 0 1 1
1 1 0 0 1 1
1 1 0 0 1 1
0 0 1 1 1 1
 * 
 *  output:
1 0 1 0
0 1 1 0
1 1 0 1
0 0 1 1
 *
 *  3):
 *  input:
3 4
1 1 1 1
1 1 1 1
1 1 1 1
 * 
 *  output:
1
 *
 */

#include <cstdio>
#include <iostream>

using namespace std;

int h, w, a[55][55];
bool del_r[55], del_c[55];
// del_r[i]表示第i行有没有被删除，删除了标记为true，未删除标记为false
// del_c[i]表示第i列有没有被删除，删除了标记为true，未删除标记为false

// 检查第x行和第y行是否相同，相同返回true，不同返回false bool chk1(int x, int y)
bool chk1(int x, int y)
{
    for (int j = 1; j <= w; j++) {
        if (a[x][j] != a[y][j]) {
            return false;
        }
    }
    return true;
}

// 检查第x列和第y列是否相同，相同返回true，不同返回false bool chk2(int x, int y)
bool chk2(int x, int y)
{
    for (int i = 1; i <= h; i++) {
        if (a[i][x] != a[i][y]) {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> h >> w;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }
    
    // 若第i行和第i-1行相同则删除第i行
    for (int i = 2; i <= h; i++) {
        if (chk1(i, i - 1)) {
            del_r[i] = true;
        }
    }

    // 若第j列和第j-1列相同则删除第j列
    for (int j = 2; j <= w; j++) {
        if (chk2(j, j - 1)) {
            del_c[j] = true;
        }
    }

    for (int i = 1; i <= h; i++) {
        if (del_r[i]) {
            continue; // 若第i行删除 for (int j = 1; j <= w; j++)
        }
        for (int j = 1; j <= w; j++) {
            if (del_c[j]) {
                continue; // 若第j列删除
            }
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}