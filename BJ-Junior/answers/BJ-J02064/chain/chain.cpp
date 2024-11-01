#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;
vector<int> p[100010];
struct node{
    int endsyn,time;
}mis[100010];
int count_[100010];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    while(t--){
        int n,k,q;
        cin>>n>>k>>q;
        for(int j = 1; j <= n; j++){
            int l;
            cin>>l;
            for(int i = 1; i <= l; i++){
                int x;
                cin>>x;
                p[j].push_back(x);
                count_[x]++;
            }
        }
        for(int i = 1; i <= q; i++){
            int x,y;
            cin>>x>>y;
            mis[i].endsyn = x;
            mis[i].time = y;
        }
        for(int i = 1; i <= q; i++){
            if(count_[mis[i].endsyn] == 0){
                cout<<"0"<<endl;
            }
        }
        //不会了...
    }

    return 0;
}



//t4好难 QAQ

