#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,r,c,l[1010],s[1010][2010];
bool flag;
vector<int>mp[200010];
void dfs(int lst,int peo,int ct){
    if(ct==0){
        //cout<<lst<<" "<<peo<<endl;
        mp[lst].push_back(peo);
        //for(auto x:mp[lst]){
        //    cout<<x<<" ";
        //}cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(n==peo)continue;
        for(int j=1;j<=l[i];j++){
            if(s[i][j]==lst){
                for(int h=j+1;h<=l[i]&&h-j+1<=k;h++){
                    dfs(s[i][h],i,ct-1);
                }
            }
        }
    }
}
void dfs1(int lst,int peo,int ct){
    if(ct==0){
        //cout<<lst<<" "<<peo<<" "<<endl;
        for(auto x:mp[lst]){
            cout<<x<<endl;
            if(x!=peo){flag=1;break;}
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(i==peo)continue;
        for(int j=1;j<=l[i];j++){
            if(s[i][j]==lst){
                for(int h=j-1;h>=1&&j-h+1<=k;h--){
                    dfs(s[i][h],i,ct-1);
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
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
            }
        }
        while(q--){
            flag=0;
            cin>>r>>c;
            if(r==1){
                //cout<<q<<" "<<r<<" "<<c<<endl;
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=l[i];j++){
                        if(s[i][j]==1){
                            for(int h=j+1;h<=l[i]&&h-j+1<=k;h++){
                                //cout<<i<<" "<<h<<endl;
                                if(s[i][h]==c)flag=1;
                            }
                        }
                    }
                }
            }
            else{
                dfs(1,0,r/2);
                //cout<<"!"<<endl;
                dfs1(c,0,r/2);
            }
            cout<<flag<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
