#include<bits/stdc++.h>
using namespace std;
int vis[10005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,k,q,num=0,cnt=0;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            int x,y;
            cin>>x;
            cnt=0;
            for(int j=1;j<=x;j++)
            {
                cin>>y;
                if(cnt>0)
                {
                    cnt--;
                    num++;
                    vis[num]=y;
                }
                if(y==1)
                    cnt=k;
            }
        }
        for(int i=1;i<=q;i++)
        {
            int x,y,f=0;
            cin>>x>>y;
            if(x==1)
            {
                for(int i=1;i<=num;i++)
                if(y==vis[i])
                {
                    cout<<1<<endl;
                    f=1;
                    break;
                }
                if(f==0)
                    cout<<0<<endl;
            }
            else
                cout<<0<<endl;
        }
    }
    return 0;
}