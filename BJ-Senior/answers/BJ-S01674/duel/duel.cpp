#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int a[100005];
int b[100005];
int cnt[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
        b[a[i]]++;
    }
    int now=1,ans=n;
    for(int i=1;i<=100000;i++)
    {
        for(int j=1;j<=b[i];j++)
        {
            now=i+1;
            while(now<100000&&cnt[now]==0)
            {
                now++;
            }
            if(cnt[now]>0)
            {
                cnt[now]--;
                ans--;
            }
        }
    }
    cout<<ans;
    return 0;
}