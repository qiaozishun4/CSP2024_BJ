#include<bits/stdc++.h>
using namespace std;

string s1 = "0DCHS";
string s2 = "0123456789TJQK";
bool f[5][15];
int cnt = 52,n;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    cin >> n;

    while(n--){
        char a,b;
        cin >> a >> b;
        int x = s1.find(a),y = s2.find(b);
        if(!f[x][y]){
            f[x][y] = true;
            cnt--;
        }
    }

    cout << cnt << endl;

    return 0;
}
