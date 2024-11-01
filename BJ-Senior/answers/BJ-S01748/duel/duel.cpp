#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int r[100005];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>r[i];
    }sort(r+1,r+n+1);
    int ans=0,cur=0;
    for(int i=1;i<=n;++i){
        if(r[i]!=r[i-1]){
            ans=max(ans,cur);
            cur=1;
        }else{
            ++cur;
        }
    }ans=max(ans,cur);
    cout<<ans;
    return 0;
}
