#include<iostream>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
#define int long long
const int maxn=1e5+10,inf=1e17,minf=0.0001;
int T;
int n,m,l,v,p[maxn],ans1,flag;
multiset<pair<int,int>>st;
struct C{
    int d,v,a,st,ed;
}c[maxn];
struct NODE{
    int l,r,mx,tag,id;
}t[maxn<<2];
void pushdown(int p){
    t[p*2].mx+=t[p].tag;
    t[p*2+1].mx+=t[p].tag;
    t[p*2].tag+=t[p].tag;
    t[p*2+1].tag+=t[p].tag;
    t[p].tag=0;
}
void build(int p,int l,int r){
    t[p]={l,r};
    if(l==r){
        t[p].id=l;
        return;
    }
    int mid=l+r>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
}
void add(int p,int l,int r,int v){
    if(l<=t[p].l&&t[p].r<=r){
        t[p].mx+=v;
        t[p].tag+=v;
        return;
    }
    pushdown(p);
    int mid=t[p].l+t[p].r>>1;
    if(l<=mid)add(p*2,l,r,v);
    if(r>mid)add(p*2+1,l,r,v);
    t[p].mx=max(t[p*2].mx,t[p*2+1].mx);
    if(t[p*2].mx>=t[p*2+1].mx)t[p].id=t[p*2].id;
    else t[p].id=t[p*2+1].id;
}
NODE ask(int p,int l,int r){
    if(l<=t[p].l&&t[p].r<=r){
        return t[p];
    }
    pushdown(p);
    int mid=t[p].l+t[p].r>>1;
    NODE ans1={0,0,0,0,0},ans2={0,0,0,0,0},ans;
    if(l<=mid)ans1=ask(p*2,l,r);
    if(r>mid)ans2=ask(p*2+1,l,r);
    ans.mx=max(ans1.mx,ans2.mx);
    if(ans1.mx>=ans2.mx)ans.id=ans1.id;
    else ans.id=ans2.id;
    return ans;
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        st.clear();
        ans1=0;
        flag=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
            if(c[i].a<0)flag=1;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        p[m+1]=maxn;
        // sort(p+1,p+m+1);
        for(int i=1;i<=n;i++){
            int l=0,r=m+1,oo=0;
            while(l<=r){
                int mid=l+r>>1;
                if(p[mid]<c[i].d)l=mid+1;
                else r=mid-1,oo=mid;
            }
            if(c[i].a==0){
                if(c[i].v>v)c[i].st=oo,c[i].ed=m;
                else c[i].st=oo,c[i].ed=oo-1;
            }
            if(c[i].a>0){
                long long l=oo-1,r=m,ans=m;
                while(l<=r){
                    int mid=l+r>>1;
                    if(p[mid]<c[i].d){
                        l=mid+1;continue;}
                    double v1=sqrt(c[i].v*c[i].v+2*c[i].a*(p[mid]-c[i].d));
                    if(v1<v&&v-v1>minf)l=mid+1;
                    else if(v1>v&&v1-v>minf)r=mid-1,ans=mid;
                    else r=mid-1;
                }
                c[i].st=ans,c[i].ed=m;
            }
            else if(c[i].a<0){
                int l=oo-1,r=m,ans=oo-1,o=1;
                while(l<=r){
                    int mid=l+r>>1;
                    if(p[mid]<c[i].d){
                        l=mid+1,ans=mid,o=mid;continue;
                    }
                    double v1=sqrt(c[i].v*c[i].v+2*c[i].a*(p[mid]-c[i].d));
                    if(v1<v&&v-v1>minf)r=mid-1;
                    else if(v1>v&&v1-v>minf)l=mid+1,ans=mid;
                    else l=mid+1;
                }
                if(sqrt(c[i].v*c[i].v+2*c[i].a*(p[ans]-c[i].d))<v)ans--;
                c[i].ed=ans,c[i].st=oo;
                if(c[i].v<=v)c[i].st=inf;
            }
            if(c[i].st<=c[i].ed){
                ans1++;
                st.insert({c[i].st,c[i].ed});
            }
                // cout<<i<<" "<<c[i].st<<' '<<c[i].ed<<'\n';
        }
        build(1,1,m);
        cout<<ans1<<' ';
        if(flag==0){
            cout<<m-1<<'\n';
            continue;
        }
        // return 0;
        for(auto o:st){
            add(1,o.first,o.second,1);
        }
        st.insert({-inf,-inf});
        st.insert({inf,inf});
        int ans2=0;
        while(st.size()>2){
            ans2++;
            auto mx=ask(1,1,m);
            int ik=mx.id;
            auto itr=--st.upper_bound({mx.id,inf});
            if(itr==st.begin())break;
            while(1){
                if(itr==st.begin())break;
                if((*itr).second>=mx.id){
                    auto uuu=itr;
                    if(itr==st.begin())break;
                    add(1,(*itr).first,(*itr).second,-1);
                    itr--;
                    st.erase(uuu);
                }
                else itr--;
                // cout<<(*itr).first<<' '<<(*itr).second<<'\n';
                if((*itr).first<=-1e10)break;
            }
            // cout<<st.size()<<'\n';
        }
        cout<<m-ans2<<'\n';
    }
}