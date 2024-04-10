/**
 * Description:
 *  循环数是那些不包括0且没有重复数字的整数（比如81362）并且还应同时具有一个有趣的性质, 就像这个例子:
 *  如果你从最左边的数字开始（在这个例子中8）向右数最左边这个数（如果数到了最右边就回到最左边），你会停止在另一个新的数字（如果停在一个相同的数字上，这个数就不是循环数）。
 *  就像：8 1 3 6 2 从最左边接下去数8 个数字: 1 3 6 2 8 1 3 6 所以下一个数字是6
 *  重复这样做 (这次从6开始数6个数字) 并且你会停止在一个新的数字上: 2 8 1 3 6 2, 也就是2
 *  再这样做 （这次数两个）: 8 1
 *  再一次 （这次一个）: 3
 *  又一次: 6 2 8
 *  这时你回到了起点，在经过每个数字一次后回到起点的就是循环数。如果你经过每一个数字一次以后没有回到起点, 你的数字不是一个循环数。
 *  给你一个数字 m ，找出第一个比 m 大的循环数, 输出数据保证结果能用一个无符号长整型数 ∈[0,2<32>) 装下。 （追加提醒：循环数每个数位都必须要访问到）
 * 
 * Input:
 *  仅仅一行, 包括m
 * 
 * Output:
 *  仅仅一行，输出第一个比m大的循环数.
 * 
 * Hints:
 *  对于100% 的数据, 1 <= m <= 10<9>.
 * 
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
81361
 * 
 *  output:
81362
 *
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int a[15], vis[15];

bool check(int m)
{
    int n = 0;
    
    memset(vis, 0, sizeof vis);
    while (m != 0) {
        int x = m % 10;
        m /= 10;
        
        if (x == 0 || vis[x]) {
            return false;
        }
        
        vis[x] = true;
        a[n] = x;
        n++;
    }

    for (int i = 0; i < n / 2; i++) {
        swap(a[i], a[n - 1 - i]);
    }

    memset(vis, 0, sizeof vis);
    int p = 0;
    for (int i = 0; i <= n - 1; i++) {
        p = (p + a[p]) % n;
        if (vis[p]) {
            return false;
        }
        vis[p] = 1;
    }
    
    return true;
}

int main()
{
    int m;
    cin >> m;
    
    while(true) {
        m++;
        if (check(m)) {
            break;
        }
    }

    cout << m << endl;

    return 0;
}