/**
 * Description:
 *  如上图所示，由正整数1, 2, 3, ...组成了一棵无限大的二叉树。从某一个结点到根结点（编号是1的结点）都有一条唯一的路径，比如从10到根结点的路径是(10, 5, 2, 1)，从4到根结点的路径是(4, 2, 1)，从根结点1到根结点的路径上只包含一个结点1，因此路径就是(1)。对于两个结点x和y，假设他们到根结点的路径分别是(x1,x2, ... ,1)和(y1,y2, ... ,1)（这里显然有x=x1 y=y1），那么必然存在两个正整数i和j，使得从xi 和yj开始，有xi = yj, xi+1=yj+1,xi+2=yj+2现在的问题就是，给定x和y，要求xi（也就是yj）。
 *
 * Input:
 *  输入只有一行，包括两个正整数x和y，这两个正整数都不大于1000。
 *
 * Output:
 *  输出只有一个正整数xi
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
10 4
 *
 *  output:
2
 *
 */

#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    while (x != y) {
        if (x > y) {
            x /= 2;
        } else {
            y /= 2;
        }
    }
    cout << x << endl;
    return 0;
}