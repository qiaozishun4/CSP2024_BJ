#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3fll
using namespace std;
int t,n,m,g,l,v,d,vv,a,cnt,ans,pans,p[100001],nxt[1000001],lst[1000001];
int GCD(int x,int y){
    return y?GCD(y,x%y):x;
}
int gcd(int x,int y){
    return x<y?GCD(y,x):GCD(x,y);
}
int rb(int x,int y){
    if(x%y){
        return x/y;
    }
    return x/y-1;
}
pair<int,int>c[100001];
bool cmp(pair<int,int>x,pair<int,int>y){
    return x.second==y.second?x.first<y.first:x.second<y.second;
}
set<int>st;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            c[i].first=0;
            c[i].second=-1;
            cin>>d>>vv>>a;
            if(a==0){
                if(vv>v){
                    c[i]=make_pair(d,l);
                }
            }else if(a<0){
                if(vv>v){
                    c[i]=make_pair(d,min(l,rb(v*v-vv*vv+2*a*d,2*a)));
                }
            }else{
                if(vv>v){
                    c[i]=make_pair(d,l);
                }else if(vv*vv+2*a*(l-d)>v*v){
                    c[i]=make_pair((v*v-vv*vv+2*a*d)/(2*a)+1,l);
                }
            }
        }
        memset(nxt,0,sizeof(nxt));
        memset(lst,0,sizeof(lst));
        for(int i=1;i<=m;i++){
            cin>>p[i];
            nxt[p[i]]=i;
            lst[p[i]]=i;
        }
        if(!nxt[l]){
            nxt[l]=-1;
        }
        if(!lst[0]){
            lst[0]=-1;
        }
        for(int i=l-1;i>=0;i--){
            if(!nxt[i]){
                nxt[i]=nxt[i+1];
            }
        }
        for(int i=1;i<=l;i++){
            if(!lst[i]){
                lst[i]=lst[i-1];
            }
        }
        cnt=0;
        for(int i=1;i<=n;i++){
            if(c[i].first<=c[i].second){
                if(nxt[c[i].first]==-1||lst[c[i].second]==-1){
                    c[i].first=0;
                    c[i].second=-1;
                }else{
                    if(nxt[c[i].first]<=lst[c[i].second]){
                        c[++cnt]=make_pair(nxt[c[i].first],lst[c[i].second]);
                    }
                }
            }
        }
        cout<<cnt<<" ";
        pans=-1;
        ans=0;
        sort(c+1,c+cnt+1,cmp);
        for(int i=1;i<=cnt;i++){
            if(c[i].first>pans){
                pans=c[i].second;
                ans++;
            }
        }
        cout<<m-ans<<"\n";
    }
}
