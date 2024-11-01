#include<bits/stdc++.h>
using namespace std;
long long t,n,k,q,l[200001],li,bo[200001],r,c;
int a[11][200001];
bool b[11][200001];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>li;
            for(int i=1;i<=li;i++){
                cin>>l[i];
            }
            for(int i=1;i<=li;i++){
                if(l[i]==1){
                    for(int j=i+1;j<i+k;j++){
                        bo[l[j]]=1;
                    }
                }
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r>>c;
            cout<<bo[c]<<endl;
        }
        for(int i=0;i<=200000;i++)bo[i]=0;
    }
    return 0;
}
