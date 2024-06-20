/**
 * Description:
 *  农民约翰的牛奶生产和运输是一个复杂的过程，他用挤奶器给他的若干头奶牛挤奶，然后流入管道。
 *  每一个管道把一台挤奶器和一个接口连接起来，每个接口可能连有一台或多台挤奶器（这样几个管道里的牛奶就汇合了）。然后牛奶通过附加管道（连在各个接口之间的管道）直到流到中央管道，通向储存室。 然后这些牛奶反过来通过管道分流到各个牛奶桶，最后被运至市场。
 *  约翰发现对于牛奶来说，最多只有一种方式从一个接口流到另一个接口。并且由于约翰是一个高效率的人，他需要确保每一个管道都有牛奶经过，也就是说，没有多余的管道。
 *  如果我们把每个挤奶机、接口和奶罐都看成一个节点，就共有 N 个节点，输入有序的节点对Ai  和 Bi ，代表牛奶从 Ai节点流到 Bi节点。如果没有相对应的头节点，那就说明这是一个挤奶器，同样的如果没有对应的尾节点，则这是一个奶罐。
 *  这几个月巧克力牛奶的需求量激增，所以约翰想要在某一个接口处安装一个巧克力混合器，把所有牛奶都变成巧克力牛奶，为了节约，约翰只买了一个巧克力混合器。所以他想把这个东西放到一个所有牛奶都能经过的接口，保证一定有这种接口存在。
 *  请你帮助约翰找到这样的节点（注意：不能把巧克力混合器放在挤奶机里）。
 *
 * Input:
 *  第 1 行一个整数 N。
 *  第 2 到第 N 行：包含空格分隔的两个整数，描述第 i 个管道连接的两个节点：Ai和 Bi 。
 *
 * Output:
 *  生成若干行，每行一个整数，升序输出每个可以安装巧克力混合器的节点。
 *
 * Hints:
 *  2 <= N <= 100,000
 *
 */

/**
 *  Samples:
 *  1):
 *  input:
9 
1 4 
3 5 
2 4 
5 6 
6 7 
7 8 
4 6 
7 9
 *
 *  output:
6
7
 *
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int n, ind[N], cnt[N], vis[N], s, ans;
vector<int> g[N];

void topo_sort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!ind[i]) {
            q.push(i);
            cnt[i] = 1;
            vis[i] = 1;
            s++;
        }
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (g[x].size() > 1)
            continue;
        for (auto y : g[x]) {
            cnt[y] += cnt[x];
            if (--ind[y] == 0)
                q.push(y);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        ind[b]++;
    }
    topo_sort();
    for (int i = 1; i <= n; i++)
        if (!vis[i] && cnt[i] == s)
            cout << i << endl;
    return 0;
}
