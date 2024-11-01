#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,k,q,r[N],c[N];
bool haveans;
vector <vector <int>> s;
void dfs(int kt,int peo,int r2,int j2)
{
    if(r2==r[j2])
    {
        haveans=1;
        cout << 1 << endl;
    }
    for(int i=2;i<=s[peo][1]+1;i++)
    {
        if(s[peo][i]!=kt)continue;
        for(int j=1;j<=k;j++)
        {
            if(i+j>s[peo][1])break;
            if(r2+1==r[j2]&&s[peo][i+k]!=c[j2])continue;
            for(int a=1;a<=n;a++)
            {
                if(a==peo)continue;
                dfs(s[peo][i+j],a,r2+1,j2);
                if(haveans)return;
            }
        }
    }
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> k >> q;
        for(int i=1;i<=n;i++)
        {
            int l;
            cin >> l;
            vector<int> l2;
            l2.push_back(l);
            s.push_back(l2);
            for(int j=1;j<=s[i][1];j++)
            {
                int s2;
                cin >> s2;
                s[i].push_back(s2);
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin >> r[i] >> c[i];
            haveans=0;
            for(int j=1;j<=n;i++)
            {
                dfs(1,j,0,i);
            }
        }
    }
    return 0;
}

