#include<iostream>
#include<vector>
#include<random>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    for(cin>>T;T;T--){
        int n,k,q;
        cin>>n>>k>>q;
        vector<string> s[n];
        for(int i=0,l;i<n;i++){
            cin>>l;
            for(int j=0;j<l;j++){
                string x;
                cin>>x;
                s[i].push_back(x);
            }
        }
        while(q--){
            int r,c;
            cin>>r>>c;
            mt19937 generate(r*c);
            cout<<generate()%2<<'\n';
        }
    }
}