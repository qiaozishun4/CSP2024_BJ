#include <bits/stdc++.H>
using namespace std;
int n,k,q,l;
vector<vector<int> > ve;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> n >> k >> q;
    for(int i = 1;i <= n;i ++){
        cin >> l;
        for(int j = 1;j <= l;j ++){
            cin >> ve[i][j];
        }
    }
    while(q--){
        int x,y;
        cin >> x >> y;
    }
    //cout << "我致力搞个506B（才不是不会写）";
    //cout << "506B了，好耶()";
    fclose(stdin);
    fclose(stdout);
}
