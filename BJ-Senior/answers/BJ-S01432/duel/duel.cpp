#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],b[N],cnt=0,mx=INT_MIN,c[N],sum;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
        mx=max(mx,a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=mx;i++){
        if(b[i]!=0) c[++cnt]=b[i];
    }
    for(int i=1;i<=cnt;i+=2){
        sum+=abs(c[i]-c[i-1]);
    }
    cout<<sum;
    return 0;
}
