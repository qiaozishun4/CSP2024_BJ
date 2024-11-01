#include <bits/stdc++.h>
using namespace std;
vector<int> go[100005];
map<int,bool>cnt[100005][105],ans[105];
int n,k,q,t;
void DFS(int last,int nowi,int dep){
    if(dep>102)return;
    for(int i=0;i<n;i++){
        if(i==last)continue;
        for(int j=0;j<go[i].size();j++){
            if(go[i][j]==nowi){
                for(int l=j+1;l<go[i].size()&&l<j+k;l++){
                    if(cnt[i][dep][go[i][l]])continue;
                    DFS(i,l,dep+1);
                    cnt[i][dep][go[i][l]]=true;
                    ans[dep][go[i][l]]=true;
                }
            }
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        for(int i=0;i<100005;i++){
            go[i].clear();
            for(int j=0;j<105;j++){
                cnt[i][j].clear();
            }
        }
        for(int i=0;i<105;i++){
            ans[i].clear();
        }
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            int m;
            cin>>m;
            for(int j=0;j<m;j++){
                int l;
                cin>>l;
                go[i].push_back(l);
            }
        }
        DFS(-1,1,1);
        int r,c;
        for(int i=0;i<q;i++){
            cin>>r>>c;
            /*
            cout<<"Q:"<<r<<" "<<c<<endl;
            for(auto t:ans[r]){
                cout<<t.first<<endl;
            }
            cout<<endl;
            */
            if(!ans[r][c]){
                cout<<0<<endl;
            }else{
                cout<<1<<endl;
            }
            
        }
    }
    return 0;
}