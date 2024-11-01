#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,m,L,lim,cnt;
pair<ll,ll> car[100010];
ll speed[100010],vis[100010];
priority_queue<pair<ll,ll>> q1;
set<ll> s[100010];
bool operator<(pair<ll,ll> a,pair<ll,ll> b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first>b.first;
}
int mmin(ll a,ll b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}
struct node{
    int val,id;
}vi[100010];
bool operator<(const node &a,const node &b){
    return a.val>b.val;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>L>>lim;
        for(ll i=1;i<=n;i++){
            ll d,v,a;
            cin>>d>>v>>a;
            if(a<=0&&v<=lim){
                car[i].first=car[i].second=L+1;
            }else if(v>lim && a<0){
                car[i].first=d;
                car[i].second=mmin(L+1,(ll)ceil((float)d+((float)lim+v)*((float)lim-v)/((float)2*a))-1);
            }else if(v>lim && a>=0){
                car[i].first=d;
                car[i].second=L+1;
            }else{
                car[i].first=mmin(L+1,d+(ll)floor(((float)lim+v)*((float)lim-v)/((float)2*a)+1));
                car[i].second=L+1;
            }
        } memset(vis,0,sizeof vis);
        int cntt=0;memset(vi,0,sizeof vi);
        for(int i=1;i<=m;i++){
            cin>>speed[i];
            for(int j=1;j<=n;j++){
                if(car[j].first<=speed[i]&&car[j].second>=speed[i]&&!vis[j]){
                    vis[j]=1;
                    cnt++;
                    s[j].insert(speed[i]);vi[i].id=speed[i];
                    cntt++;vi[i].val++;
                }else if(car[j].first<=speed[i]&&car[j].second>=speed[i]&&vis[j]){
                    s[j].insert(speed[i]);vi[i].id=speed[i];
                    cntt++;vi[i].val++;
            }
            }
        }
        cout<<cnt<<" ";
        sort(vi+1,vi+n+1);
        ll ttp=cnt;
        cnt=0;
        memset(vis,0,sizeof vis);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[j].find(vi[i].id)!=s[j].end()&&vis[j]==0){
                    vis[j]=1;cnt++;
                }
            }
            if(cnt==ttp){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
