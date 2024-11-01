#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<queue>
#include<cstring>
#include<cstdio>
#include<set>
#include<map>
using namespace std;
const int Q=3005;
int cnt,b[Q],tot,a[Q],s[Q],f[Q];
struct in{
    int be,en;
}p[Q];
bool cmp(in x,in y){
    if(x.en!=y.en) return y.en>x.en;
    return y.be>x.be;
}
int close(){
    int lst=0,cnt=0;
    for(int i=1;i<=tot;i++){
        if(lst<p[i].be){
            cnt++;
            lst=p[i].en;
        }
    }
    return cnt;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,l,v,cnt=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            int x;
            double y,z,t;
            cin>>x>>y>>z;
            if(y<=v&&z<=0) a[i]=-1;
            else if(y>v&&z>=0){
                a[i]=2e9;
                s[i]=x;
            }
            else{
                s[i]=x;
                t=(v-y)/z;
                a[i]=x+y*t+0.5*z*t*t;
                if(z>0) f[i]=1;
                else f[i]=0;
            }
        }
        for(int i=1;i<=m;i++) cin>>b[i];
        tot=1;
        for(int i=1;i<=n;i++){
            int st=0,ed=0;
            bool q=0;
            if(a[i]==-1) continue;
            if(a[i]==2e9){
                cnt++;
                p[tot]={s[i],l};
                tot++;
                continue;
            }
            if(f[i]) for(int j=1;j<=m;j++) if(b[j]>=a[i]){
                if(q==0) st=j;
                ed=j,q=1;
            }
            if(!f[i]) for(int j=1;j<=m;j++) if(b[j]>s[i]&&b[j]<=a[i]){
                if(q==0) st=j;
                ed=j,q=1;
            }
            if(q){
                cnt++;
                p[tot]={st,ed};
                tot++;
            }
        }
        tot--;
        cout<<cnt<<" ";
        sort(p+1,p+tot+1,cmp);
        cout<<m-close()<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
