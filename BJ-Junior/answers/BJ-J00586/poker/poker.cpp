#include<bits/stdc++.h>
using namespace std;
vector<string>vs;
int n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        string t;
        cin>>t;
        vs.push_back(t);
    }
    sort(vs.begin(),vs.end());
    vs.erase(unique(vs.begin(),vs.end()),vs.end());
    cout<<52-vs.size();
    return 0;
}
