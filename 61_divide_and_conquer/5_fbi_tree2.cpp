/**
 * Description:
 *  我们可以把由“0”和“1”组成的字符串分为三类：全“0”串称为B串，全“1”串称为I串，既含“0”又含“1”的串则称为F串FBI树是一种二叉树，它的结点类型也包括F结点，B结点和I结点三种。由一个长度为2<N>的“01”串S可以构造出一棵FBI树T，递归的构造方法如下：
 *  1. T的根结点为R，其类型与串S的类型相同；
 *  2. 若串S的长度大于1，将串S从中间分开，分为等长的左右子串S1和S2；由左子串S1构造R的左子树T1，由右子串S2构造R的右子树T2
 *  现在给定一个长度为2<N>的“01”串，请用上述构造方法构造出一棵FBI树，并输出它的后序遍历序列。
 *
 * Input:
 *  第一行是一个整数N(0≤N≤10)，
 *  第二行是一个长度为2<N>的“01”串
 *
 * Output:
 *  一个字符串，即FBI树的后序遍历序列。
 *
 * Hints:
 *  N≤10
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
3
10001011
 *
 *  output:
IBFBBBFIBFIIIFF
 *
 */

// 方法二
#include <iostream>
using namespace std;

string dfs(string s)
{
    string ans = "";
    if (s.size() > 1) {
        ans = dfs(s.substr(0, s.size() / 2)) + dfs(s.substr(s.size() / 2));
    }
    if (s.find('1') == -1) {
        return ans + "B";
    }
    if (s.find("0") == -1) {
        return ans + "I";
    }
    return ans + "F";
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    cout << dfs(s) << endl;
    return 0;
}