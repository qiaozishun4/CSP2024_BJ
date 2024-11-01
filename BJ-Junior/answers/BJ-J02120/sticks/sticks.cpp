#include <bits/stdc++.h>
using namespace std;
//6,2,5,5,4,5,6,3,7,6
int cnt;
int cur;
bool b;
int ans[1001];
int a[1001];
void dfs2(int x)
{
    if(cur>cnt || x<0)
    {
        return;
    }
    if(x==0)
    {
        b=1;
        for(int i=1;i<=cnt;i++)
        {
            ans[i]=a[i];
        }
        return;
    }
    cur++;
    a[cur]=8;
    dfs2(x-7);
    a[cur]=7;
    dfs2(x-3);
    if(cur==1)
    {
        a[cur]=6;
        dfs2(x-6);
    }
    a[cur]=4;
    dfs2(x-4);
    a[cur]=2;
    dfs2(x-5);
    a[cur]=1;
    dfs2(x-2);
    if(cur!=1)
    {
        a[cur]=0;
        dfs2(x-6);
    }
    cur--;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)
            {
                cout<<"8";
            }
        }
        else if(n%7==1 && n!=1)
        {
            cout<<"19";
            for(int i=1;i<=n/7-1;i++)
            {
                cout<<"8";
            }
        }
        else
        {
            cnt=n/7+1;
            b=0;
            cur=0;
            dfs2(n);
            if(b==0)
            {
                cout<<"-1";
            }
            else
            {
                for(int i=1;i<=cnt;i++)
                {
                    cout<<ans[i];
                }
            }
        }
        cout<<endl;
    }
    return 0;
}