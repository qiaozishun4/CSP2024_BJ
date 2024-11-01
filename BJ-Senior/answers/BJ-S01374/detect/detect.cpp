#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
int l,maxv;
int d[100005];
int v[100005];
int a[100005];
int p[100005];
bool f[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>maxv;
        int ans=0;
        int ans2=m;
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>p[i];
            f[i]=false;
        }
        p[m]=l+1;
        for(int i=0;i<n;i++){
            int cnt=0;
            while(p[cnt]<d[i])cnt++;
            int sd=d[i];
            int sv=v[i];
            while(sd<l&&sv>0){
                sv=sv*sv+2*a[i]*(p[cnt]-sd);
                if(sv<0)break;
                sv=sqrt(sv);
                if(sv>maxv){
                    if(!f[cnt]){
                        f[cnt]=true;
                        ans2--;
                    }
                    ans++;
                    break;
                }
                sd=p[cnt];
                cnt++;
            }
        }
        cout<<ans<<" "<<ans2<<endl;
    }
    return 0;
}
