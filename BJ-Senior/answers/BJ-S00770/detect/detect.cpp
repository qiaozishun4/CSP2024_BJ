#include<bits/stdc++.h>
#define double long double
#define N 100105
using namespace std;
double L,V;
double eps=1e-12;
double d[N],v[N],a[N],p[N];
int lin[N];
int n,m;
struct node{
    int l1,r1;
}f[N];
bool cmp(node x,node y){
    if(x.r1==y.r1){
        return x.l1<y.l1;
    }else return x.r1<y.r1;
}
int zh(){
    int mmax=0,pos=-1;
    for(int i=1;i<=m;i++){
        if(lin[i]>mmax){
            mmax=lin[i];
            pos=i;
        }
    }
    return pos;
}
double check(int k){
    double l=0,r=L+1;
    while(l<=r){
        double mid=(l+r)/2;
        if(sqrt(v[k]*v[k]+2*a[k]*mid)>V){
            r=mid-0.01;
        }else{
            l=mid+0.01;
        }
    }
    return r+0.01;
}
double check1(int k){
    double l=0,r=L+1;
    while(l<=r){
        double mid=(l+r)/2;
        if(sqrt(v[k]*v[k]+2*a[k]*mid)>V){
            l=mid+0.01;
        }else{
            r=mid-0.01;
        }
    }
    return l-0.01;
}
int zhao(double k){
    int l=1,r=m;
    while(l<=r){
        int mid=(l+r)>>1;
        if(p[mid]+eps<k){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return r+1;
}
int zhao1(double k){
    int l=1,r=m;
    while(l<=r){
        int mid=(l+r)>>1;
        if(p[mid]+eps<=k){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return r+1;
}
double k;
int l,r;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            //cout<<"i:"<<i<<endl;
            f[i].l1=0,f[i].r1=0;
            if(a[i]==0){
                if(v[i]>V){
                    int l=zhao(d[i]);
                    if(l>m)continue;
                    f[i].l1=l,f[i].r1=m;
                    //cout<<l<<" "<<m<<endl;
                    ans++;
                }
                continue;
            }
            if(a[i]>0){
                k=d[i]+(V*V-v[i]*v[i])/2/a[i];
                l=zhao(k),r=m;
                if(l>r||r==0||l==0)continue;
                f[i].l1=l,f[i].r1=r;
                ans++;
                //<<l<<" "<<r<<endl;
            }else{
                double k=d[i]+(V*V-v[i]*v[i])/2/a[i];
                l=zhao(d[i]),r=zhao1(k)-1;
                r=min(r,m);
                if(l>r)continue;
                //cout<<l<<" "<<r<<endl;
                f[i].l1=l,f[i].r1=r;
                ans++;
            }
            //cout<<i<<"ok"<<endl;
        }
        sort(f+1,f+1+n,cmp);
        int mmax=0;int cnt=0;
        for(int i=1;i<=n;i++){
            if(f[i].l1>mmax){
                mmax=f[i].r1;
                cnt++;
            }
        }
        //cout<<"163ok"<<endl;
        cout<<ans<<" "<<m-cnt<<endl;
    }
    return 0;
}
