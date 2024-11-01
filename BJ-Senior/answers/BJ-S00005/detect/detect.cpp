#include<bits/stdc++.h>
using namespace std;
long long t,n,m,l,v,d[1000001],w[1000001],a[1000001],p[1000001],bo[1000001],ans2=0,pbo[1000001];
double le[1000001],re[1000001];
void check(){
    long long ans3=m;
    for(int i=1;i<=n;i++){
        bool boo=0;
        if(bo[i]){
            for(int j=1;j<=m;j++){
                if(pbo[j])if((le[i]<=double(p[j]))&&(double(p[j])<=re[i]))boo=1;
            }
        }
        if(!boo)return;
    }
    for(int i=1;i<=m;i++)ans3-=pbo[i];
    ans2=max(ans2,ans3);
}
void dfs(long long ceng){
    if(ceng==(m+1)){
        check();
        return;
    }
    dfs(ceng+1);
    pbo[ceng]++;
    dfs(ceng+1);
    pbo[ceng]--;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
                ans2=0;
            cin>>d[i]>>w[i]>>a[i];
            if(a[i]==0){
                if(v<w[i])le[i]=d[i],re[i]=l;
                else le[i]=1.0,re[i]=0.0;
                le[i]-=0.000001,re[i]+=0.000001;
            }
            if(a[i]>0){
                if(v<w[i])le[i]=double(d[i])-0.000001,re[i]=double(l)+0.000001;
                else if((v>=w[i])&&((double(d[i])+double(v*v-w[i]*w[i])/double(2*a[i]))<double(l)))le[i]=(double(d[i])+double(v*v-w[i]*w[i])/double(2*a[i]))+0.000001,re[i]=double(l)+0.000001;
                else le[i]=1.0,re[i]=0.0;
            }
            if(a[i]<0){
                if(v>=w[i])le[i]=1.0,re[i]=0.0;
                else if((double(d[i])+double(v*v-w[i]*w[i])/double(2*a[i]))>double(l))le[i]=d[i]-0.000001,re[i]=l+0.000001;
                else le[i]=d[i]-0.000001,re[i]=(double(d[i])+double(v*v-w[i]*w[i])/double(2*a[i]))-0.000001;
            }
        }
        for(int i=1;i<=m;i++)cin>>p[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((le[i]<double(p[j]))&&(double(p[j])<re[i]))bo[i]=1;
            }
        }
        long long ans1=0;
        for(int i=1;i<=n;i++)ans1+=bo[i];
        dfs(1);
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
