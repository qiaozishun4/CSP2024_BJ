#include<bits/stdc++.h>
using namespace std;
int a[100010],ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        a[x]++;
    }
    for(int i=1;i<=100001;i++){
        if(a[i]!=0){
            if(ans>=a[i]) continue;
            if(ans<a[i]) ans=a[i];
        }
    }
    cout<<ans;
    return 0;
}
