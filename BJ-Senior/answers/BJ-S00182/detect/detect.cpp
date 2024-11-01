#include<bits/stdc++.h>
using namespace std;
int n,m,l,V,t,d[100010],v[100010],a[100010],p[100010],ans;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t>0){
        t--;
        cin>>n>>m>>l>>V;
        for(int i=0;i<n;i++){
            cin>>a[i]>>v[i]>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>p[i];
        }
        ans=0;
        if(a[0]==0){
            for(int i=0;i<n;i++){
                if(v[i]>V&&d[i]<=l){
                    ans++;
                }
            }
            cout<<ans<<' '<<1<<endl;
            continue;
        }
    }

    return 0;
}
