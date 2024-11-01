#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,w,num[15]={6,2,5,5,4,5,6,3,7,6};
stack<int> s1;
stack<int> s2;
bool dfs(int k,int now)
{
    if(now==0&&k==0) return true;
    if(now==0&&k!=0)
    {
        s1.pop();
        return false;
    }
    for(int i=0;i<=9;i++)
    {
        if(now==w&&i==0) continue;
        if((k-num[i])-now*7>k||num[i]>k) continue;
        s1.push(i);
        if(dfs(k-num[i],now-1)) return true;
    }
    if(!s1.empty()) s1.pop();
    return false;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%7!=0) w=n/7+1;
        else w=n/7;
        if(dfs(n,w))
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            while(!s2.empty())
            {
                cout<<s2.top();
                s2.pop();
            }
        }
        else cout<<-1;
        cout<<'\n';
    }
    return 0;
}
