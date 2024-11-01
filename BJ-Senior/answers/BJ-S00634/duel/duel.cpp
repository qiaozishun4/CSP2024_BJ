#include <iostream>
#include <bits/stdc++.h>
#define gc getchar()
using namespace std;
const int maxn=int(1e5+5);
int n,a[maxn],ans;
bool vis[maxn],life[maxn];
long long t[maxn];
int gofind(int x){
    int l=1,r=x,ansk=-1;
    for(l=1;l<=r;l++){
        if(a[l]==a[r]) return l-1;
    }
}

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    memset(life,true,sizeof(life));
    memset(vis,false,sizeof(vis));
    cin>>n;
    if(n<=30){
        ans=n;
        for(int i=1;i<=n;i++){
        cin>>a[i];
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            int k=gofind(i);
            if(k!=0){
                ans--;
                //cout<<k<<endl;
                life[k]=false;
                vis[i]=true;
            }
        }
        cout<<ans<<endl;
    }
    else {
        memset(t,0,sizeof(t));
        for(int i=1;i<=n;i++){
            cin>>a[i];
            t[a[i]]++;
        }
        if(t[3]==0){
            int der=t[2]-t[1];
            if(der>0) cout<<t[2]<<endl;
            else cout<<t[2]+der<<endl;
        }

    }

    return 0;
}
