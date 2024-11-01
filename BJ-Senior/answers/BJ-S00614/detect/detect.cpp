#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct car {
    int d,v,a;
}c[N];
struct node{
    int l,r;
}csqj[N];
int csy[N];
inline bool cmp (const node &a,const node &b) {
    if (a.l!=b.l) return a.l<b.l;
    return a.r<b.r;
}
inline bool cmp2 (const node &a,const node &b) {
    if (a.r!=b.r) return a.r<b.r;
    return a.l<b.l;
}
inline bool operator == (const node &a,const node &b) {
    return (a.l==b.l && a.r==b.r);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        for (int i=1;i<=n;i++) {
            int d,v,a;
            cin>>d>>v>>a;
            c[i]=(car){d,v,a};
        }
        for (int i=1;i<=m;i++) {
            cin>>csy[i];
        }
        sort(csy+1,csy+1+m);
        for (int i=1;i<=n;i++) {
            int d=c[i].d,v=c[i].v,a=c[i].a;
            if (a>=0 && v>V) {
                csqj[i]=(node){d,L};
            }
            else if (a>0 && v<=V) {
                int x=(V*V-v*v)/(a*2)+1;
                csqj[i]=(node){d+x,L};
            }
            else if (a<0 && v>V) {
                int x=(V*V-v*v)/(a*2)-((V*V-v*v)%(a*2)==0);
                csqj[i]=(node){d,d+x};
            }
            else {
                csqj[i]=(node){-1,-1};
            }
        }
        sort(csqj+1,csqj+1+n,cmp);

        //for (int i=1;i<=n;i++) cout<<csqj[i].l<<' '<<csqj[i].r<<'\n';

        int cnt=0,ans=0;
        for (int i=1,j=1;i<=n;i++) {
            if (csqj[i]==(node){-1,-1}) continue;
            while (j<=m && csy[j]<csqj[i].l) j++;
            if (j>m) break;
            if (csy[j]<=csqj[i].r) cnt++;
            else csqj[i]=node{-1,-1};
        }
        sort(csqj+1,csqj+1+n,cmp2);
        for (int i=1,j=1;i<=n;) {
            if (csqj[i]==(node){-1,-1}) {
                i++;
                continue;
            }
            while (j<m && (csy[j]>csqj[i].r || csy[j]<csqj[i].l || (csy[j+1]>=csqj[i].l && csy[j+1]<=csqj[i].r))) j++;
            if (j>m) break;
            ans++;
            while (csqj[i]==(node){-1,-1} || (i<=n && csqj[i].l<=csy[j] && csqj[i].r>=csy[j])) i++;
            j++;
        }
        cout<<cnt<<' '<<m-ans<<'\n';
    }
    return 0;
}
