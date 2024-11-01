#include<bits/stdc++.h>
using namespace std;
int a[10005],k=1,flag=0;
void dfs(int x)
{
    if(x==0){
        flag=1;
        return;
    }
    for(int i=7;i>=2;i++)
    {
        if(x>i)
        {
            dfs(x-i);
            a[k]=i;
            k++;
        }
    }
}
int main()
{
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m;
        flag=0;
        dfs(m);
        for(int j=k;j>=1;j--)
        {
            if(a[j]==2) a[j]=1;
            else if(a[j]==3) a[j]=7;
            else if(a[j]==4) a[j]=4;
            else if(a[j]==5) a[j]=2;
            else if(a[j]==6&&j!=1) a[j]=0;
            else if(a[j]==6&&j==1) a[j]=6;
            else if(a[j]==7) a[j]=8;
        }
        for(int i=1;i<=k;i++) cout<<a[i];
        cout<<endl;
    }
    return 0;
}
