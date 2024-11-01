#include <bits/stdc++.h>
using namespace std;

int n,k,q,x,y;
vector < int > num[100005],t[100005];
int cnt[200005];

vector < int > sort(vector < int > a){
    memset(cnt,0,sizeof cnt);
    for(int i = 0;i < a.size();i++) cnt[a[i]]++;
    a.clear();
    for(int i = 0;i <= 200000;i++)
        for(int j = 1;j <= cnt[i];j++) a.push_back(i);
    return a;
}

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++){
            cin >> x;
            for(int j = 1;j <= x;j++){
                cin >> y;
                if(j > 1 && j <= k) num[i].push_back(y);
            }
            t[i] = sort(num[i]);
        }
        while(q--){
            cin >> x >> y;
            bool f = false;
            for(int i = 1;i <= n;i++) if(binary_search(t[i].begin(),t[i].end(),y)) f = true;
            if(f) f = false;
            for(int i = 1;i <= n;i++) if(num[i][num[i].size() - 1] == y) f = true;
            if(!f){
                cout << "0\n";
                continue;
            }
            cout << "1\n";
        }
    }
    return 0;
}
