#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAXN=1e5+5;
const ll MOD=1e9+7;
ll a[MAXN],r[MAXN],h[MAXN];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ll n,sum=0;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        r[a[i]]+=1;
        h[a[i]]+=1;
    }
    ll x=0,y=0;
    for(ll i=1;i<=1e5;i++){
        if(r[i]!=0){
            if(x==0&&y==0) x=i;
            else{
                y=i;
                //cout<<y<<"kill"<<x<<endl;
                if(r[y]>h[x]){
                    //cout<<"1";
                    r[y]-=h[x];
                    r[x]=0;
                    h[x]=0;
                    x=y;
                    y=0;
                    //cout<<y<<"kill"<<x<<endl;
                }
                else if(r[y]<h[x]){
                    //cout<<"2";
                    //cout<<h[y]<<"kill"<<h[x]<<endl;
                    h[x]-=r[y];
                    r[y]=0;
                    r[x]-=r[y];
                    y=0;
                    //cout<<y<<"kill"<<x<<endl;
                }
                else{
                    //cout<<"3";
                    r[y]=0;
                    r[x]=0;
                    h[x]=0;
                    x=y;
                    y=0;
                    //cout<<y<<"kill"<<x<<endl;
                }
            }
        }
    }
    for(ll i=1;i<=1e5;i++){
        sum+=h[i];
        //if(h[i]!=0) cout<<"i="<<i<<" h="<<h[i]<<endl;
    }
    cout<<sum<<endl;
    return 0;
}