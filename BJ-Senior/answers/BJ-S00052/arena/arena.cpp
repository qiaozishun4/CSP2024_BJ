#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a1[100005],c[100005],lg[140000],a[100005];
string s[20];
int ans=0,ans1;
void slv(int p){
    int k=0,mul=1;
    while(mul<p)k++,mul<<=1;
    vector<pair<int,int>>v,nw;
    v.clear();
    for(int i=1;i<=p;i++)v.push_back({a[i],i});
    int r=0;
    while(v.size()>1){
        r++;
        nw.clear();
        for(int i=1;2*i<=v.size();i++){
            if(s[r][i]=='0'){
                if(v[i+i-2].first>=r)nw.push_back(v[i+i-2]);
                else nw.push_back(v[i+i-1]);
            }
            else{
                if(v[i+i-1].first>=r)nw.push_back(v[i+i-1]);
                else nw.push_back(v[i+i-2]);
            }
        }
        v.swap(nw);
    }
    ans1=v[0].second;
}
void slv(){
    ans=0;
    for(int i=1;i<=m;i++)slv(c[i]),ans^=i*ans1;
    cout<<ans<<endl;
}
signed main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a1[i];
    for(int j=1;j<=m;j++)cin>>c[j];
    int k=0,mul=1;
    while(mul<n)k++,mul<<=1;
    lg[1]=0;
    for(int i=2;i<=mul;i++)lg[i]=lg[i>>1]+1;
    for(int i=1;i<=k;i++){
        cin>>s[i];
    }
    int T;
    cin>>T;
    while(T--){
        int x[4];
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++)a[i]=(a1[i]^x[i%4]);
        slv();
    }
    fclose(stdin);
    fclose(stdout);
}