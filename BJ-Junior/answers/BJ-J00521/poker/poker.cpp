#include<bits/stdc++.h>
using namespace std;
unordered_set<string> s;
string str;
int n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str;
        s.insert(str);
    }
    cout<<52-s.size();
    return 0;
}
