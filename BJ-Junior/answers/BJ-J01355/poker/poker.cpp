#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string,int> mp;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        mp[s]=1;
    }
    int t = mp.size();
    cout << 52-t << endl;
    return 0;
}
