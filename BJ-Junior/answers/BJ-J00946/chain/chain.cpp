#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
#define endl '\n'

const int MAXN = 1e3 + 10,Maxn = 2e3 + 10;
int t,n,k,q,s[MAXN][Maxn];

bool check(int pos1,int pos2){
    int len = max(pos2,pos1) - min(pos1,pos2) + 1;
    return len >= 2 && len <= k;
}

int main(){
    ios::sync_with_stdio(false);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> t;
    while(t--){
        map<pair<int,int>,pair<int,int> > mp;
        cin >> n >> k >> q;
        for(int i = 1;i <= n;++i){
            cin >> s[i][0];
            for(int j = 1;j <= s[i][0];++j){
                cin >> s[i][j];
                if(mp.find(make_pair(i,s[i][j])) != mp.end()) mp[make_pair(i,s[i][j])].second = j;
                else{
                    mp[make_pair(i,s[i][j])].second = j;
                    mp[make_pair(i,s[i][j])].first = j;
                }
            }
        }
        while(q--){
            int r,c;
            cin >> r >> c;
            bool flag = 0;
            for(int i = 1;i <= n;++i){
                if(mp.find(make_pair(i,1)) == mp.end() || mp.find(make_pair(i,c)) == mp.end()) continue;
                int pos1 = mp[make_pair(i,1)].first,pos2 = mp[make_pair(i,1)].second;
                int pos3 = mp[make_pair(i,c)].first,pos4 = mp[make_pair(i,c)].second;
                if(check(pos1,pos3) || check(pos1,pos4) || check(pos2,pos3) || check(pos2,pos4)){
                    flag = 1;
                    break;
                }
            }
            cout << flag << endl;
        }
    }
    return 0;
}
