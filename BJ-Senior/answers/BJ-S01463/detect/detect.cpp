#include<bits/stdc++.h>
using namespace std;
long long a[100010],t,n,m,l,V,f,find[100010],ans,ans1;
struct node{
    long long d,v;
}car[100010];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>m>>l>>V;
        for(int i=1;i<=n;i++){
            cin>>car[i].d>>car[i].v>>f;
        }
        for(int i=1;i<=m;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            if(car[i].v>V){
                if(car[i].d<=a[m]){
                    ans1=m-1;
                }
                ans++;
            }
        }
        cout<<ans<<" "<<ans1<<endl;
    }
    return 0;
}
