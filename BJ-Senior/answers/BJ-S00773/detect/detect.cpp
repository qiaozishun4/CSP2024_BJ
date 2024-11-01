#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int ci;cin>>ci;
    while(ci--){
        int a[100005],b[100005],c[100005],d[100005],road[100005];
        int n,m,l,v,morecar=0,ans=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]>v)morecar++;
        }
        cout<<morecar<<" ";
        for(int i=1;i<=n;i++){
            if(b[i]>v){
                for(int j=a[i];j<=l;j++){
                    road[j]++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            cin>>d[i];
            if(road[d[i]]==0)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
