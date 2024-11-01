#include<bits/stdc++.h>
using namespace std;
int n,ans,min1=1000000,max1;
long long a[100010],s[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        int x;cin>>x;
        min1=min(min1,x);
        max1=max(max1,x);
        a[x]++;
    }
    s[0]=0;
    for(int i=1;i<=100000;++i){
        if(a[i]>s[i-1]){
            ans+=a[i]-s[i-1];
            s[i]=a[i];
        }
        else{
            s[i]=s[i-1];
        }
    }
    cout<<ans<<'\n';
    return 0;
}