#include<iostream>
#include<algorithm>
#include<cmath>
int main(){
    using namespace std;
    typedef long long ll;
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin.tie(nullptr)->sync_with_stdio(0);
    auto length=[](ll speed,ll time,ll add)->ll {
        if(add==0) return speed*time;
        return speed*time+1.0/2*add*time*time;
    };
    auto speed_add=[](ll speed,ll time,ll add)->ll {
        if(add==0) return speed;
        return speed+add*time;
    };
    auto tick_speed=[](ll speed,ll len,ll add)->double {
        if(add==0) return speed;
        return sqrt(speed*speed+2*add*len);
    };
    for(cin>>T;T;T--){
        /*
        ll n,m,L,V;
        cin>>n>>m>>L>>V;
        ll d[n+1],v[n+1],a[n+1];
        for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
        pair<ll,bool> p[m+1];//pair<pos,detected count>
        ll ans=0;
        for(int i=1;i<=m;i++) cin>>p[i].first;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j].first<d[i]) continue;
                if(tick_speed(v[i],length(v[i],)))
            }
        }
        */
        ll n,m,L,V;
        cin>>n>>m>>L>>V;
        ll d[n+1],v[n+1],a[n+1];
        bool beyond[n+1]={0};
        for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
        pair<ll,bool> p[m+1];//pair<pos,detected count>
        ll ans=0;
        for(int i=1;i<=m;i++) cin>>p[i].first;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j].first<d[i]) continue;
                if(v[i]>V){
                    p[j].second=1;
                    if(!beyond[i]) beyond[i]=1,ans++;
                }
            }
        }
        cout<<ans<<' ';
        long long cnt=0;
        for(int i=1;i<=m;i++) if(!p[i].second) cnt++;
        cout<<cnt<<'\n';
    }
    return 0;
}