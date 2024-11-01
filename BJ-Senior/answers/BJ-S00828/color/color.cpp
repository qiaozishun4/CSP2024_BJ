#include<iostream>
using namespace std;

int a[200010];
int c[200010];
int n,maxn=-1e9;

int f()
{
    int sum=0,now1=-1,now0=-1;
    for(int i=1;i<=n;i++)
    {
        if(c[i]==1)
        {
            if(now1==a[i])sum+=a[i];
        }
        else if(c[i]==0)
        {
            if(now0==a[i])sum+=a[i];
        }

        if(c[i]==0)now0=a[i];
        else if(c[i]==1)now1=a[i];
    }
    return sum;
}

void dfs(int step)
{
    if(step>n)
    {
        maxn=max(maxn,f());
        return;
    }
    for(int i=0;i<=1;i++)
    {
        c[step]=i;
        dfs(step+1);
    }
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        maxn=-1e9;
        cin >> n;
        for(int i=1;i<=n;i++)cin >> a[i];
        dfs(1);
        cout << maxn << endl;
    }
    return 0;
}
