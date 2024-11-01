#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int d[N],v[N],a[N],p[N];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        int maxn=m,minn=1;
        int sum=0;
        int l,r,mid;
        for(int i=1;i<=n;i++){
            if(a[i]>0){
                double out,oo,uu;
                oo=(V*V-v[i]*v[i]);uu=2*a[i];
                out=oo/uu;
                out+=d[i];
                if(out>=p[m]) continue ;
                l=1,r=m,mid=(l+r)/2;
                while(l<r){
                    if(p[mid]<out){
                        l=mid+1;
                    }
                    else if(p[mid]>=out){
                        r=mid-1;
                    }
                }
                sum++;
                maxn=min(maxn,m);
                minn=max(minn,l);
            }
            else if(a[i]==0){
                if(v[i]<=V) continue ;
                l=1,r=m,mid=(l+r)/2;
                while(l<r){
                    if(p[mid]<d[i]){
                        l=mid+1;
                    }
                    else if(p[mid]>=d[i]){
                        r=mid-1;
                    }
                }
                sum++;
                maxn=min(maxn,m);
                minn=max(minn,l);
            }
            else if(a[i]<0){
                if(v[i]<V) continue ;
                double out,oo,uu;
                oo=(V*V-v[i]*v[i]);uu=2*a[i];
                out=oo/uu;
                out+=d[i];
                if(out>=p[m]) continue ;
                l=1,r=m,mid=(l+r)/2;
                while(l<r){
                    if(p[mid]<out){
                        l=mid+1;
                    }
                    else if(p[mid]>=out){
                        r=mid-1;
                    }
                }
                int l1=l;
                l=1,r=m;
                while(l<r){
                    if(p[mid]<d[i]){
                        l=mid+1;
                    }
                    else if(p[mid]>=d[i]){
                        r=mid-1;
                    }
                }
                if(l1==l) continue;
                maxn=min(maxn,l1-1);
                minn=max(minn,l);
                sum++;
            }
        }
        cout<<sum<<" ";
        cout<<maxn-minn<<endl;
    }
    return 0;
}
