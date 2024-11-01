#include<bits/stdc++.h>
using namespace std;
string s[60];
int cnt;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i]==s[j]){
                cnt++;
            }
        }
    }
    cout<<52-n+cnt;
    return 0;
}