#include<bits/stdc++.h>
using namespace std;
unordered_map <string,int> p;
string tmp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        p[tmp]=1;
    }
    cout<<52-p.size();
    return 0;
}
