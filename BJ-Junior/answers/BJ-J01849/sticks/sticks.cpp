#include<bits/stdc++.h>

using namespace std;


int a[15] = {6,2,5,5,4,5,6,3,7,6};
char r[10007];
string f[100007];
int n, t;
string cmp(string a, string b){
    if(a == "") return b;
    if(a.length() < b.length()) return a;
    else if(a.length() > b.length()) return b;
    else{
        if(a < b) return a;
        else return b;
    }
}

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while(t--){
       cin >> n;
        for(int i = 0; i <= n; i++) f[i] = "";
        f[1] = "-1";
        f[6] = "6";
        f[2] = "1";
        f[3] = "7";
        f[4] = "4";
        f[5] = "2";
        f[7] = "8";

        for(int j = 0; j <= n; j++){
            for(int i = 9; i >= 0; i--){
                if(j < a[i]) continue;
                if(f[j-a[i]] != ""){
                    if(f[j-a[i]][0] == '0') continue;
                    f[j] = cmp(f[j], f[j-a[i]]+char(i+'0'));
                }
            }
        }
        cout << f[n] <<"\n";
    }


    return 0;
}
