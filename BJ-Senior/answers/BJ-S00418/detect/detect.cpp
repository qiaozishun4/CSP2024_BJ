#include<bits/stdc++.h>
using namespace std;
int t,n,m,L,V,d[100005],v[100005],a[100005],p[100005];
namespace BF{
    struct Node{
        int l,r,id;
        Node(int l,int r,int id):l(l),r(r),id(id){}
    };
    int s[100005],f[25][2000005];
    vector<Node> vec;
    bool cmp(Node x,Node y){
        if(x.r!=y.r) return x.r<y.r;
        return x.l<y.l;
    }
    int tr[1000005];
    int lowbit(int x){
        return x&(-x);
    }
    void add(int x,int a){
        for(;x<=L+1;x+=lowbit(x)) tr[x]+=a;
    }
    int sum(int x){
        int s=0;
        for(;x;x-=lowbit(x)) s+=tr[x];
        return s;
    }
    void check(Node nd){
        // printf("%d [%d,%d]\n",nd.id,nd.l,nd.r);
        if(sum(nd.r+1)-sum(nd.l)>0){
            vec.push_back(nd);
        }
    }
    void main(){
        vec.clear();
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        }
        for(int i=1;i<=L+1;i++) tr[i]=0;
        for(int i=1;i<=m;i++) scanf("%d",&p[i]),add(p[i]+1,1);
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(v[i]>V) check(Node(d[i],L,i));
            }
            else if(a[i]>0){
                int x=(V*V-v[i]*v[i])/(2*a[i])+1;
                if(d[i]+x<=L) check(Node(max(d[i]+x,d[i]),L,i));
            }
            else{
                if(v[i]>V){
                    a[i]*=-1;
                    int x=(v[i]*v[i]-V*V+2*a[i]-1)/(2*a[i])-1;
                    check(Node(d[i],min(d[i]+x,L),i));
                }
            }
        }
        sort(vec.begin(),vec.end(),cmp);
        for(int i=1;i<=L+1;i++) tr[i]=0;
        int ans2=0;
        for(int i=0,j=0;i<vec.size();i++){
            if(sum(vec[i].r+1)-sum(vec[i].l)>0) continue;
            while(j<=m&&p[j]<=vec[i].r) j++;
            j--;
            // printf("%d\n",j);
            ans2++;
            add(p[j]+1,1);
        }
        printf("%d %d\n",(int)vec.size(),m-ans2);
    }
}
int main(){
    #ifndef JZQ
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    #endif
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&m,&L,&V);
        BF::main();
        // vector<pair<int,int>> vec;
        // for(int i=1;i<=n;i++){
        //     scanf("%d%d%d",&d[i],&v[i],&a[i]);
        //     if(v[i]>V) vec.push_back({i,d[i]});
        //     else if(a[i]>0){
        //         int x=(V*V-v[i]*v[i])/(2*a[i])+1;
        //         if(d[i]+x<=L) vec.push_back({i,d[i]+x});
        //     }
        // }
        // int mxp=0;
        // for(int i=1;i<=m;i++){
        //     scanf("%d",&p[i]);
        //     mxp=max(mxp,p[i]);
        // }
        // int ans=0;
        // for(auto pr:vec) if(pr.second<=mxp) ans++;
        // printf("%d ",ans);
        // if(ans) printf("%d\n",m-1);
        // else printf("%d\n",m);
    }
    return 0;
}