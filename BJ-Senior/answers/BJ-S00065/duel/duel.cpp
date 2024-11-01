#include<bits/stdc++.h>
using namespace std;

int n;
int r[1000010];
int input;
int ans;

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    for(int i=0;i<=100005;i++)r[i]=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>input;
        r[input]++;
    }
    ans=r[100005];
    for(int i=100005;i>1;i--)
    {
        ans=max(ans-r[i-1],0)+r[i-1];
    }
    cout<<ans;
    return 0;
}
