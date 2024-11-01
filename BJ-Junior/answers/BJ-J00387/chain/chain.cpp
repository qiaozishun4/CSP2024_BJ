#include<bits/stdc++.h>
using namespace std;
int n,k,q;
bool flag;
int player[1010][2020];
int le[1010];
int st,fn;
void dfs(int x,int r,int no){
    if(r==st&&x==fn){
        flag=true;
        return;
    }
    if(r==st&&x!=fn){
        return;
    }
    for(int i=1;i<=n&&flag==false;i++){
        if(no!=i){
        for(int j=1;j<=le[i]&&flag==false;j++){
            if(player[i][j]==x){
                for(int kk=j+1;(kk-j)<k&&kk<=le[i]&&flag==false;kk++){
                    dfs(player[i][kk],r+1,i);
                }
            }
        }
        }
    }

}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        int len;
        cin>>len;
        le[i]=len;
        for(int j=1;j<=len;j++){
            cin>>player[i][j];
        }
    }
    while(q--){
        cin>>st>>fn;
        flag=false;
        dfs(1,0,0);
        if(flag==true){
            cout<<"1"<<endl;
        }else{
            cout<<"0"<<endl;
        }
    }
    }
}
