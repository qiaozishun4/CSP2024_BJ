#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct car{
    int d,v,a;
}car[N];
int T;
int n,m,l,v;
int p[N];
int ans;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>l>>v;
        ans=0;
        for(int i=1;i<=n;i++) cin>>car[i].d>>car[i].v>>car[i].a;
        for(int i=1;i<=m;i++) cin>>p[i];
        for(int i=1;i<=n;i++){
            if(car[i].d<=p[m] && car[i].v>v) ans++;
        }
        cout<<ans<<" "<<(ans==0?m:m-1)<<endl;
    }
    return 0;
}
