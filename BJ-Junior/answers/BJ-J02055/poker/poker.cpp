#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s,t;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>> n;
    for(int i=0;i<n;i++){
        cin>> s;
    }
    if(n==1){
        cout<< 52-n;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(s[i]!=s[i+1]){
            cnt++;
        }
    }
    cout<< 52-(cnt+1);
    return 0;
}
