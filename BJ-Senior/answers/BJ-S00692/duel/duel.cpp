#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],x=0;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) b[i]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    while(1){
        int ans=0;
        x=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=1;j--){
                if(a[i]>a[j]&&b[i]==1&&b[j]!=-1)
                {
                    a[j]=-1;
                    b[j]=-1;
                    b[i]=0;
                    ans++;
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(b[i]==0||b[i]==1) x++;
        }
        if(ans==0) break;
    }
    cout<<x<<'\n';
    return 0;
}
