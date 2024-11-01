#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxs,t,n,m,L,V,bs,d[100010],v[100010],a[100010],p[100010],s,dels,l,r,cu[1000010];
ll k[1000010];
bool flagA=1,flagB=1,flagC=1,mpk[30][30];
map<pair<ll,ll>,bool> mp;
vector<ll> vec;
bool cuif(ll l,ll r){
    return cu[r]-cu[l-1];
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        s=0;
        maxs=0;
        bs=0;
        mp.clear();
        flagA=1;
        flagB=1;
        flagC=1;
        memset(cu,0,sizeof cu);
        memset(k,0,sizeof k);
        cin>>n>>m>>L>>V;
        for(ll i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            d[i]++;
            if(a[i]!=0) flagA=0;
            if(a[i]<=0) flagB=0;
            if(a[i]>=0) flagC=0;
        }for(ll i=1;i<=m;i++){
            cin>>p[i];
            k[p[i]]=1;
        }for(ll i=1;i<=L;i++){
            cu[i]=k[i]+cu[i-1];
        }for(ll i=1;i<=n;i++){
            if(a[i]==0){
                if(v[i]>V) mp[{d[i],L}]=1;
            }else if(a[i]>0){
                mp[{d[i]+ceil(1.0*((V*V-v[i]*v[i])/(2*a[i]))),L}]=1;
            }else{
                if(v[i]>V){
                    mp[{d[i],d[i]+ceil(1.0*((V*V-v[i]*v[i])/(2*a[i])))}]=1;
                }
            }
        }for(auto i:mp){
            if(cuif(i.first.first,i.first.second)>0){
                s++;
            }
        }
        cout<<s<<" ";
        if(flagB){
        for(auto i:mp){
            if(cuif(i.first.first,i.first.second)>0){
                if(i.first.first>maxs) maxs=i.first.first;
                if(i.first.first==i.first.second&&i.first.first<maxs) bs++;
            }
        }
            cout<<m-bs-cuif(maxs,L)<<endl;
            continue;
        }
        ll M=1<<m;
        for(ll i=1;i<M;i++){
            vec.clear();
            ll ks=0;
            for(ll j=1;j<=m;j++){
                if((1<<j)&i){
                    vec.push_back(p[j]);
                }
            }memset(mpk,0,sizeof mpk);
            for(ll j=0;j<vec.size();j++){
                for(auto i:mp){
                    if(cuif(i.first.first,i.first.second)>0&&i.first.first<=vec[j]&&i.first.second>=vec[j]&&mpk[i.first.first][i.first.second]==0){
                        ks++;
                        mpk[i.first.first][i.first.second]=1;
                    }
                }if(mp.size()==ks){
                    if(n-vec.size()>dels){
                        dels=n-vec.size();
                    }
                }
            }
        }
        cout<<dels<<endl;
    }

    return 0;
}
