#include<bits/stdc++.h>
using namespace std;
int f(int x,int y,int z)
{
    char p[1001][1001];
    int flag[1001][1001]={0};
    int a,b,c;
    cin>>a>>b>>c;
    for(int i = 1;i<=x;i++)
        for(int j=1;j<=y;j++)
            cin>>p[i][j];
    for(int r = 0;r<z;r++)
    {
        flag[a][b]=1;
        if(c==0)
        {
            if(p[a][b+1]=='.')
                b++;
            else
                c++;
        }
        else if(c==1)
        {
            if(p[a+1][b]=='.')
                a++;
            else
                c++;
        }
        else if(c==2)
        {
            if(p[a][b-1]=='.')
                b--;
            else
                c++;
        }
        else
        {
            if(p[a-1][b]=='.')
                a--;
            else
                c=0;
        }
    }
    flag[a][b]=1;
    int cnt=0;
    for(int i = 1;i<=x;i++)
        for(int j = 1;j<=y;j++)
            if(flag[i][j]==1)
                cnt++;
    return cnt;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    int n[6],m[6],k[6];
    int ans[6];
    cin>>T;
    for(int i = 0;i<T;i++)
    {
        cin>>n[i]>>m[i]>>k[i];
        ans[i] = f(n[i],m[i],k[i]);
    }
    for(int i = 0;i<T;i++)
        cout<<ans[i]<<endl;
    return 0;
}
