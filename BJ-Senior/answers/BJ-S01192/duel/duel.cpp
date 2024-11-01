#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    int a[100005]={},b[100005]={},s[100005]={};
    int maxn2=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]>maxn2)
        {
            maxn2=a[i];
        }
        b[a[i]]++;
        s[a[i]]++;
    }
    int c[100005]={},ans=n;
    for(int i=maxn2;i>=1;i--)
    {
        if(b[i]==0) continue;
        for(int j=1;j<=i-1;j++)
        {
            if(s[j]==0) continue;
            ans-=b[i];
            s[j]-=b[i];
            b[i]=0;
        }
    }
    cout << ans;
    return 0;
    fclose(stdin);
    fclose(stdout);
}