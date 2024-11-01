#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int d[100005],v[100005],a[100005],p[100005],INF=0x3f3f3f3f;
int n,m,L,V,ans1=0;
struct pr{
    int st,ed;
};
pr k[100005];
int ck(int x){
    bool vis[30];
    memset(vis,0,sizeof(vis));
    int sum=0;
    for(int i=0;i<m;i++){
        bool s=x%2;
        x/=2;
        if(s){
            //cout<<p[i]<<' ';
            sum++;
            for(int j=0;j<ans1;j++){
                if(k[j].st<=p[i]&&p[i]<=k[j].ed){
                    vis[j]=1;
                    //if(p[i]==15) cout<<k[j].st<<' '<<k[j].ed<<'\n';
                }
            }
        }
    }
    //cout<<'\n';
    for(int i=0;i<ans1;i++){
        if(!vis[i]){
            return -1;
        }
    }
    //cout<<"success\n";
    return sum;
}
void fun(){
    for(int i=0;i<n;i++){
        if(a[i]==0){
            if(v[i]>V&&d[i]<=p[m-1]){
                k[ans1++]={d[i],INF};
                //cout<<i<<' '<<k[ans1-1].st<<' '<<k[ans1-1].ed<<'\n';
            }
        }
        else if(a[i]>0){
            int q=V*V-v[i]*v[i];
            q=q/(2*a[i])+1;
            if(d[i]+q<=p[m-1]&&(d[i]<p[m-1]||d[i]==p[m-1]&&v[i]>V)){
                //cout<<i<<' ';
                k[ans1++]={max(d[i],d[i]+q),INF};
                //cout<<i<<' '<<k[ans1-1].st<<' '<<k[ans1-1].ed<<'\n';
            }
        }
        else{
            if(v[i]<=V) continue;
            int q=V*V-v[i]*v[i];
            q=q/(2*a[i]);
            if(p[lower_bound(p,p+m,d[i]+q)-p]>=d[i]&&q!=0){
                //cout<<i<<' ';
                k[ans1++]={d[i],d[i]+q};
                //cout<<i<<' '<<k[ans1-1].st<<' '<<k[ans1-1].ed<<'\n';
            }
        }
    }
    cout<<ans1<<' ';
    int minn=INF;
    for(int i=0;i<(1<<m);i++){
        int s=ck(i);
        if(s!=-1) minn=min(minn,s);
    }
    cout<<m-minn<<' ';
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        ans1=0;
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>p[i];
        }
        sort(p,p+m);
        if(n<=20&&m<=20){
            fun();
            continue;
        }
        for(int i=0;i<n;i++){
            if(a[i]==0){
                if(v[i]>V&&d[i]<=p[m-1]) ans1++;
            }
            else if(a[i]>0){
                int q=V*V-v[i]*v[i];
                q=q/(2*a[i])+1;
                if(d[i]+q<=p[m-1]&&(d[i]<p[m-1]||d[i]==p[m-1]&&v[i]>V)) ans1++;
            }
        }
        cout<<ans1<<' ';
        if(ans1==0) m++;
        cout<<m-1<<'\n';
    }
    return 0;
}
/*
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int d[100005],v[100005],a[100005],p[100005],INF=0x3f3f3f3f;
struct pr{
    int st,ed;
};
pr k[100005];
int main(){
    freopen("detect3.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,L,V,ans1=0;
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>p[i];
        }
        sort(p,p+m);
        for(int i=0;i<n;i++){
            if(v[i]<=V&&a[i]<=0){
                continue;
            }
            int q=V*V-v[i]*v[i];
            if(a[i]<0){
                k[ans1]={d[i],d[i]+q/(2*a[i])};
            }
            else if(v[i]<V){
                k[ans1]={int(d[i])+ceil((double)q/(2.0*(double)a[i])),INF};
            }
            else if(v[i]==V){
                k[ans1]={d[i]+1,INF};
            }
            else{
                k[ans1]={d[i],INF};
            }
            if(p[int(lower_bound(p,p+m,k[ans1].ed)-p)]>=k[ans1].st){
                ans1++;
                cout<<p[int(lower_bound(p,p+m,k[ans1].ed)-p)]<<' '<<k[ans1].st<<' '<<k[ans1].ed<<'\n';
            }
            else k[ans1]={0,0};
        }
        cout<<ans1<<' '<<m-1<<'\n';
    }
    return 0;
}
*/
