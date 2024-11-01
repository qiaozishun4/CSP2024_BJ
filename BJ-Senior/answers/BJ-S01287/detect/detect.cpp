#include<bits/stdc++.h>
using namespace std;
long long n,m,l,v,d[10005],u[10005],c[10005],x[100005],b[100005];
struct N{
    long long r;
    vector<long long> a;
}p[10005];
struct Y{
    long long x,y;
}e[100005];
bool cmp(Y a,Y b){
    if(a.x==0){
        return 0;
    }
    if(b.x==0){
        return 1;
    }
    return a.x<b.x;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        long long cnt=0,ans=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>u[i]>>c[i];
        }
        for(int i=1;i<=m;i++){

            cin>>p[i].r;
        }
        for(int i=1;i<=n;i++){

            if(c[i]>0){
                int uv=u[i];
                for(int j=1;d[i]*j+0.5*c[i]*j*j<=l;j++){
                    if(u[i]+c[i]*j>v){
                        x[i]=d[i]*j+0.5*c[i]*j*j;
                        break;
                    }
                }
                for(int j=1;j<=m;j++){
                    if(p[j].r>=x[i]){
                        b[i]=1;
                        e[i].x=j;
                        e[i].y=i;
                        p[j].a.push_back(i);
                    }
                }
            }
            else{
                int uv=u[i];
                for(int j=1;d[i]*j+0.5*c[i]*j*j<=l;j++){
                    if(u[i]+c[i]*j<=v){
                        x[i]=d[i]*j+0.5*c[i]*j*j;
                        break;
                    }
                }
                for(int j=1;j<=m;j++){
                    if(p[j].r<x[i]&&p[i].r>=d[i]){
                        b[i]=1;
                        e[i].x=j;
                        e[i].y=i;
                        p[j].a.push_back(i);
                    }
                }
            }


        }
        sort(e+1,e+n+1,cmp);
        N px;
        for(int i=1;i<=n;i++){
            if(e[i].x!=0){
                cnt++;
                bool bll=0;
                for(auto k:px.a){
                    if(k==e[i].y){
                        bll=1;
                        break;
                    }
                }
                if(bll){
                    continue;
                }
                px=p[e[i].x];
                ans++;
            }

        }
        cout<<cnt<<' '<<m-ans<<endl;
    }
}
