#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#define int long long
using namespace std;
int n;
int a[100005];
int b[100005],k;
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1])cnt=0,b[++k]=++cnt;
        else b[k]=++cnt;
    }
  //  cout<<b[1]<<' '<<b[2]<<endl;
    int lastans=1e18;
    int ans=b[k],tmp=b[k];
    for(int i=k-1;i>=1;i--){
        if(tmp>=b[i])tmp-=b[i],i--;
        else tmp=b[i]-tmp,ans+=tmp;
    }
    lastans=ans;
    tmp=b[1];
    for(int i=2;i<=k;i++){
        if(tmp<b[i])tmp=b[i],ans+=b[i];
    }
   // cout<<tmp<<endl;
    printf("%lld\n",min(lastans,tmp));
    return 0;
}
/*
10
136 136 136 2417 136 136 2417 136 136 136
*/
