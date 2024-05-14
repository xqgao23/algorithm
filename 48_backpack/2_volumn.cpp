/**
 * Description:
 *  农夫约翰完全忘了他有多少头牛了！他不好意思到牧场里去数牛，因为他不想让牛意识到他的健忘。取而代之的是，他决定在奶牛聚集的牧场里安装麦克风，秘密计算出他能从中听到的所有牛叫声的总音量，以便以此确定奶牛的数量。FJ的N(1≤N≤100)个牧场都是沿着一条笔直的道路分布的。每一个牧场可能有许多种品种的奶牛；FJ拥有B(1≤B≤20)个品种的奶牛，而第i种奶牛的叫声音量为vi(1≤Vi≤100)。此外，有一股强风沿着道路吹来，将牛的叫声从左往右传递，如果某个牧场的总音量x>0，那么它将传递x−1的音量到右边的下一个牧场。这就意味着，一个牧场里的总音量是处在该牧场的奶牛所发出的音量加上左边前一个牧场的总音量−1。数据保证，每一个牧场内由该牧场所有奶牛所发出的总音量最多为10<5>
 *  给出FJ在每个牧场能监听到的总音量，请计算FJ最小可能拥有的奶牛数量。
 *
 * Input:
 *  第一行包含两个整数N和B。
 *  接下来B行，每行一个整数，表示第i种奶牛的叫声音量vi
 *  再接下来N行，每行一个整数，表示从左到右第i个牧场能监听到的总音量。
 *
 * Output:
 *  输出一行，表示FJ拥有的最小奶牛数量。
 *  如果不存在方案，使得其满足监听到的音量序列，输出−1。
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
5 2
5
7
0
17
16
20
19
 *
 *  output:
4
 *
 *  2):
 *  input:
1 1000000000
1000000000 10
 *
 *  output:
10
 *
 *  3):
 *  input:
6 15
6 5
5 6
6 4
6 6
3 5
7 2
 *
 *  output:
17
 *
 */

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, b, v[25], sv[110], f[100010];

int main()
{
    cin >> n >> b;
    for (int i = 1; i <= b; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> sv[i];
    }
    for (int i = n; i >= 1; i--) {
        if (sv[i - 1]) {
            sv[i] -= sv[i - 1] - 1;
        }
    }
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    
    for (int i = 1; i <= b; i++) {
        for (int j = v[i]; j <= 100000; j++) {
            f[j] = min(f[j], f[j - v[i]] + 1);
        }
    }
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (f[sv[i]] == f[100009]) {
            ans = -1;
            break;
        }
        ans += f[sv[i]];
    }
    cout << ans << endl;
    return 0;
}