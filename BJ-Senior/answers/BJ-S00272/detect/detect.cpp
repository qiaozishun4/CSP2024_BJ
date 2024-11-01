#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int T,n,m,L,V,num[3005];

struct Node {
    int d,v,a;
}c[N];

int p[N];

int lower(int l,int r,int x) {
    if(l==r) return l;
    if(r==l+1) {
        if(r<=x) return r;
        return l;
    }
    int mid=(l+r)>>1;
    if(p[mid]==x) return mid;
    if(p[mid]<x) return lower(mid,r,x);
    return lower(l,mid-1,x);
}


int upper(int l,int r,int x) {
    if(l==r) return l;
    if(r==l+1) {
        if(l>x) return l;
        return r;
    }
    int mid=(l+r)>>1;
    if(p[mid]>x) return upper(l,mid,x);
    return upper(mid+1,r,x);
}

int main() {
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>T;
    while(T--) {
        int cnt=0,cnt1=0;
        cin>>n>>m>>L>>V;
        //cout<<1<<endl;
        for(int i=1;i<=n;i++) {
            int d,v,a;
            cin>>d>>v>>a;
            c[i]={d,v,a};
        }
        //cout<<2<<endl;
        for(int i=1;i<=m;i++) {
            cin>>p[i];
        }
        //cout<<3<<endl;
        for(int i=1;i<=n;i++) {
            int d=c[i].d,v=c[i].v,a=c[i].a;
            if(a==0) {
                //cout<<"a=0"<<endl;
                if(v>V && d<=p[m]) {
                    cnt1++;
                    //cout<<i<<" ";
                }
            } else if(a>0) {
                if(d>p[m]) continue;
                if(v>V) {
                    cnt1++;
                    continue;
                }
                double pp=d*1.0+(1.0*(V*V-v*v)/(2.0*a));
                if(pp<p[m]) cnt1++;
            } else {
                //cout<<"a<0"<<endl;
                if(d>p[m] || v<V) continue;
                double poi=d*1.0+1.0*(V*V-v*v)/(2.0*a);
                //cout<<d<<"d poi "<<poi<<endl;
                //cout<<"bbbb"<<endl;
                int low=lower(1,m,d);
                //cout<<"dddd"<<endl;
                int up=upper(1,m,poi);
                //cout<<"cccc"<<endl;
                //cout<<"up:"<<up<<" low:"<<low<<endl;
                if(up-low>=2) {
                    cnt++;
                    for(int j=low+1;j<=up-1;j++) {
                        num[j]++;
                    }
                    //cout<<i<<" ";
                }
            }
        }
        cout<<cnt+cnt1<<" ";
        if(!cnt && cnt1) {cout<<m-1<<"\n"; continue;}
        if(!cnt && !cnt1) {cout<<m<<"\n"; continue;}
        if(cnt && cnt1) {
            if(num[m]==cnt) {cout<<m-1<<"\n"; continue;}
        }
        bool flag=false;
        for(int j=1;j<=m;j++) {
            if(num[j]==cnt) {
                flag=true;
                break;
            }
        }
        if(flag) cout<<m-2<<"\n";
        else cout<<m-3<<"\n";
    }
    return 0;
}//please!!