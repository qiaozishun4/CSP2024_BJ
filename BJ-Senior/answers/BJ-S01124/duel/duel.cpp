#include<bits/stdc++.h>
using namespace std;
int n,last,ans;
int a[100010],b[100010];
queue<int> q;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    last=1;
    b[1]=1;
    for(int i=2;i<=n;i++)
    {
       if(a[i]!=a[i-1])
       {
           last++;
       }
       b[i]=last;
    }
    ans=n;
    for(int i=1;i<=n;i++)
    {
        if(!q.empty())
        {
            if(b[i]<=q.front())
            {
                q.push(b[i]);
            }
            else
            {
                q.pop();
                ans--;
                q.push(b[i]);
            }
        }
        else
        {
            q.push(b[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
