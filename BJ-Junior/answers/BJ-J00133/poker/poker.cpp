#include<iostream>
using namespace std;
string hs;
int ans=0,res;
int n,ret=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>hs[i];
    }
    ret+=52-n;
    for(int i=1;i<=n;i++){
        if(!(hs[i]!=hs[i+1]||hs[i]!=hs[i-1])){
             ret++;
        }
    }
    cout<<ret;
    return 0;
}
