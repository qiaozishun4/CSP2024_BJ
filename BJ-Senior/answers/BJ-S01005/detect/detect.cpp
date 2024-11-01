#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,mxx,a[100010],w[100010];
long long t,ans;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>x>>y;
        for(int i=1;i<=n;i++){
                 int T;
            cin>>w[i]>>a[i]>>T;
            if(d[i]>y){
                ans++;
            }
            if(p[i]>mxx){
                mxx=w[i];
            }
        }
        int maxx=0;
       for(int i=1;i<=m;i++){
            int t;
            cin>>t;
            if(t>maxx){
                maxx=t;
            }
       }
       if(0&&mxx>mx){
            sort(w+1,w+n+1);
        for(int i=n;i>=1;i++){
            if(a[i]>maxx){
                ans++;
            }
            else{
                break;
            }
        }
       }
       if(ans!=0){
        cout<<ans<<" "<<m-1<<endl;
       }
       else{
        cout<<ans<<" "<<m<<endl;
       }
    }
    return 0;
}
