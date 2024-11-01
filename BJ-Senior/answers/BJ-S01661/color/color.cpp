#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int t,n;
int z[100010];
int pan[100010];
int ans;
int gett(vector<int>a)
{
    int len=a.size();
    int num=0;
    for(int i=1;i<len;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            if(a[i]==a[j])
            {
                if(z[i]==z[j])
                num+=z[i];
                break;
            }
        }
    }
    return num;
}
void dfs(vector<int>a)
{
    if(a.size()==n+1)
    {
        ans=max(ans,gett(a));
        return;
    }
    a.push_back(1);
    dfs(a);
    a.pop_back();
    a.push_back(2);
    dfs(a);
    a.pop_back();
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >>t;
    while(t--)
    {
        cin >>n;
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            cin >>z[i];
            mx=max(mx,z[i]);
            pan[z[i]]++;
        }
        bool flag=0;
        for(int i=1;i<=mx;i++)
        {
            if(pan[i]>1)
                flag=1;
            pan[i]=0;
        }
        if(flag==0)
        {
            cout << 0 <<"\n";
            continue;
        }
        vector<int>a;
        ans=0;
        a.push_back(0);
        dfs(a);
        cout <<ans <<"\n";
    }
}
