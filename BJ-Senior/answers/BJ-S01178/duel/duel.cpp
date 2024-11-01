#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int h[N],r[N],s[N];
int ans,x,f;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&r[i]);
        h[r[i]]++;
    }
    for(int i=1;i<=100000;i++){
        ans=max(ans,h[i]);
    }
    cout<<ans;
    return 0;
}
