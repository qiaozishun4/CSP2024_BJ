#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,l,vv;
struct shunxu{
    int st;
    int endd;
};
bool cmp(shunxu x,shunxu y){
    if(x.st!=y.st){
        return x.st<y.st;
    }
    else{
        return x.endd>y.endd;
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int pt=1;pt<=t;pt++){
        int d[100005],v[100005],a[100005],p[100005],pan[100005];
        shunxu shun[200005];
        for(int i=0;i<=100004;i++){
            d[i]=0;
            v[i]=0;
            a[i]=0;
            p[i]=0;
            pan[i]=0;
        }
        cin>>n>>m>>l>>vv;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
            pan[p[i]]++;
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            int s=0,ed=l;
            if(a[i]>0){
                s=d[i]+min(int(floor(1.0*(vv*vv-v[i]*v[i])/2/a[i]))+1,l+1);
            }
            if(a[i]==0){
                if(v[i]<=vv){
                    s=1e7;
                }
                else{
                    s=d[i];
                }
            }
            if(a[i]<0){
                if(v[i]<=vv){
                    s=1e7;
                }
                else{
                    s=d[i];
                    ed=d[i]+min((int)ceil(1.0*(vv*vv-v[i]*v[i])/2/a[i])-1,l+1);
                }
            }
            shun[i].st=s;
            shun[i].endd=ed;
            int pp=1;
            for(int j=s;j<=ed;j++){
                if(pan[j]!=0){
                    sum++;
                    pp=0;
                    break;
                }
            }
            if(pp==1&&s!=1e7){
                shun[i].st=1e7;
            }
        }
        cout<<sum<<" ";
        sort(shun+1,shun+n+1,cmp);
        int zuo,you=shun[1].endd;
        int ans=0;
        int panduan;
        for(int i=1;i<=n;i++){
            panduan=0;
            if(shun[i].st==1e7){
                continue;
            }
            zuo=shun[i].st;
            you=min(you,shun[i].endd);
            for(int j=zuo;j<=you;j++){
                if(pan[j]!=0){
                    panduan=1;
                }
            }
            if(panduan==0&&zuo!=1e7){
                ans++;
                you=shun[i].endd;
            }
        }
        cout<<m-ans-1<<"\n";
    }
    return 0;
}
