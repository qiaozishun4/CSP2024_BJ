#include <bits/stdc++.h>
using namespace std;
int n,r[100001],ans=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+n+1);
    int tmp=1;
    for(int i=1;i<=n;i++){
        if(r[i]==r[i-1]){
            tmp++;
        }
        else{
            if(ans<tmp){
                ans=tmp;
            }
            tmp=1;
        }
    }
    if(ans<tmp){
        ans=tmp;
    }
    cout<<ans;
    return 0;
}