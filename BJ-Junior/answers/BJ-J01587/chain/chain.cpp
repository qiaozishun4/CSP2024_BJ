#include<bits/stdc++.h>
using namespace std;
int hn[2001],ans[11][200005],a[1001][2001],flag[200005];

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;cin>>T;
    for(int o=1;o<=T;o++){
        int n,k,qq;cin>>n>>k>>qq;
        for(int i=1;i<=n;i++){
            int l;
            cin>>l;
            hn[i]=l;
            for(int j=1;j<=l;j++){
                cin>>a[i][j];
            }
        }
        queue<int> q;
        q.push(1);
        for(int i=1;i<=10;i++){
            while(!q.empty()){
                int cur=q.front();q.pop();
                for(int k=1;k<=n;k++){
                    int pos=0;
                    for(int z=1;z<=hn[i];z++){
                        if(a[k][z]==cur)pos=z;
                        if(z<pos+k)flag[a[k][z]]=1;
                    }
                }
            }
            for(int j=1;j<=200005;j++){
                if(flag[j]){
                        q.push(j);
                        ans[i][j]=1;
                }
            }
        }
        for(int i=1;i<=qq;i++){
            int qw,qwq;cin>>qw>>qwq;
            cout<<ans[qw][qwq]<<endl;
        }
    }
    return 0;
}