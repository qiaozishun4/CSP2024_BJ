#include<bits/stdc++.h>
using namespace std;
string s[55];
bool flag[55];
int ascll(string st){
    int ssuum = 0;
    for(int i=0;i<=st.size()-1;i++){
        ssuum += int(st[i]);
    }
    return ssuum;
}
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w". stdout);
    int n;
    cin >> n;
    int sum=0;
    s[0] = "**&";
    for(int i = 1; i <= n; i++){
        cin>>s[i];
    }
    for(int i = 1; i <= n; i++){
        if(flag[ascll(s[i])] != 1){
            sum++;
            flag[ascll(s[i])] = 1;
        }
    }
    cout << 52-sum << endl;
    return 0;
}
