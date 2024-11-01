#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b[100010],n,a,del;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a;
        b[a]++;
    }for(ll i=1;i<=100000;i++){
        if(!b[i]){
            continue;
        }else{
            if(del>0){
                if(b[i]>=del){
                    n-=del;
                    del=b[i];
                }else{
                    n-=b[i];
                }
            }else{
                del=b[i];
            }
        }
    }cout<<n;
    return 0;
}
