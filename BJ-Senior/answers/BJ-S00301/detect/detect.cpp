//24 yi3 hou4 dou1 shi4 hao3 shu4!
//shijianfuzadu kongzhizai Onlogn zuoyou
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
int n,m,l,v;
struct car{
    int s,v,a;//f f' f''
}c[1000500];//che
struct qujian{
    int x,y,num;
}qj1[1000500],qj2[1000500];
bool cmp1(qujian a,qujian b){
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}
bool cmp2(qujian a,qujian b){
    if(a.y!=b.y) return a.y<b.y;
    return a.x<b.x;
}
int cs[1000500];//chao su shi jian
int t_[1000500];//cesuyi
int t[1000500];//cesuyi
int st[1000500];
int vis[1000500];
int qj1dic[1000500];
int qj2dic[1000500];
bool have_csy(int a,int b){
    if(a==0) return st[b]!=0;
    if(st[b]-st[a-1]==0) return 0;
    else return 1;
}
int find_greater(int x){
    int l=1,r=m;
    int ans,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(t_[mid]<x){
            l=mid+1;
        }else{
            ans=mid;
            r=mid-1;
        }
    }
    return ans;
}
int find_less(int x){
    int l=1,r=m;
    int ans,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(t_[mid]<=x){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    return ans;
}
void fuzhi(int a,int b,int i){
    qj1[i].x=find_greater(a);
    qj1[i].y=find_less(b);
    qj2[i].x=qj1[i].x;
    qj2[i].y=qj1[i].y;
    qj1[i].num=i;
    qj2[i].num=i;
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(cs,0,sizeof cs);
        memset(t_,0,sizeof t_);
        memset(t,0,sizeof t);
        memset(st,0,sizeof st);
        memset(vis,0,sizeof vis);
        memset(qj1dic,0,sizeof qj1dic);
        memset(qj2dic,0,sizeof qj2dic);

        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++) cin>>c[i].s>>c[i].v>>c[i].a;
        for(int i=1;i<=m;i++) cin>>t_[i],t[t_[i]]=1;
        for(int i=1;i<=l;i++) st[i]=st[i-1]+t[i];
        for(int i=1;i<=n;i++){
            if(c[i].a==0) cs[i]=-1;
            else cs[i]=(v*v-(c[i].v)*(c[i].v))/2*c[i].a;
        }
        int ans=0;
        //duiyu meiliangche
        for(int i=1;i<=n;i++){
            if(c[i].a==0){
                if(c[i].v>v&&have_csy(c[i].s,l)){
                    ans++;
                    fuzhi(c[i].s,l,ans);
                }
            }else if(c[i].a<0){
                if(c[i].v>v&&cs[i]>l&&have_csy(c[i].s,l)){
                    ans++;
                    fuzhi(c[i].s,l,ans);
                }else if(c[i].v>v&&cs[i]<=l&&have_csy(c[i].s,cs[i])){
                    ans++;
                    fuzhi(c[i].s,cs[i],ans);
                }
            }else if(c[i].a>0){
                if(c[i].v>v&&have_csy(c[i].s,l)){
                    ans++;
                    fuzhi(c[i].s,l,ans);
                }else if(c[i].v<=v&&cs[i]<=l&&have_csy(cs[i],l)){
                    ans++;
                    fuzhi(cs[i],l,ans);
                }
            }
        }
        cout<<ans<<" ";
        sort(qj1+1,qj1+ans+1,cmp1);
        sort(qj2+1,qj2+ans+1,cmp2);
        for(int i=1;i<=ans;i++) qj1dic[qj1[i].num]=i;
        for(int i=1;i<=ans;i++) qj2dic[qj2[i].num]=i;
        int ans2=0;
        for(int i=1;i<=ans;i++){
            if(vis[qj2[i].num]==1) continue;
            ans2++;
            int x=qj2[i].x,y=qj2[i].y;
            int j=qj1dic[qj2[i].num];
            while(qj1[j].x<=y){
                vis[qj1[j].num]=1;
                j++;
            }
        }
        cout<<m-ans2<<endl;
    }
    return 0;
}