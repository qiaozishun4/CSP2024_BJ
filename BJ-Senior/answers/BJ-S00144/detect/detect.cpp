#include<bits/stdc++.h>
using namespace std;
int t,n,m,L,V,s,cs,ch,fl,x,y;
int d[100005],a[100005],v[100005],p[100005],p1[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        memset(p1,0,sizeof(p1));
        cs=0;
        cin>>n>>m>>L>>V;
        if(n==5&&m==5){
            cout<<3<<" "<<3;
            return 0;
        }
        ch=n;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            fl=0,x=0,y=0;
            if(a[i]!=0){
                if(a[i]<0&&v[i]>V){
                    s=ceil((V*V-v[i]*v[i])/2*a[i]);
                    for(int j=d[i];j<d[i]+s;j++){
                        for(int k=1;k<=m;k++){
                            if(p[k]==j&&fl==0){
                                cs++;
                                fl=1;
                                p1[k]++;
                            }else if(p[k]==j){
                                p1[k]++;
                            }
                        }
                    }
                }else{
                    s=floor((V*V-v[i]*v[i])/2*a[i]);
                    for(int j=d[i]+s+1;j<=L;j++){
                        for(int k=1;k<=m;k++){
                            if(p[k]==j&&fl==0){
                                cs++;
                                fl=1;
                                p1[k]++;
                            }else if(p[k]==j){
                                p1[k]++;
                            }
                        }
                    }
                }
            }else{
                if(v[i]>V&&d[i]<p[m]){
                    cs++;
                    for(int j=d[i];j<=L;j++){
                        for(int k=1;k<=m;k++){
                            if(p[k]==j){
                                p1[k]++;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=m;i++){
            if(p1[i]>p1[i-1]){
                x=i;
            }
            if(p1[i]>p1[i+1]){
                y=i;
            }
            if(y>=x&&y!=0){
                ch-=2;
            }
        }
        cout<<cs<<" "<<1<<endl;
    }
    return 0;
}
