#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=60+5;

int n,ans=52;
string z;
map <string,bool> vis;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> z;
        if(!vis[z]){
            ans--;
            vis[z] = true;
        }
    }
    cout << ans;
    return 0;
}
