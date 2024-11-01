#include<bits/stdc++.h>
using namespace std;
int tot[200010],num[200010],n;
bool cmp(int a,int b){
    return a<b;
}int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        tot[num[i]]++;
    }int ans=0;
    for(int i=1;i<=100010;i++){
        ans=max(ans,tot[i]);    
    }cout<<ans<<'\n';
}