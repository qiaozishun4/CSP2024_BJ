#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n,cnt=52;
string s;
map<string,bool> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >>n;
    while(n--){
        cin >> s;
        if(!mp[s]){
            mp[s]=true;

            cnt--;
        }
    }
    cout << cnt;
    return 0;
}
