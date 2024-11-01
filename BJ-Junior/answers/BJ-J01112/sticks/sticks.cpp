#include<bits/stdc++.h>
using namespace std;
int a[10]={8,0,2,4,7,1};
int box[100005];
int min1;
void dfs(int x,int cur)
{
    if(x==0)
    {
        int ans=0;
        for(int i=1;i<=cur-1;i++)
        {
            ans=ans*10+box[i];
        }
        if(min1>ans)
        {
            min1=ans;
        }
        return ;
    }
    if(x<2)
    {
        return ;
    }
    for(int i=0;i<6;i++)
    {
        box[cur]=a[i];
        if(box[1]==0)
        {
            box[1]=6;
        }
        dfs(x-7+i,cur+1);
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x%7==0)
        {
            while(x)
            {
                cout<<8;
                x-=7;
            }
        }
        else if(x%7==1&&x>=8)
        {
            cout<<10;
            x-=8;
            while(x)
            {
                cout<<8;
                x-=7;
            }
        }
        else
        {
            min1=1e9;
            dfs(x,1);
            if(min1==1e9)
            {
                min1=-1;
            }
            cout<<min1;
        }
        cout<<endl;
    }
    return 0;
}
