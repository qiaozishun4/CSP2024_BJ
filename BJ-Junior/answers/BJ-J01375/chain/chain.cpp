#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> s[100001];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,kk,q,l,x,r,c;
        cin>>n>>kk>>q;
        for(int i=1;i<=n;i++){
            s[i].clear();
        }
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=1;j<=l;j++){
                cin>>x;
                s[i].push_back(x);
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r>>c;
            bool flag=false;
            for(int j=1;j<=n;j++){
                int now = -1;
                for(auto k:s[j]){
                    if(k==1)now=0;
                    if(now!=-1)now++;
                    if(k==c){
                        // cout << now << endl;
                        if(now<=kk&&now!=-1){
                            // cout<<1<<endl;     
                            flag=true;
                        }
                    }
                }
            }
            if(flag==true){
                cout<<1<<endl;
            }
            else cout<<0<<endl;
        }
    }
    return 0;
}