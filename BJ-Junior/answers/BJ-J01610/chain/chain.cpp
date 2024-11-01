#include<bits/stdc++.h>
using namespace std;

int T, n, k, q, x, r, c;
int len[100005];
int cnt[200005];
vector <int> vec[100005];
struct node
{
    int num;
    int lastnum;
    int id;
};

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> k >> q;
        for(int i = 1; i <= n; i++)
        {
            cin >> len[i];
            for(int j = 1; j <= len[i]; j++)
            {
                cin >> x;
                vec[i].push_back(x);
                cnt[x]++;
            }
        }
        while(q--)
        {
            cin >> r >> c;
            if(cnt[c] == 0)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
