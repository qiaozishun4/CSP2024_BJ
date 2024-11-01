#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
// #include<cmath>
using namespace std;
const int N=100100;
inline int read(){
    int i=getchar(),r=0,s=1;
    while(i<'0'||i>'9'){if(i=='-')s=-1;i=getchar();}
    while(i>='0'&&i<='9')r=(r<<1)+(r<<3)+(i^48),i=getchar();
    return r*s;
}
int n,m,L,V,d[N],v[N],a[N],p[N],l[N],r[N],b[N];
inline bool cmp (const int &A,const int &B){return  r[A]<r[B];}
int t[N];
inline void add(int i,int k){while(i<N)t[i]+=k,i+=i&-i;}
inline int get_sum(int i){int r=0;while(i)r+=t[i],i-=i&-i;return r;}
void init(){
    memset(t,0,sizeof(t));
    cin>>n>>m>>L>>V;
    for(int i=1;i<=n;i++)d[i]=read(),v[i]=read(),a[i]=read();
    for(int i=1;i<=m;i++)p[i]=read();
    // sort(p+1,p+m+1);
}
double get_x(int i,double t){return t*t*a[i]/2+t*v[i]+d[i];}
inline int floor(double x){return (int)x;}
inline int cell(double x){return ((double)floor(x)==x)?(int)x:(int)x+1;}
inline int get_l(int l,int r,int i){
    while(l<r){
        int mid=(l+r)>>1;
        if(v[i]*v[i]+2*a[i]*(p[mid]-d[i])>V*V)r=mid;
        else l=mid+1;
    }
    if(v[i]*v[i]+2*a[i]*(p[l]-d[i])>V*V)return l;
    return l+1;
}
inline int get_r(int l,int r,int i){
    while(l<r){
        int mid=(l+r+1)>>1;
        if(v[i]*v[i]+2*a[i]*(p[mid]-d[i])>V*V)l=mid;
        else r=mid-1;
    }
    if(v[i]*v[i]+2*a[i]*(p[l]-d[i])>V*V)return l;
    return l-1;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;cin>>T;
    while(T--){
        init();
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(v[i]<=V){
                    l[i]=r[i]=0;
                    continue;
                }
                l[i]=lower_bound(p+1,p+m+1,d[i])-p;
                r[i]=m;
            }
            else if(a[i]<0){
                if(v[i]<=V){
                    l[i]=r[i]=0;
                    continue;
                }
                l[i]=lower_bound(p+1,p+m+1,d[i])-p;
                // int x=(V*V-v[i]*v[i])/(2*a[i]);
                // r[i]=upper_bound(p+1,p+m+1,x+d[i])-p-1;
                r[i]=get_r(l[i],m,i);
            }
            else{
                if(v[i]>V){
                    l[i]=lower_bound(p+1,p+m+1,d[i])-p;
                    r[i]=m;
                    continue;
                }
                // int x=(V*V-v[i]*v[i])/(2*a[i]);
                // if(2*a[i]*x<V*V-v[i]*v[i])x++;
                r[i]=m;
                // l[i]=lower_bound(p+1,p+m+1,x+d[i])-p;
                l[i]=get_l(lower_bound(p+1,p+m+1,d[i])-p,m,i);
            }
        }
        int tot=0,del=m;
        for(int i=1;i<=n;i++)if(l[i]<=r[i]&&1<=l[i]&&r[i]<=m){
            // if(v[i]*v[i]+2*a[i]*(p[l[i]]-d[i])<=V*V){
            //     cerr<<a[i]<<' '<<v[i]<<' '<<d[i]<<' '<<l[i]<<' '<<r[i]<<' '<<p[l[i]]<<endl;
            // }
            b[++tot]=i;
        }
        sort(b+1,b+tot+1,cmp);
        for(int i=1;i<=tot;i++){
            int curl=l[b[i]],curr=r[b[i]];
            if(get_sum(curr)-get_sum(curl-1))continue;
            add(curr,1);
            del--;
        }
        cout<<tot<<' '<<del<<endl;
    }
    fflush(stdout);
    fflush(stdin);
    fclose(stdin);
    fclose(stdout);
    return 0;
}