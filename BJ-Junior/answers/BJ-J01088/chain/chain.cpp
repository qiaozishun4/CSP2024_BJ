#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,k,q,t[200010];
vector<int> vec[N];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++) vec[i].clear();
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            vec[i].push_back(x);
            for(int j=1;j<=vec[i][0];j++){
                cin>>x;
                vec[i].push_back(x);
                t[x]++;
            }
            //cout<<vec[i][0]<<endl;
        }
        while(q--){
            int r,c;cin>>r>>c;
            if(r==1){
                bool flag=false;
                for(int i=1;i<=n;i++){
                    //cout<<"lent:"<<vec[i][0]<<endl;
                    int tac1=-1e9,tacc=-1e9;
                    for(int j=1;j<=vec[i][0];j++){
                        if(vec[i][j]==1){
                            tac1=j;
                        }else if(vec[i][j]==c){
                            tacc=j;
                        }
                        if(c==1 && tac1!=-1000000000){
                            flag=true;
                            break;
                        }
                        if(tac1!=-1000000000 && tacc!=-1000000000 && tacc>=tac1 && tacc-tac1+1<=k){
                            flag=true;
                            //cout<<i<<":"<<tac1<<" "<<tacc;
                            break;
                        }
                    }
                    if(flag==true) break;
                }
                cout<<flag<<endl;
            }else{
                if(t[c]!=0) cout<<1<<endl;
                else cout<<0<<endl;
            }
        }
    }
    return 0;
}
