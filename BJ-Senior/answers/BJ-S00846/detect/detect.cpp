#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=1e6+10;
int T,n,m,L;double V;
int d[N],v[N],a[N],p[N];
int nearest_detect[M];
bool have_a_detect[M];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
            have_a_detect[p[i]]=1;
        }
        int QwQ;
        for(int i=L;i;i--){
            if(have_a_detect[i]){
                QwQ=i;
            }
            nearest_detect[i]=QwQ;
        }
        int chk=p[m],ans=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(d[i]>chk)continue;
            if(a[i]>=0){
                int l=chk-d[i];
                double speed=sqrt(v[i]*v[i]+2*a[i]*l);
                if(speed>V)ans++;
            }else if(a[i]<0){
                cnt++;
                if(v[i]>V){
                    int x=nearest_detect[d[i]];
                    int l=x-d[i];
                    double speed=sqrt(v[i]*v[i]+2*a[i]*l);
                    if(speed>V)ans++;
                }
            }
        }
        cout<<ans<<" "<<m-cnt-1<<endl;
    }
    return 0;
}
