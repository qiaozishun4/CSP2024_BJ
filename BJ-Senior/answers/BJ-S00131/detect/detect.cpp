#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pii pair<int,int>
#define p1(x) x.first
#define p2(x) x.second
#define int long long 
int n,m,L,V;
int s[2000300];
int p[100930];
int l[109000],r[109300];
int v[100930],a[109300];
inline bool chk(int l,int r){
    // return 1;
    // if(r>=1e6||l<0||l>r){
    //     cout<<l<<" "<<r<<endl;
    //     cout.flush();
    //     exit(0);
    // }
    int p=s[r];
    if(l)p-=s[l-1];
    return p!=0;
}
inline bool cmp(pii A,pii B){return p2(A)<p2(B);}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>L>>V;
        vector<pii>T;
        for(int i=1;i<=n;i++)
            cin>>l[i]>>v[i]>>a[i];
        memset(s,0,sizeof(s));
        set<int>S;
        for(int i=1;i<=m;i++)
            cin>>p[i],s[p[i]]++,S.insert(p[i]); 
            // cout<<L<<endl;
            // cout.flush();
        // continue;
        for(int i=1;i<=L;i++)s[i]+=s[i-1];
        for(int i=1;i<=n;i++){
            if(v[i]<=V&&a[i]<=0)continue;
            if(v[i]>V&&a[i]>=0)
                r[i]=L;
            else{
                int p=V*V-v[i]*v[i],q=2*a[i];
                if(p<0)p=-p,q=-q;
                r[i]=l[i]+p/q;
                if(a[i]>0){
                    // cout<<calc(r[i]-l[i],v[i],a[i])<<endl;
                    l[i]=r[i]+1,r[i]=L;}
                else {
                    // cout<<calc(r[i]-l[i],v[i],a[i])<<endl;
                    
                    if(p%q==0)r[i]--;}
            }
            r[i]=min(r[i],L);
                // cout<<l[i]<<"x"<<r[i]<<"x"<<chk(l[i],r[i])<<endl;
            if(l[i]<=r[i]&&chk(l[i],r[i]))T.push_back({l[i],r[i]});
        }   
        // continue;
        // cout<<endl;
        cout<<T.size()<<" ";
        sort(T.begin(),T.end(),cmp);
        int lst=-1;
        int ct=0;
        for(pii e:T){
            // cout<<p1(e)<<" "<<p2(e)<<endl;
            if(lst<p1(e)){
                ct++;
                auto it=S.upper_bound(p2(e));
                it--;
                lst=*it;
                // cout<<lst<<"x"<<p2(e)<<endl;
            }
        }
        cout<<m-ct<<endl;
    }

    cout.flush();
    fflush(stdout);
    fclose(stdout);
    return 0;
}