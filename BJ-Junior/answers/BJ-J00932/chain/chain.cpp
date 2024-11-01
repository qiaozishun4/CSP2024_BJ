#include<bits/stdc++.h>
using namespace std;
int a[100001][10];
int main()
{
    //freopen("chain.in","r",stdin);
    //freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=1;i<=100001;i++)
        {
            a[i][0]=0;
            a[i][1]=0;
            a[i][2]=0;
            a[i][3]=0;
            a[i][4]=0;
            a[i][5]=0;
            a[i][6]=0;
            a[i][7]=0;
            a[i][8]=0;
            a[i][9]=0;
        }
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            int l;
            cin>>l;
            while(l--)
            {
                int x;
                cin>>x;
                a[n][x]++;
                a[n+1][x]++;
                a[n+2][0]++;
            }
        }
        for(int i=1;i<=q;i++)
        {
            int x,y;
            cin>>x>>y;
            if(a[n+1][1]>0 && a[n+1][y]>0 || x==y && y==2)
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
    }
    return 0;
}

