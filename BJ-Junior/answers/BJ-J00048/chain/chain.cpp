#include<bits/stdc++.h>
using namespace std;
bool dfs(int di,int lastp,int lastw,int needw,int manyp,int maxl,int nowl,vector<vector<int>> lj){
    if(nowl>maxl)   return false;
    if(di==0){
        if(lastw==needw){
            return true;
        }
        else{
            return false;
        }
    }
    for(int i=1;i<=manyp;i++){
        if(lj[lastw][i]!=0){
            if(dfs(di-(lj[lastw][i]!=lastp&&lastp!=0),lj[lastw][i],i,needw,manyp,maxl,nowl+1,lj)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for(int iii=0;iii<t;iii++){
        vector<vector<int>> lj(20005,vector<int>(20005,0));
        for(int i=1;i<=20005;++i){
            lj[0][i]=-1;
        }
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int l,last;
            cin>>l;
            for(int j=1;j<=l;j++){
                int word;
                cin>>word;
                if(j==1)    last=word;
                else{
                    lj[word][last]=i;
                    last=word;
                }
            }
        }
        for(int i=1;i<=q;i++){
            int r,c;
            cin>>r>>c;
            cout<<dfs(r,0,0,c,n,k,0,lj);
            if(i<q) cout<<'\n';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
