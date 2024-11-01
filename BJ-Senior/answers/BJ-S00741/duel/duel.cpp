#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0,temp1=0,temp2=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[i-1]) temp2++;
        else
        {
            ans+=min(temp1,temp2);
            temp1=max(temp1,temp2);
            temp2=1;
        }
    }
    ans+=min(temp1,temp2);
    cout<<n-ans<<endl;
    return 0;
}