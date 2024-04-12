/**
 * Description:
 *  香蕉大陆有三个强大的国家，分别是A国、B国、C国，三国之间互相为交战状态，其中更是有n个兵家必争之地。这n个地点从西向东排成一线，在第i个地点中三个国家分别派遣的兵力为ai,bi,ci。如果在第i个地点，有某个国家的兵力同时大于其他两个国家，它就可以占领该地点。
 *  小猴作为杰出的战略家，总能准确地预测出下场战争的交战区域[l,r]，表示下次战场会由西向东从第l个地点覆盖到第r个地点 。而第l个地点到第r个地点范围内，占领的地点数量最多的国家，会成为本场战争的战胜国。如果有两个或以上国家占领的地点数量都是最多的，则本场战争的结果为平局。
 *  现在，小猴一共会预测m场战争，请你帮他求出每场战争的结果。
 * 
 * Input:
 *  输入共 n+m+1 行，第一行输入包含两个正整数n和m，表示地点的数量n，以及小猴预测的战争数量m。
 *  接下来的n行每行包含三个正整数ai,bi,ci，分别表示第i个地点中三个国家派遣的兵力。
 *  接下来的m行每行包含两个正整数l,r表示第i场战争的交战区域从第l个地点到第r个地点。
 * 
 * Output:
 *  输出共 m 行，每行包含一个字符，对于第i场战争，如果A国获胜则输出'A'，B国获胜输出'B'，C国获胜输出'C'，其他情况则输出'D'。
 * 
 * Hints:
 *  1 <= n,m <= 10<5>, 1 <= l,r <= n, 1 <= ai,bi,ci <= 10<18>, ai!=bi,bi!=ci,ci!=ai
 *
 */ 
 
/**
 *  Samples:
 *  1):
 *  input:
6 4
1 6 0
2 5 0
3 4 7
4 3 7
5 2 0
6 1 0
1 6
1 3
5 6
2 5
 * 
 *  output:
D
B
A
C
 *
 */

// 暴力枚举 40分
#include <iostream>

using namespace std;

const int N = 100005;

int n, m;
int sa[N], sb[N], sc[N];// 前缀和数组
// sa[i]表示前i个地点中，A国占领的地点数量
// sb[i]表示前i个地点中，B国占领的地点数量 
// sc[i]表示前i个地点中，C国占领的地点数量

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        long long a, b, c; // a,b,c分别表示第i个地点中三个国家派遣的兵力

        cin >> a >> b >> c;
        sa[i] = sa[i - 1] + (a > b & a > c); // 第i个地点，A国兵力最多
        sb[i] = sb[i - 1] + (b > a & b > c); // 第i个地点，B国兵力最多
        sc[i] = sc[i - 1] + (c > b & c > a); // 第i个地点，C国兵力最多
    }

    for (int i = 1; i <= m; i++) {  // m场战争
        int l, r;
        cin >> l >> r;

        int suma = sa[r] - sa[l - 1]; // 第l至r个地点中，A国占领的地点数量
        int sumb = sb[r] - sb[l - 1]; // 第l至r个地点中，B国占领的地点数量
        int sumc = sc[r] - sc[l - 1]; // 第l至r个地点中，C国占领的地点数量

        if (suma > sumb && suma > sumc) {
            cout << "A" << endl;
        } else if (sumb > suma && sumb > sumc) {
            cout << "B" << endl;
        } else if (sumc > suma && sumc > sumb) {
            cout << "C" << endl;
        } else {
            cout << "D" << endl;
        }
    }

    return 0;
}