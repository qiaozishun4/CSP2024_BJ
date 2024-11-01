#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const double eps=1e-9;
int n,m,L,p[N],psum[N],pre[N],last[N];
double V,d[N],v[N],a[N];
typedef pair<int,int> pii;
vector<pii> task;
inline void solve(){
    cin>>n>>m>>L>>V;
    for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
    for(int i=1;i<=m;i++)cin>>p[i];
    sort(p+1,p+1+m);
    for(int i=0;i<=L;i++)psum[i]=0;
    for(int i=1;i<=m;i++)psum[p[i]]=1;
    for(int i=0;i<=L;i++)psum[i]+=psum[i-1];
    int ans1=0;
    task.clear();
    for(int i=1;i<=n;i++){
        if(a[i]>0){
            //double tmp=d[i]+(V*V-v[i]*v[i])/(a[i]*2);
            //if(ceil(tmp)-tmp<0.00001&&tmp-floor(tmp)>0.00001)cerr<<d[i]<<' '<<v[i]<<' '<<a[i]<<'\n';
            int pos=floor(d[i]+(V*V-v[i]*v[i])/(a[i]*2))+1;
            if(v[i]>V)pos=d[i];
            if(pos>L)continue;
            if(psum[L]-psum[pos-1]>0){
                //assert(v[i]*v[i]+a[i]*2*(pos-d[i])>V*V&&v[i]*v[i]+a[i]*2*(pos-d[i]-1)<=V*V);
                ans1++;
                task.push_back(pii(pos,L));
            }
        }
        else if(a[i]==0){
            if(v[i]>V&&psum[L]-psum[(int)d[i]-1]>0){
                ans1++;
                task.push_back(pii(d[i],L));
            }
        }
        else{
            if(v[i]<=V)continue;
            int pos=ceil(d[i]+(V*V-v[i]*v[i])/(a[i]*2))-1;
            //assert(v[i]*v[i]+a[i]*2*(pos-d[i])<=V*V/*&&v[i]*v[i]+a[i]*2*(pos-d[i]-1)<=V*V*/);
            //double tmp=d[i]+(V*V-v[i]*v[i])/(a[i]*2);
            //if(tmp-floor(tmp)<0.00001)cerr<<d[i]<<' '<<v[i]<<' '<<a[i]<<'\n';
            pos=min(pos,L);
            if(psum[pos]-psum[(int)d[i]-1]>0){
                ans1++;
                task.push_back(pii(d[i],pos));
            }
        }
    }
    cout<<ans1<<' ';
    pre[0]=0;
    for(int i=1;i<=L;i++){
        if(psum[i]>psum[i-1])pre[i]=i;
        else pre[i]=pre[i-1];
    }
    sort(task.begin(),task.end());
    for(int i=0;i<=L;i++)last[i]=0;
    int ans2=0;
    vector<pii> vec;
    //for(pii p:task)cout<<p.first<<' '<<p.second<<endl;
    //for(int i=0;i<=L;i++)cout<<pre[i]<<' ';cout<<endl;
    //return;
    for(int i=0,j=0;i<=L;i++){
        while(j<task.size()&&task[j].first==i){
            last[pre[task[j].second]]++;
            vec.push_back(task[j]);
            j++;
        }
        if(last[i]>0){
            for(pii pr:vec){
                last[pre[pr.second]]--;
            }
            vec.clear();
            ans2++;
        }
    }
    cout<<m-ans2<<'\n';
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}
