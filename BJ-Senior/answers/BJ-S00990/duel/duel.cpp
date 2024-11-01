#include<bits/stdc++.h>
using namespace std;
const int N=1e5 + 7;
int b[N],a[N],c[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,cnt=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        if(!b[x])a[++cnt]=x;
        ++b[x];
        ++c[x];
    }
    sort(a+1,a+cnt+1);
    for(int i=1;i<cnt;++i){
            int j=i+1;
        while(b[a[i]]){
            if(c[a[j]]>=b[a[i]]){
                c[a[j]]-=b[a[i]];
                b[a[i]]=0;
            }
            else{
                b[a[i]]-=c[a[j]];
                c[a[j]]=0;
            }
            ++j;
            if(j>cnt)break;
        }
    }
    for(int i=1;i<=cnt;++i){
        ans+=b[a[i]];
    }
    cout<<ans<<'\n';
    return 0;
}
