#include<bits/stdc++.h>
using namespace std;
int n,a[100005],mx=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        a[x]++;
    }
    for(int i=1;i<=100002;i++) mx=max(mx,a[i]);
    cout<<mx;
}
