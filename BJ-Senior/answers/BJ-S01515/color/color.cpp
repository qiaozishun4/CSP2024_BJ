#include<bits/stdc++.h>
using namespace std;
long long n,maxx=0;
int a[200005];
void dfs(int red,int blue,long long x,int cnt)
{
    //cout<<red<<" "<<blue<<" "<<x<<" "<<cnt<<endl;
    if(cnt>n&&x>maxx)
        maxx=x;
    if(cnt>n)
        return ;
    if(a[cnt]==blue)
    {
        x+=blue;
        dfs(red,blue,x,++cnt);
    }
    else if(a[cnt]==red)
    {
        x+=red;
        dfs(red,blue,x,++cnt);
    }
    else
    {
        ++cnt;
        dfs(a[cnt-1],blue,x,cnt);
        dfs(red,a[cnt-1],x,cnt);
    }

}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        maxx=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        dfs(0,0,0,1);
        cout<<maxx<<endl;
    }
    return 0;
}
