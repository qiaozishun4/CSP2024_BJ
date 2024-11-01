#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,r,c;
vector<int>s[1005];
bool f[200005];
void init(){
    for(int i=1;i<=n;i++){
        s[i].clear();
    }
    memset(f,false,sizeof(f));
}
int sov1(){
    for(int i=1;i<=n;i++){
        for(int j=0;j<s[i].size();j++){
            if(s[i][j]!=1){
                continue;
            }
            int h=-1;
            for(int p=j+1;p<=j+k-1;p++){
                if(s[i][p]==c){
                    return 1;
                }
                if(s[i][p]==1){
                    h=max(h,p-1);
                }
            }
            if(h==-1){
                h=j+k-1;
            }
            j=max(j,h);
        }
    }
    return 0;
}

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        init();
        for(int i=1;i<=n;i++){
            int l;
            cin>>l;
            while(l--){
                int num;
                cin>>num;
                s[i].push_back(num);
                f[num]==true;
            }
        }
        while(q--){
            cin>>r>>c;
            if(r==1){
                cout<<sov1()<<endl;
            }else if(f[c]=false){
                cout<<0<<endl;
            }else{
                cout<<1<<endl;
            }
        }
    }
}

