#include <bits/stdc++.h>
using namespace std;
int n,m,t,a[100010],b[100010],c[100010],lg,x[10];
char d[30][100010];
set <int> s;
void dfs(vector <int> v,int now){
    if(v.size()==1){
        s.insert(v[0]);
        return ;
    }
    vector <int> g,bqd;
    for(int i=0;i<v.size();i+=2){
        int tt=i/2+1;
        if(d[now][tt]!='*'){
            if(d[now][tt]=='0'){
                if(b[v[i]]>=now) g.push_back(i);
                else g.push_back(i+1);
            }
            else{
                if(b[v[i+1]]>=now) g.push_back(i+1);
                else g.push_back(i);
            }
        }
        else bqd.push_back(i);
    }
    for(int i=0;i<(1 << (bqd.size()));i++){
        int id=0;
        vector <int> bd(int(v.size())/2+10),vt;
        for(int j=0;j<int(v.size())/2;j++){
            bd[j]=-1;
        }
        for(int j=0;j<bqd.size();j++){
            int tt=bqd[j]/2+1;
            if(!(i & (1 << j))){
                if(b[v[bqd[j]]]>=now) bd[tt]=bqd[j];
                else bd[tt]=bqd[j]+1;
            }
            else{
                if(b[v[bqd[j]+1]]>=now) bd[tt]=bqd[j]+1;
                else bd[tt]=bqd[j];
            }
        }
        for(int j=0;j<int(v.size())/2;j++){
            if(bd[j]!=-1) continue;
            bd[j]=g[id++];
        }
        for(int j=0;j<int(v.size())/2;j++){
            vt.push_back(bd[j]);
        }
        dfs(vt,now+1);
    }
    return ;
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    memset(d,'*',sizeof(d));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    for(int i=1;(1 << i)<n;i++){
        lg=i;
    }
    lg++;
    for(int i=1;i<=lg;i++){
        for(int j=1;j<=(1 << (lg-i));j++){
            cin>>d[i][j];
        }
    }
    cin>>t;
    while(t--){
        int xr=0;
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++){
            b[i]=a[i];
            b[i] ^= x[i%4];
        }
        for(int i=1;i<=m;i++){
            if(c[i]==1){
                xr ^= i;
                continue;
            }
            vector <int> v;
            int l;
            for(int j=0;(1 << j)<c[i];j++){
                l=j;
            }
            l++;
            l=(1 << l);
            for(int j=1;j<=l;j++){
                v.push_back(j);
            }
            set <int> tmp;
            swap(s,tmp);
            dfs(v,1);
            int sum=0;
            set <int>::iterator it;
            for(it=s.begin();it!=s.end();it++){
                sum+=(*it);
            }
            xr ^= (i*sum);
        }
        cout<<xr<<"\n";
    }
    return 0;
}
