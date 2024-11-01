#include<bits/stdc++.h>
using namespace std;
int t,n,k,q;
vector<int> a[100005];
struct s{
    int r;
    int c;
    int p;
};
bool bfs(int r,int c){
    queue<s> q;
    q.push({0,1,0});
    while(!q.empty()){
        s sss=q.front();
        q.pop();
        if(sss.r<r){
            for(int i=1;i<=n;i++){
                if(i!=sss.p){
                    for(int j=0;j<a[i].size();j++){
                        if(a[i][j]==sss.c){
                            for(int l=1;l<k;l++){
                                if(j+l>=a[i].size())break;
                                if(a[i][j+l]==c&&sss.r==r-1)return true;
                                q.push({sss.r+1,a[i][j+l],i});
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            a[i].clear();
            int l;
            cin>>l;
            for(int j=1;j<=l;j++){
                int x;
                cin>>x;
                a[i].push_back(x);
            }
        }
        for(int i=1;i<=q;i++){
            int r,c;
            cin>>r>>c;
            if(bfs(r,c)){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

