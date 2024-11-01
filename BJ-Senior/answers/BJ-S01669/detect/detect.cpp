#include <bits/stdc++.h>
using namespace std;
long long int n,m,L,ans1,ans2;
long double V;
vector<int> d,v,a;
vector<int> mi,cnt;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    long long t;
    cin>>t;
    while(t--){
        d.clear();
        v.clear();
        a.clear();
        cnt.clear();
        mi.clear();
        ans1=0,ans2=0;
        cin>>n>>m>>L>>V;
        d.resize(n,0);
        v.resize(n,0);
        a.resize(n,0);
        cnt.resize(L+1,0);
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        mi.resize(m,0);
        for(int i=0;i<m;i++){
            cin>>mi[i];
            cnt[mi[i]]++;
        }
        for(int i=L-1;i>=0;i--){
            cnt[i]+=cnt[i+1];
        }
        for(int i=0;i<n;i++){
            if(a[i]==0&&v[i]>V&&cnt[d[i]]>=1){
                ans1++;
            }
        }
        if(ans1==0){
            ans2=m;
        }else{
            ans2=m-1;
        }
        cout<<ans1<<' '<<ans2<<'\n';
    }

    return 0;
}