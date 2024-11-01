#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
vector<int>vec[N];
bool canbeg[N];
int T,n,k,q,x,l,r,c;
bool is_ok;
void dfs(int i,int djl,int stc)
{
    if (djl>r)
    {
        if (stc==c) is_ok=1;
        return;
    }
    int sz=vec[i].size();
    for (int j=0;j<sz;j++) if (vec[i][j]==stc) for (int t=2;t<=k;t++) for (int s=1;s<=n;s++)
    if (s==i) continue; else dfs(s,djl+1,vec[i][j+t-1]);
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d %d %d",&n,&k,&q);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&l);
            for (int j=0;j<l;j++)
            {
                scanf("%d",&x);
                vec[i].push_back(x);
                if (x==1) canbeg[i]=1;
            }
        }
        for (int i=1;i<=q;i++)
        {
            scanf("%d %d",&r,&c);
            is_ok=0;
            for (int j=1;j<=n;j++)
            {
                dfs(j,1,1);
                if (is_ok) break;
            }
            cout<<is_ok<<'\n';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
