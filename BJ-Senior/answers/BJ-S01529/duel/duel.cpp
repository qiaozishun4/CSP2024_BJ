#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,s,r[N],a[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+n+1);
    s=1;
    for(int i=1;i<=n;){
        int p=i;
        while(r[i]==r[++i]);
        a[s++]=i-p;
    }
    for(int i=2;i<s;i++){
        a[i]=a[i]+max(a[i-1]-a[i],0);
    }
    cout<<a[s-1]<<endl;
    return 0;
}
