#include<iostream>
#include<vector>
using namespace std;
vector<int> a[100005];
int n,k,q,c;
bool ans;
void dfs(int f,int now,int pre){
    if(ans==true){
        return;
    }
    if(now==1){
        for(int i=1;i<=n;i++){
            if(i==pre){
                continue;
            }
            int flag=0;
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]==f){
                    for(int k1=j+1;k1<a[i].size();k++){
                        if((k1-j)<k&&a[i][k]==c){
                            ans=true;
                            return;
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i==pre){
            continue;
        }
        int flag=0;
        for(auto x:a[i]){
            flag++;
            if(x==f){
                int flag2=0;
                for(auto x1:a[i]){
                    flag2++;
                    if(flag2<flag){
                        continue;
                    }
                    if(flag2-flag>k){
                        break;
                    }
                    dfs(x1,now-1,i);
                }
            }
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,l,xx,r;
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=1;j<=l;j++){
                cin>>xx;
                a[i].push_back(xx);
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r>>c;
            ans=false;
            dfs(1,r,-1);
            if(ans==true){
                cout<<"1"<<endl;
            }
            else{
                cout<<"0"<<endl;
            }
        }
    }
    return 0;
}
