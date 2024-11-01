#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long mp[N];
bool fir[N];
int t,n,k,q;
int l,r,c;
vector<int>v[N];
int main(){//rp++
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> t;
    while(t--){
        bool flag = 0;
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++){
            cin >> l;
            for(int j = 1;j <= l;j++){
                int x;
                cin >> x;
                if(x == 1 && l - j >= 1){
                    fir[i] = j;
                    flag = 1;
                }
                mp[x]++;
                v[i].push_back(x);
            }
        }
        while(q--){
            cin >> r >> c;
            if(!mp[c]){cout << 0 << endl;continue;}
            if(!flag){cout << 0 << endl;continue;}
            cout << 0 << endl;
        }

    }

}//rp++
