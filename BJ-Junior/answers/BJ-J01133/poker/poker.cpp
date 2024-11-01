#include <bits/stdc++.h>
using namespace std;

int n,tot;
map<string,int> mp;

int main(){
    //freopen("poker.in","w",stdout);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(!mp[s]) mp[s]=++tot;
    }
    cout<<52-tot;
    return 0;
}
