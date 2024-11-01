#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t[maxn],t2[maxn],minn=2e9+5,x,n,maxm=0,ans=0;
int main(int argc,char** argv){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    memset(t,0,sizeof(t));
    memset(t2,0,sizeof(t2));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        t[x]++;
        t2[x]++;
        minn=min(minn,x);
        maxm=max(maxm,x);
    }
    for(int i=minn;i<=maxm;i++){
        if(t[i]==0) continue;
        for(int j=minn;j<i;j++){
            if(t[j]==0) continue;
            int temp=min(t[i],t[j]);
            t[j]-=temp;
            t2[j]-=temp;
            t2[i]-=temp;
            ans+=temp;
            if(t2[i]==0) break;
        }
    }
    cout<<n-ans;
    return 0;
}
