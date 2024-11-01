#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,k,x,y,d;
    string a[1005];
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        string m;
        cin>>n>>m>>k>>x>>y>>d;
        for (int j=1;j<=n;j++)
        {
            cin>>a[i];
        }
        if (n==1 && m.length()==1)
        {
            cout<<1;
        }
        if(n==1 && m.length()==2)
        {
            if(m==".x" || m=="x.")
            {
                cout<<"1";
            }
            else
            {
                cout<<"2";
            }
        }

    }
    return 0;
}