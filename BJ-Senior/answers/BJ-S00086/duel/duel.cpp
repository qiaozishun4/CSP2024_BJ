#include<bits/stdc++.h>
using namespace std;
struct aaa{int g, z;}r[10005];
int n, s=1, ans, gj=2, ma=-0x3f;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        r[x].g++;
        r[x].z++;
        ma=max(ma,x);
    }
    ans=n;
    while(gj<=ma){
        if(s==gj){
            gj++;
            continue;
        }
        if(r[s].z==0){
            s++;
            continue;
        }
        if(r[gj].g==0){
            gj++;
            continue;
        }
        r[s].z--;
        r[gj].g--;
        ans--;
    }
    cout << ans;
    return 0;
}
