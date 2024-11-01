#include<bits/stdc++.h>
using namespace std;
string s[55];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,c = 52;
    cin>>n;
    for(int i = 0;i < n;i += 1){
        cin>>s[i];
    }
    for(int i = 0;i < n;i += 1){
        bool b = 0;
        for(int j = 0;j < i;j += 1){
            if(s[i] == s[j]){
                b = 1;
                break;
            }
        }
        if(!b){
            c -= 1;
        }
    }
    cout<<c;
    return 0;
}
