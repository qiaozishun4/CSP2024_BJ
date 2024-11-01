#include<bits/stdc++.h>
using namespace std;
int n;
vector<char>v[2];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        char s1,s2;
        cin >> s1 >> s2;
        bool l = true;
        for(int i = 0; i < v[1].size(); i++){
            if(v[0][i] == s1 && v[1][i] == s2){
                l = false;
                break;
            }
        }
        if(l){
            v[0].push_back(s1);
            v[1].push_back(s2);
        }
    }
    cout << 52-v[1].size();
    return 0;
}