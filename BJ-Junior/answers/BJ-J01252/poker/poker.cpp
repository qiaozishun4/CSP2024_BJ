#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    map<string,int> m;
    int n,de=0;cin>>n;
    for(int i=1;i<=n;i++){
        string x;cin>>x;
        if(m[x]==0){
            m[x]=1;
            de++;
        }
    }
    cout<<52-de<<endl;
    return 0;
}
