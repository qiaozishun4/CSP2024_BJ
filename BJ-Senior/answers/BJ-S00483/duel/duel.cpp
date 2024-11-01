#include<bits/stdc++.h>
using namespace std;
int n,r[100010],ans;
bool atd[100010],cj[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+1+n);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(atd[i]||cj[i]){
                continue;
            }
            atd[j]=true;
            cj[i]=true;
        }
    }
    for(int i=1;i<=n;i++){
        if(atd[i]||cj[i])continue;
        ans++;
    }
    cout<<ans++;
    return 0;
}
