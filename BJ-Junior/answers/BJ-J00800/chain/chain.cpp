#include<bits/stdc++.h>
using namespace std;
int n,k,q;
int s[10010][20020];
int l[10010];
struct node{
    int val,pl;
};
vector<node>e[20010];
queue<node>que;
bool ans[20010][20010];
int dis[20010];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            cin>>l[i];
            for(int j=0;j<l[i];j++)cin>>s[i][j];
            for(int x=0;x<l[i];x++){
                for(int a=1;a<k;a++)e[s[i][x]].push_back({s[i][x+a],i});
            }
        }
        que.push({1,-1});
        int d=0;
        while(que.size()){
            auto x=que.front();
            que.pop();
            if(dis[x.val]>11)break;
            for(int y=0;y<=e[x.val].size();y++){
                if(e[x.val][y].pl!=x.pl && dis[x.val]+1<11){
                    que.push(e[x.val][y]);
                    dis[e[x.val][y].val]=dis[x.val]+1;
                    ans[e[x.val][y].val][dis[x.val]+1]=true;
                }
            }
        }
        for(int i=0;i<q;i++){
            int r,c;
            cin>>r>>c;
            if(ans[c][r])cout<<1<<'\n';
            else cout<<0<<'\n';
        }

    }
    return 0;
}
