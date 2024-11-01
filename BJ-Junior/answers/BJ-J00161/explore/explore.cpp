#include<bits/stdc++.h>
uisng namespace std;
char x[100010][100010];
bool turn(int a,int b,int c)
{
    if(c==0)
    {
        return b+=1;
    }
    else if(c==1)
    {
        return a+=1;
    }
    else if(c==2)
    {
        return b-=1;
    }
    else
    {
        return a-=1;
    }
}
int main()
{
    reopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m,k;
        int cnt=0;
        cin>>n>>m>>k;
        int a,b,c;
        cin>>a>>b>>c;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>x[i][j];
            }
        }
        for(int i=1;i<=k;i++)
        {
            turn(a,b,c);
            if(x[a][b]=='.')
            {
                cnt++;
            }
            else
            {
                c=(c+2)%4
                turn(a,b,c);
                c=(c+3)%4;
            }
        }

    }
    cout<<cnt<<endl;

    return 0;
}
