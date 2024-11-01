#include<bits/stdc++.h>
using namespace std;
int t,n,m,ll,vm,d[500000],v[500000],a[500000],p[500000];
int jl[500000];
int jl2[500000];
int l[1000],r[1000];
int vt,cnt,cntt;
int ans;
        int c[1000];
int anss;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>ll>>vm;
        for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++)cin>>p[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i]!=0){
                    if(p[j]<d[i]){
                        continue;
                    }
                    if(p[j]==d[i]){
                        if(v[i]>vm) {
                            cnt++;
                            if(a[i]>0){
                                l[i]=j;
                                r[i]=m;

                            }
                            if(a[i]<0){
                                    l[i]=j;
                                for(int k=j;k<=m;k++){
                                    int vtt=sqrt(2*a[i]*(p[k]-d[i])+v[i]*v[i]);
                                    if(vtt>vm){

                                        r[i]=k;
                                    }
                            }
                            }
                        }
                    }
                    if(p[j]>d[i]){
                        int x,y;
                        x=2*a[i]*(p[j]-d[i]);
                        y=v[i]*v[i];
                        vt=sqrt(x+y);
                        if(vt>vm) {
                            cnt++;
                            if(a[i]>0){
                                l[i]=j;
                                r[i]=m;

                            }
                            if(a[i]<0){
                                    l[i]=j;
                                for(int k=j;k<=m;k++){
                                    int vtt=sqrt(2*a[i]*(p[k]-d[i])+v[i]*v[i]);
                                    if(vtt>vm){

                                        r[i]=k;
                                    }
                            }
                            }
                            break;
                        }
                    }
                }
                if(a[i]==0){
                    if(p[j]<d[i]){
                        continue;
                    }
                    if(v[i]>vm) {cnt++;l[i]=j;r[i]=m;}
                }
            }
            vt=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(l[j]>=l[i]&&r[j]<=r[i]) {l[i]=l[j];r[i]=r[j];}
                if(l[j]<=l[i]&&r[j]>=r[i]) {l[j]=l[i];}
                if(l[j]>=l[i]&&r[j]<=r[i]) {r[j]=r[i];}
        }
        }
        for(int i=1;i<=n;i++){
            for(int j=l[i];j<=r[i];j++){
                c[j]=1;
            }
        }

        for(int i=1;i<=n;i++){
                if(c[i]!=0){
            c[i]+=c[i-1];
            c[i-1]=0;}
        }
for(int i=1;i<=n;i++){
           if(c[i]!=0) cntt++;
        }
        cout<<cnt<<" "<<m-cntt<<endl;
        cnt=0;
        cntt=0;
    }
    return 0;
}
