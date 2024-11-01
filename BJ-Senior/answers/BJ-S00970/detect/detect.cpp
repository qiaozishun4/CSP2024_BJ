#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n,m,l,V;
int g[1000005],p[1000005];
int dp[1000005];
int v[1000005],r[1000005];
int d[100005],vv[100005],a[100005];
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>V;
        for(int i=0;i<=l;i++){
            g[i]=1e9;
        }
        for(int i=1;i<=n;i++){
            cin>>d[i]>>vv[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        m++;
        p[m]=1e9;
        int ans1=0;
        for(int i=1;i<=n;i++){

            if(a[i]<0&&vv[i]>V){
                a[i]=-a[i];
                //long double t=1.0*(vv[i]-V)/a[i];//d,lst.
                //int lst=vv[i]*t+(a[i]*t*t)/2-1e-12+d[i];//<it could.
                int lst=((vv[i]-V)*vv[i]*2-((vv[i]-V)*(vv[i]-V))+2*a[i]-1)/(2*a[i])-1+d[i];
                //cout<<d[i]<<' '<<lst<<endl;
                lst=min(lst,l);
                if(p[lower_bound(p+1,p+m+1,d[i])-p]>lst)continue;
                ans1++;
                g[d[i]]=min(g[d[i]],lst);
            }
            else if(a[i]==0){
                if(vv[i]>V){//d,l.
                    //cout<<d[i]<<' '<<l<<endl;
                    if(p[lower_bound(p+1,p+m+1,d[i])-p]>l)continue;
                    ans1++;
                    g[d[i]]=min(g[d[i]],l);
                }
            }
            else if(a[i]>0){
                if(vv[i]>V){//d,l.
                    //cout<<d[i]<<' '<<l<<endl;
                    if(p[lower_bound(p+1,p+m+1,d[i])-p]>l)continue;
                    ans1++;
                    g[d[i]]=min(g[d[i]],l);
                }
                else{//lst,l.
                    //long double t=(V-vv[i])/a[i];
                    //int lst=t*vv[i]+(a[i]*t*t)/2+d[i]+1+1e-12;
                    int lst=((V-vv[i])*vv[i]*2+((V-vv[i])*(V-vv[i])))/(2*a[i])+1+d[i];
                    if(p[lower_bound(p+1,p+m+1,lst)-p]>l)continue;
                    ans1++;
                    g[lst]=min(g[lst],l);
                }
            }
        }
        p[0]=-1;
        int h=1,w=1;
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
        int z=0;
        //for(int i=1;i<=l;i++)if(g[i]!=1e9)cout<<i<<':'<<g[i]<<endl;
        for(int i=0;i<=m;i++)dp[i]=0;
        for(int i=1;i<=m;i++){
            for(int j=p[i-1]+1;j<=min(l,p[i]);j++){
                q.push({g[j],j});
            }
            while(q.size()&&q.top().first<p[i]){
                z++;
                while(q.size()&&q.top().second<p[z])q.pop();
            }
            dp[i]=dp[z]+1;
        }
        cout<<ans1<<' '<<m-dp[m]<<'\n';
        //cerr<<"awa";
    }
    return 0;
}
