#include<bits/stdc++.h>
using namespace std;
bool check[255][255]={};
int ans=52,n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        string s;
        cin>>s;
        if(!check[s[0]][s[1]]){
            check[s[0]][s[1]]=1;
            ans--;
        }
    }cout<<ans<<endl;
    return 0;
}