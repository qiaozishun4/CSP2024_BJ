#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int a[N],c[N],aa[N];
string s[30];
int f(int x){
    vector<int> v;
    for(int i=1;i<=x;i++){
      v.push_back(a[i]);
    }
    int k=0;
    while(v.size()!=1){
        vector<int> tmp;
        k++;
        for(int i=0;i<v.size();i++){
            int aa=v[i],bb=c[i+1];
            if(s[k][i/2]=='0'){
                if(aa>k){
                    tmp.push_back(i);
                }
            }else{
                if(bb>k){
                    tmp.push_back(i);
                }
            }
        }
        v=tmp;
    }
    return v[0];
}
void solve(){
    int x[10];
    cin >>x[0]>>x[1]>>x[2]>>x[3];
    for(int i=1;i<=n;i++){
        a[i]=(aa[i]^x[i%4]);
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        ans^=(i*f(c[i]));
    }
    cout <<ans<<endl;
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        cin >>aa[i];
    }
    for(int i=1;i<=m;i++){
        cin >>c[i];
    }
    int x=0;
    while((1<<x)<n){
        x++;
    }
    for(int i=1;i<=x;i++){
        cin >>s[i];
    }
    int t;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}
