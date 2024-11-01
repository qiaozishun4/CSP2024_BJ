#include <bits/stdc++.h>
using namespace std;
struct car{
    long long d,v,a;
}c[100007];
long long t[100007];
struct s{
    long long l,r;
}vis[100007];
bool cmp(s x,s y){
    return x.r<y.r;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        long long n,m,L,V,sum=0,flag=0,j=-1;
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
        }
        for(int i=0;i<m;i++){
            cin>>t[i];
        }
        sort(t,t+m);
        for(int i=0;i<n;i++){
            if(c[i].a>0){
                if(t[m-1]>=c[i].d){
                    double f=c[i].v*c[i].v+2*c[i].a*(t[m-1]-c[i].d);
                    f=sqrt(f);
                    if(f>V){
                        sum++;
                        vis[++j].r=m-1;
                        long long p=V*V-c[i].v*c[i].v;
                        if(p%(2*c[i].a)==0) p/=(2*c[i].a);
                        else p=p/(2*c[i].a)+1;
                        int l=0,r=m-1;
                        while(l<=r){
                            int mid=(l+r)/2;
                            if(t[mid]>=p){
                                r=mid-1;
                            }
                            if(t[mid]<p){
                                l=mid+1;
                            }
                        }
                        vis[j].l=l;
                    }
                }
            }
            else{
                int l=0,r=m-1;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(t[mid]>=c[i].d){
                        r=mid-1;
                    }
                    if(t[mid]<c[i].d){
                        l=mid+1;
                    }
                }
                double f=c[i].v*c[i].v+2*c[i].a*(t[l]-c[i].d);
                f=sqrt(f);
                if(f>V){
                    sum++;
                    vis[++j].l=l;
                    if(c[i].a==0){
                        vis[j].r=m-1;
                        continue;
                    }
                    long long p=V*V-c[i].v*c[i].v;
                    p/=(2*c[i].a);
                    l=0,r=m-1;
                    while(l<=r){
                        int mid=(l+r)/2;
                        if(t[mid]>p){
                            r=mid-1;
                        }
                        if(t[mid]<=p){
                            l=mid+1;
                        }
                    }
                    vis[j].r=r;
                }
            }
        }
        cout<<sum<<" ";
        sort(vis,vis+j+1,cmp);
        int cnt=1,p=vis[0].r;
        for(int i=1;i<=j;i++){
            if(vis[i].l>p){
                cnt++;
                p=vis[i].r;
            }
        }
        cout<<m-cnt<<endl;
    }
    return 0;
}