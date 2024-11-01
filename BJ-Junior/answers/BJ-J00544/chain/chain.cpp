#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n,k,q,qu[100005][2],b[100005];
vector<int> v[100005];
//void make_graphe(){
//    if(find(v[0].begin(),v[0].end(),1)==v[0].end){
//        return;
//    }
//    int e=0;
//    queue<vector<int> > q,qt;
//    q.push(v[0]);
//    while(!q.empty()){
//        while(find(v[0].begin()+e,v[0].end(),1)!=v[0].end){
//            int x=find(v[0].begin()+e,v[0].end(),1);
//            vector<int> u;
//            for()
//        }
//    }
//}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            for(int j=0;j<x;j++){
                int u;
                cin>>u;
                v[i].push_back(u);
            }
        }
        for(int i=0;i<v[0].size();i++){
            if(b[v[0][i]]==0){
                b[v[0][i]]=i+1;
            }
            //cout<<b[v[0][i]]<<" "<<i+1<<endl;
        }
        for(int i=0;i<q;i++){
            int q1,q2;
            cin>>q1>>q2;
            //cout<<q1<<" "<<q2<<endl;
            if(q1==1){
                if(b[q2]==0){
                    cout<<0;
                }
                else if(b[q2]<=k){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
                cout<<endl;
            }
        }
  //      make_graphe();
    }
}
