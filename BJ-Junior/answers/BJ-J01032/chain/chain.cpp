#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n, kk, q, t;
int l[100010];
vector<int> s[100010];

int main(){

    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin>>t;
    while(t--){
        cin>>n>>kk>>q;
        for(int i=1; i<=n; i++)
        {
            cin>>l[i];
            for(int j=1; j<=l[i]; j++){
                int t; cin>>t;
                s[i].push_back(t);
            }
        }
        for(int i=1; i<=q; i++){
            int r, c;
            cin>>r>>c;
            bool flag = false;
            if(r==1){
                for(int j=1; j<=n; j++){
                    int oneplace=-1000000;
                    for(int k=0; k<s[j].size(); k++){
                        if(s[j][k]==1) oneplace = k;
                        if(s[j][k] == c && k-oneplace+1 <=kk) flag = true;
                    }
                }
                cout<<flag<<endl;
            }
            else{
                cout<<1<<endl;
            }
        }
    }


    return 0;
}
