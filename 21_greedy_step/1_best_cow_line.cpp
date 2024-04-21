/**
 * Description:
 *  FJ带着他的N头奶牛去参加年度最佳农场评选.
 *  评选的组织者会将来自同一个农场的奶牛按照列队的顺序进行登记,
 * 并且只登记每只奶牛名字的首字母. 如果FJ让Bessie, Sylvia, 和
 * Dora按这个顺序排好队,FJ的农场就会被登记为字符串"BSD".
 * 登记后所得到的的字符串的字典序最小的农场将会被评为年度最佳农场.(字典序是指从前到后比较两个字符串大小的方法，首先比较第一个字符，如果不同则第1个字符较小的字符串更小，如果相同，继续比较第2个字符...如此继续，来比较整个字符串的大小)
 *  FJ已经将奶牛排好队, 现在他要进行以下两种操作共N次, 将奶牛排一个新队:
 *  1.将原队伍排第一的奶牛加入新队伍的末尾
 *  2.将原队伍排最后的奶牛加入新队伍的末尾
 *  FJ想要通过以上两种操作, 构造字典序尽可能小的新队伍.
 * 输入原队伍的顺序，输出字典序最小的新队伍.
 *
 * Input:
 *  第一行一个正整数N, 表示奶牛的数量(N≤2000)
 *  接下来N行，每行一个大写英文字母, 代表原队伍每只奶牛的名字首字母.
 *
 * Output:
 *  输出字典序最小的新队伍, 每输出80个字符就换行.
 *
 * Hints:
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
6
A
C
D
B
C
B
 *
 *  output:
ABCBCD
 *
 */

#include <iostream>
using namespace std;
int n;
char a[2010], b[2010];

bool check(int l, int r)
{
    while (l <= r) {
        if (a[l] != a[r]) {
            return a[l] < a[r];
        }
        l++, r--;
    }
    return false;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = n;
    for (int i = 1; i <= n; i++) {
        if (check(l, r)) {
            b[i] = a[l++];
        } else {
            b[i] = a[r--];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i];
        if (i % 80 == 0) {
            cout << endl;
        }
    }
    return 0;
}