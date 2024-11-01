#include<bits/stdc++.h>
using namespace std;
int a[100010];
bool vis[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            cnt1++;
        }
        else if(a[i]==2)
        {
            cnt2++;
        }
    }
    sort(a+1,a+1+n);
    if(cnt1+cnt2==n)
    {
        cout<<max(cnt1,cnt2);
    }
    else
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(vis[j]==true)
                {
                    continue;
                }
                if(a[j]>a[i])
                {
                    vis[j]=true;
                    cnt++;
                    break;
                }
            }
        }
        cout<<n-cnt;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
