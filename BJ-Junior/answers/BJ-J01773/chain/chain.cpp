#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l[2010],s[1010][2010],stid[1010],edid[1010];
vector<int> pos[200010],g[200010];
set<int> st[110],lst[200010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=0;i<=200005;i++){
            pos[i].clear();
            g[i].clear();
            lst[i].clear();
        }
        int id=0;
        for(int i=0;i<=105;i++){
            st[i].clear();
        }
        for(int i=1;i<=n;i++){
            cin>>l[i];
            stid[i]=id+1;
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
                ++id;
                pos[s[i][j]].push_back(id);
                if(s[i][j]==1)  st[0].insert(id);
            }
            edid[i]=id;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=l[i];j++){
                vector<int> v;
                for(int p=j+1;p<=min(l[i],j+k-1);p++){
                    lst[s[i][p]].insert(stid[i]+j-1);
                    v.push_back(s[i][p]);
                }
                sort(v.begin(),v.end());
                for(int p=0;p<(int)v.size();p++){
                    if(p==0||v[p]!=v[p-1]){
                        for(int toid:pos[v[p]]){
                            if(toid<stid[i]||toid>edid[i]){
                                g[stid[i]+j-1].push_back(toid);
                                //cout<<stid[i]+j-1<<" -> "<<toid<<endl;
                            }
                        }
                    }
                }
            }
        }
        //cout<<"OK A "<<T<<endl;
        for(int i=1;i<=9;i++){
            for(int lstid:st[i-1]){
                for(int toid:g[lstid]){
                    st[i].insert(toid);
                    //if(i>10)    continue;
                    //cout<<i<<" <-[id]- "<<toid<<endl;
                    //cout<<i<<" <-[num]- "<<num[toid]<<endl;
                }
            }
            //cout<<(int)st[i].size()<<"-"<<ans[i].size()<<endl;
        }
        //cout<<"OK B "<<T<<endl;
        int r,c;
        for(int qc=1;qc<=q;qc++){
            cin>>r>>c;
            //cout<<qc<<" "<<r<<" "<<c<<endl;
            int ok=0;
            for(int lsid:lst[c]){
                if(st[r-1].count(lsid)){
                    ok=1;
                    break;
                }
            }
            cout<<ok<<endl;
        }
    }
    return 0;
}
