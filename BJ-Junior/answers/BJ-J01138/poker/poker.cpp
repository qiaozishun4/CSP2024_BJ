#include <bits/stdc++.h>
using namespace std;
string pk[100];
int cnt;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    string s;
    cin >> n;
    cin >> pk[0],cnt++;
    for (int i=1; i<n; i++){
        cin >> s;
        bool rp=false;
        for (int j=0; j<cnt; j++)
            if (s==pk[j]){
                rp=true;
                break;
            }
        if (!rp) {
            pk[cnt++]=s;
        }
    }
    cout << 52-cnt << endl;
    return 0;
}