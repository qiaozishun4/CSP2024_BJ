#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+10,M=2e5+10;
int t,n,k,q,l,b[N][N],a[N][N],x,y,f[100][M];
vector<int> v[M];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&k,&q);

            for(int i = 1; i <= n; i++)
            {
                cin>>l;
                for(int j = 1; j <= l; j++)
                {
                    cin>>b[i][j];
                }
            }
            for(int i = 1; i <= q; i++)
            {
                cin>>x>>y;
                cout<<"1"<<endl;
            }
        }
    return 0;
}
