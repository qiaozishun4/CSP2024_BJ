#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n,cur,ans,cnt,last,a[N],vis[N],maxn;
bool flag;
map<int,int> mp;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    scanf("%d",&n);
    ans = n;
    for(int i = 1; i <= n; ++i) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; ++i) ++mp[a[i]];
    for(auto kv:mp){
        ++cnt;
        if(cnt==1) last = kv.second;
        else{
            if(kv.second != last) flag = true;
            last = kv.second;
        }
    }
    if(cnt==1){
        for(auto kv:mp){
            cout << kv.second;
            return 0;
        }
    }
    if(cnt==2){
        bool f = true;
        for(auto kv:mp){
            if(f){ last = kv.second; f = false;}
            else{
                cout << (last>kv.second? last:kv.second);
                return 0;
            }

        }
    }
    if(!flag){
        for(auto kv:mp){
            cout << kv.second << endl;
            return 0;
        }
    }
    for(auto kv:mp){
        maxn = max(maxn,kv.second);
    }
    cout << maxn << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
