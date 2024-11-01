#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,n,m,ans,p[N],a[N],d[N],x[N],l,v;
int main(){
    freopen("detect1.in","r",stdin);
    //freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        bool flag=true,ok=false;
        ans=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>x[i]>>a[i];
            if(a[i]>0){
                flag=false;
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int k=1;k<=n;k++)
            ok=false;
            for(int i=1;i<=l;i++){
                x[i]+=a[i];
                for(int j=1;j<=l;j++){
                    if(p[j]==i&&x[i]>v&&!ok){
                        ans++,ok=1;
                        break;
                    }
                }
                if(x[i]<=0||ok==1){
                    break;
                }
            }
        cout<<ans<<" "<<m-1<<endl;

    }
    return 0;
}
