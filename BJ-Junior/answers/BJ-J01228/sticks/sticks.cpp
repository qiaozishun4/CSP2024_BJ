#include<bits/stdc++.h>
using namespace std;
//char a[15]={0,0,'1','7','4','2','0','8'};
int a[15]={6,2,5,5,4,5,6,3,7,6};
int sw;
bool f=0;
void dfs(int x,int n,long long s)
{
    if(x>sw)
    {
        if(n==0)
        {
            cout<<s<<"\n";
            f=1;
        }
        return ;
    }
    for(int i=0;i<=9;i++)
    {
        if(x==1&&i==0) continue; 
        dfs(x+1,n-a[i],s*10+i);
        if(f) return ;
    }
    return ;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>n;
        if(n<2)
        {
            cout<<"-1\n";
            continue;
        }
        sw=n/7+(n%7==0?0:1);
        f=0;
        dfs(1,n,0);
    }
    return 0;
}
