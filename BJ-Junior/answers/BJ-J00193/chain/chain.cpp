#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,ll,rr,cc,ss;
vector<int> l,r,c;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        vector<int>s[n+1];
        for(int i=1;i<=n;i++){
            cin>>ll;
            l.push_back(ll);
            for(int j=1;j<=l[i-1];j++){
                cin>>ss;
                s[i].push_back(ss);
        }}for(int i=1;i<=q;i++){
            cin>>rr>>cc;
            r.push_back(rr);
            c.push_back(cc);
        }for(int i=1;i<=q;i++){
            if(r[i]==1){
                bool flag=1;
                for(int j=1;j<=n;j++){
                    if(find(s[j].begin(),s[j].end(),1)<find(s[j].begin(),s[j].end(),c[i])&&find(s[j].begin(),s[j].end(),c[i])!=s[j].end()){
                        cout<<"1\n";
                        flag=0;
                        break;
                }}if(flag)cout<<"0\n";
            }else{
                bool f=1;
                for(int j=1;j<=n;j++){
                        if(find(s[j].begin(),s[j].end(),c[i])!=s[j].end()){
                            f=0;
                            break;
                }}if(f)cout<<"0\n";
                else cout<<"1\n";
    }}}return 0;
}
