#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v1,d[3010],v[3010],a[3010],p[3010];
bool ok[3010],r[30];
int x[25][25]; 
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        int cnt=0;
        cin>>n>>m>>l>>v1;
        for(int i=1;i<=n;++i) cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;++i) cin>>p[i];
        for(int i=1;i<=n;++i){
            if(a[i]==0){
                if(v[i]<=v1) ok[i]=1;
                else if(d[i]>=p[m]) ok[i]=1;
                else{
                    int cnt=1,tmp=m;
                    while(p[tmp]>d[i]&&tmp>=1){
                        x[i][cnt]=tmp;
                        cnt++;
                        tmp--;
                    }
                }
            }
            else if(v1<v[i]&&a>0&&d[i]>=p[m]) ok[i]=1;
            else if(v1>=v[i]&&a<0) ok[i]=1;
            else{
                int cnt=1;
                double t=(v1*v1-v[i]*v[i])/(2*a[i]);
                int t1=t;if(t1!=t)t1++;
                if(v[i]>v1){
                    bool flag=1;
                    for(int j=1;j<=n;++j) if(p[j]>=d[i]&&p[j]<d[i]+t1){
                        flag=0;
                        x[i][cnt]=j;
                        cnt++;
                    }
                    ok[i]=flag;
                }
                else if(p[m]<d[i]+t1) ok[i]=1;     
                else{
                    int cnt=1,tmp=m;
                    while(p[tmp]>=d[i]+t1&&tmp>=1){
                        x[i][cnt]=tmp;
                        cnt++;
                        tmp--;
                    }
                }
            }
        }
        for(int i=1;i<=n;++i) if(!ok[i]) cnt++;
        cout<<cnt<<' ';
        int k=pow(2,n),ans=-1;
        for(int i=0;i<k;++i){
            int t=i,cnt=1,cnt2=0;
            while(t){
                r[cnt]=t%2;
                if(t%2==1) cnt2++;
                t/=2;
                cnt++;
            }
            bool qc=1;
            for(int i=1;i<=n;++i){
                if(!ok[i]){
                    bool flag=0;
                    for(int j=1;j<=20;++j) if(r[x[i][j]]) flag=1;
                    if(!flag){qc=0;break;} 
                }
            }
            if(qc){
                ans=max(ans,n-cnt2);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}