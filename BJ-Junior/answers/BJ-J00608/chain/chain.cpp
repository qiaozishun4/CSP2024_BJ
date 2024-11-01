#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


map<int, vector<int> > G[100005];
vector<int> s[100005];
int r[100005], c[100005];
vector<int> AccessRound[100005];


struct Node
{
    int person, number, round;
};


int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
//    freopen("chain2.in", "r", stdin);

    int T;
    cin >> T;

    for(int t = 1, n, k, q; t <= T; ++t)
    {
        cin >> n >> k >> q;
        for(int i = 1; i <= n; ++i)
        {
            G[i].clear();
            s[i].clear();
        }

        for(int i = 1, l; i <= n; ++i)
        {
            cin >> l;
            for(int j = 0, tmp; j < l; ++j)
            {
                cin >> tmp;
                s[i].push_back(tmp);
                for(int z = j - k + 1; z <= j - 1; ++z)
                {
                    if(find(G[i][s[i][z]].begin(), G[i][s[i][z]].end(), tmp) == G[i][s[i][z]].end())
                        G[i][s[i][z]].push_back(tmp);
                }
            }
        }
        int maxr = -1;
        for(int i = 1; i <= q; ++i)
        {
            cin >> r[i] >> c[i];
            maxr = max(maxr, r[i]);
        }

        queue<Node> Q;
        for(int i = 1; i <= n; ++i)
        {
            Q.push({i, 1, 0});
            AccessRound[1].push_back(0);
        }
        while(!Q.empty())
        {
            Node x = Q.front(); Q.pop();
            // ATTENTION: if the round number is bigger than r, not push in!!!
            for(auto y : G[x.person][x.number])
            {
                if(x.round < maxr + 3)
                {
                    for(int nextPerson = 1; nextPerson <= n; ++nextPerson)
                    {
                        if(nextPerson == x.person)
                            continue;
                        Q.push({nextPerson, y, x.round + 1});
                        AccessRound[y].push_back(x.round + 1);
                    }
                }
            }
        }

        for(int i = 1; i <= q; ++i)
        {
            cout << (find(AccessRound[c[i]].begin(), AccessRound[c[i]].end(), r[i]) != AccessRound[c[i]].end()) << endl;
        }
    }
}
