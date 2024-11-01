#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn],c[maxn],cnt;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) c[a[i]]++;
    for(int i=1;i<=100000;i++){
        if(c[i]>=cnt) cnt=c[i];
        //cout<<c[i]<<" ";
    }
    cout<<cnt<<'\n';
    return 0;
}
