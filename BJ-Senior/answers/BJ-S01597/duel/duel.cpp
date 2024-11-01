#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n,a[N],ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1,j=1;i<=n;++i){
        if(a[i]>a[j]){
            ans++,j++;
        }
    } cout<<n-ans;
}
