#include<bits/stdc++.h>
using namespace std;
int a[100009];
int cnt[100009];
int main(){

freopen("duel.in","r",stdin);
freopen("duel.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
    cnt[a[i]]++;
}
int tmp=n;
int ans=n;
for(int i=1;i<=100005;i++){

    if(cnt[i]!=0){
        if(tmp-cnt[i]<cnt[i]){
            ans-=tmp-cnt[i];
            break;
        }
    tmp-=cnt[i];
    ans-=cnt[i];
    }
}
cout<<ans<<endl;
return 0;
}
