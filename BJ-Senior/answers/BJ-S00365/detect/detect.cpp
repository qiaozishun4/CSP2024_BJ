#include<bits/stdc++.h>
#define db double 
#define ldb long double
using namespace std;
const int N=1e5+10;
int n,m,L,V;int tp=0;
struct Q{
    int l,r;
    bool operator<(const Q &b) const{
        if(l==b.l) return r>b.r;
        else return l<b.l;
    }
};
Q mk(int a,int b){
    return (Q){a,b};
}
Q qu[N],qu2[N];
int divc(int a,int b){
    if(a==0) return 0;
    int f=(a/abs(a))*(b/abs(b));
    int t=(abs(a)+abs(b)-1)/abs(b);
    if(f<0) t=abs(a)/abs(b);
    return f*t;
}int divf(int a,int b){
    if(a==0) return 0;
    int f=(a/abs(a))*(b/abs(b));
    int t=abs(a)/abs(b);
    if(f<0) t=(abs(a)+abs(b)-1)/abs(b);
    return t*f;
}int ps[N];
Q st[N];int top=0;
void slv(){
    cin>>n>>m>>L>>V;
    tp=0;
    for(int i=1;i<=n;i++){
        int d,v,a;cin>>d>>v>>a;
        if(a==0){
            if(v>V) qu[++tp]=mk(d,L);
        }else if(a>0){
            int s=divf(V*V-v*v,2*a)+1;
            //if(i<=10) cout<<s<<endl;
            int lt=max(d,d+s);
            if(lt<=L) qu[++tp]=mk(lt,L);
        }else{
            int s=divc(V*V-v*v,2*a)-1;
            int rt=min(d+s,L);
            if(rt>=d) qu[++tp]=mk(d,rt);
        }
    }sort(qu+1,qu+tp+1);
    for(int i=1;i<=m;i++) cin>>ps[i];
    //stack<Q> s;while(!s.empty()) s.pop();
    top=0;
    int it=1;int ans=0;int tp2=0;
    for(int i=1;i<=tp;i++){
        //cout<<qu[i].l<<' '<<qu[i].r<<endl;
        while(it<=m&&ps[it]<qu[i].l) it++;
        if(it<=m&&ps[it]<=qu[i].r) ans++,qu[++tp2]=qu[i]; 
    }tp=tp2;cout<<ans<<' ';ans=0;
    for(int i=1;i<=tp;i++){
        while(top>0){
            if(st[top].r>=qu[i].r) top--;
            else break;
        }st[++top]=qu[i];
    }tp=0;int sz=top;tp=sz;
    for(int i=sz;i>=1;i--){
        qu[i]=st[i];
    }it=0;int to=0;
    for(int i=1;i<=tp;i++){
        if(to<qu[i].l){
            ans++;
            while(it<m&&ps[it+1]<=qu[i].r) it++;
            to=ps[it];
        }
    }cout<<m-ans<<endl;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;cin>>t;while(t--) slv();
    fclose(stdin);fclose(stdout);
}