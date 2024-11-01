#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t;
int n,k,q;
vector<int> l[N];
struct node{
    int r,c;
}a[205];
int f[10][200005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        int idx=0;
        for(int i=1;i<=n;i++){
            int kkk;
            //cout<<"1k"<<" "<<i<<endl;
            cin>>kkk;
            for(int j=1;j<=kkk;j++){
                //cout<<"2k"<<" "<<j<<endl;
                int x;
                cin>>x;
                l[i].push_back(x);
            }
        }
        int maxr=0;
        for(int i=1;i<=q;i++){
            int r,c;
            //cout<<i<<endl;
            cin>>a[i].r>>a[i].c;
            maxr=max(a[i].r,maxr);
        }
        if(maxr==1){
            for(int i=1;i<=n;i++){
                for(int j=0;j<l[i].size();i++){
                    if(l[i][j]==1){
                        for(int p=j+1;p<=j+k-1;p++){
                            f[1][l[i][p]]=1;
                        }
                    }
                }
            }
            for(int i=1;i<=q;i++){
                cout<<f[1][a[i].c]<<endl;
            }
        }
        else cout<<1<<endl;
    }
    return 0;
}