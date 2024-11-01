#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >>n;
    map<string,bool> p;
    int ans = 52;
    string a;
    for(int i=1;i<=n;i++){
        cin >>a;
        if(p[a] == 0){
            ans--;
            p[a] = 1;
        }
        else continue;
    }
    cout <<ans;
    return 0;
}
