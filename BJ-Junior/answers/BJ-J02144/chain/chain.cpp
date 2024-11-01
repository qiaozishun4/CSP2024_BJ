#include<bits/stdc++.h>

using namespace std;

int temp;
int T,n,k,q,l;
vector<int> S[100005];
int lun,c;

bool dfs(int k,int s,int father){
    if(k==-1){
        return false;
    }
    if(s == 1 && k==0){
        return true;
    }
    bool fal = false;
    for(int i =1;i<=n;i++){
        if(i==father)continue;
        for(int j =0;j<S[i].size();j++){
               // cout<<S[i][j]<<"a";
            if(S[i][j]==s){
                for(int q = j-1;q>j-k&& q>=0;q--){
                        //cout<<S[i][q]<<" ";
                    if( dfs(k-1,S[i][q],i) == true){
                        return true;
                    }
                }
                //cout<<i<<"///////"<<endl;
            }
        }
    }
    return false;
}

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    cin>>T;
    while(T--){
        for(int i =1;i<=n;i++){
            S[i].clear();
        }

        cin>>n>>k>>q;
        for(int i =1;i<=n;i++){
            cin>>l;
            for(int j =1;j<=l;j++){
                cin>>temp;
                S[i].push_back(temp);
            }
        }
        for(int i =1;i<=q;i++){
            cin>>lun>>c;
            cout<<dfs(lun,c,-1)<<endl;
        }
    }


    return 0;
}
