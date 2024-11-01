#include<iostream>
#include<map>
using namespace std;
int n,ans=52;
map<string,bool>p;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(!p.count(s)){
            p[s]=1;
            ans--;
        }
    }
    cout<<ans<<'\n';
    return 0;
}