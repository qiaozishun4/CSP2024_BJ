#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,l,v;
ll d[1000009],v1[1000009],a[1000009];
ll pos[1000009];
ll vis[1000009],cnt=0;
bool ismus,is0,isnum;
ll _sqrt(ll x){
ll l=0,r=x;
while(l<r){
  ll mid=l+r>>1;
  if(mid*mid==x)return mid;
  else if(mid*mid>x)r=mid;
  else l=mid+1;
}
return l;
}
ll bs(ll tgt){
ll l=1,r=m;
while(l<r){
    ll mid=l+r>>1;
    if(pos[mid]>=d[tgt]){
        r=mid;
    }
    else l=mid+1;
}
return r;
}

void slv(){
    ll ans1=0,ans2=0;
for(ll i=1;i<=n;i++){
        ll spd; if(d[i]>pos[m])continue;
    if(a[i]==0){

        if(v1[i]>v)ans1++;
    }
    if(a[i]>0){
        ll dis=pos[m]-d[i];
        if(_sqrt(v1[i]*v1[i]+2*a[i]*dis)>v)ans1++;
    }
    if(a[i]<0){
         ll p=pos[bs(i)];
      //  cout<<p<<endl;
        ll dis=p-d[i];
        spd=(_sqrt(v1[i]*v1[i]+2*a[i]*dis));
        if(spd>v)ans1++;
    }
}
if(is0)ans2=m-1;
else if(isnum)ans2=m-1;
else if(ans1==0)ans2=m;
else{
        ans2=0;
  for(int s=1;s<=m;s++){
        bool f=1;
    for(ll i=1;i<=n;i++){
    if(d[i]>pos[m])continue;
    if(a[i]==0){
        if(v1[i]>v){
            if(ans2==m)f=0;
        }
    }
    if(a[i]>0){bool F=0;
   ll p=(3*3-v1[i]*v1[i])/2/a[i];
        for(ll j=m;pos[j]>=p&&j>=1;j--){
            if(vis[j]==1){F=1;break;}
        }
        if(!F)f=0;
    }
    if(a[i]<0&&v1[i]>v){bool F=0;

        ll p=(3*3-v1[i]*v1[i])/2/a[i];
            cout<<p<<endl;
        for(ll j=bs(i);pos[j]<=p&&j<=m;j++){
           if(vis[j]==1){F=1;break;}
        }
        if(!F)f=0;
    }
    }
    if(f)ans2++;
    else vis[s]=1;
  }
}
cout<<ans1<<" "<<ans2<<endl;
}
int main(){
freopen("detect.in","r",stdin);
freopen("detect.out","w",stdout);
    ll t;ismus=is0=isnum=1;
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>v;
        for(ll i=1;i<=n;i++){
            cin>>d[i]>>v1[i]>>a[i];
            if(a[i]>0)ismus=0,is0=0;
            if(a[i]==0)ismus=0,isnum=0;
            if(a[i]<0)is0=0,isnum=0;
        }
        for(ll j=1;j<=m;j++)cin>>pos[j];
memset(vis,0,sizeof vis);
        slv();
    }
    return 0;
}
