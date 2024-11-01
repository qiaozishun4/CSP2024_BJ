#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],c[100005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    int ans=n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        b[a[i]]++;
        c[a[i]]=b[a[i]];
    }
    //cout << c[1];
    sort(a+1,a+n+1);
    int du=0,zl=0;
    for (int i=1;i<=n;i+=c[a[i]])
    {
        int k=0;
        if (i+c[a[i]]>=n)
        {
            k=1;
        }
        int now=a[i],nex=a[i+c[a[i]]];
        if (b[now]==b[nex])
        {
            ans-=b[now];
            b[now]=0;
            //cout << "1 " <<now << " " << nex <<endl;
        }
        else if (b[now]>b[nex])
        {
            ans-=b[nex];
            zl+=b[now]-b[nex];
            b[now]=0;
            //cout << "2 ";
        }
        else
        {
            ans-=b[now];
            ans-=min(zl,b[nex]-b[now]);
            zl=max(0,b[nex]-b[now]);
            b[nex]-=b[now];
        }
        //cout << ans << " ";
    if (k==1)
        break;
    }
    cout << ans;
    return 0;
}
