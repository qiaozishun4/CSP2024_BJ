#include<bits/stdc++.h>
using namespace std;
int c[4][13];
map<char,map<int,bool>>m;
int n,ans=52;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        char a,b;
        cin>>a>>b;
        if(m[a][b]==false){
            m[a][b]=true;
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
