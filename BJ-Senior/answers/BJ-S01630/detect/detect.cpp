#include<bits/stdc++.h>
using namespace std;
int n,m,l,vm;
int d[100005];
int v[100005];
int a[100005];
int xx[100005];
struct node{
    int l;
    int r;
    inline bool operator < (const node &b)const{
        return r<b.r;
    }
}c[100005];
inline bool sle(int d,int v,int a,int x){
    if(x<d)cerr<<"BUG"<<endl;
    x-=d;
    return (vm*vm-v*v<2ll*a*x);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int ans1=0;
        cin>>n>>m>>l>>vm;
        for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++)cin>>xx[i];
        sort(xx+1,xx+1+m);
        for(int i=1;i<=n;i++){
            if(a[i]>=0){

                c[i].r=m;
                int ll=lower_bound(xx+1,xx+1+m,d[i])-xx;
                if(xx[ll]<d[i])ll++;
                int rr=m,mid,ans=-1;
                while(ll<=rr){
                    mid=((ll+rr)>>1);
                    if(sle(d[i],v[i],a[i],xx[mid])){
                        ans=mid;
                        rr=mid-1;
                    }else ll=mid+1;
                }
                c[i].l=ans;
                if(c[i].l==-1)c[i].r=-1;
            }
            if(a[i]<0){
                int ll=lower_bound(xx+1,xx+1+m,d[i])-xx;
                c[i].l=ll;
                if(xx[ll]<d[i])ll++;
                int rr=m,mid;
                int ans=-1;
                while(ll<=rr){
                    mid=((ll+rr)>>1);
                    if(sle(d[i],v[i],a[i],xx[mid])){
                        ans=mid;
                        ll=mid+1;
                    }else rr=mid-1;
                }
                c[i].r=ans;
                if(c[i].r==-1)c[i].l=-1;
            }
//            cout<<c[i].l<<" "<<c[i].r<<endl;
            if(c[i].l!=-1)ans1++;
        }
        int ans=0,mxk=-1;
        sort(c+1,c+1+n);
        for(int i=1;i<=n;i++){
            if(mxk<c[i].l){
                ans++;
                mxk=c[i].r;
            }
        }
        cout<<ans1<<" "<<m-ans<<endl;
//        cout<<endl<<endl<<endl<<endl;
    }
    return 0;
}
