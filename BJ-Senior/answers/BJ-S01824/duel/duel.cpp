#include<iostream>
#include<algorithm>

using namespace std;
int n, r[100005], kill[100005], ans=0;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>r[i];
    sort(r+1, r+n+1);
    for(int i=1;i<=n;i++)
    {
        kill[i]=kill[i-1];
        while(r[i]>r[kill[i]+1])kill[i]++;
    }
    for(int i=n;i>=1;i--)
    {
        ans=max(ans, i-kill[i]);
        if(i<=ans){cout<<ans;return 0;}
    }
}