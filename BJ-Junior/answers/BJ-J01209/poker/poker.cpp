#include<bits/stdc++.h>
using namespace std;
string s[54];
int n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    int m=n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(s[i]==s[j]){
                m--;
            }
        }
    }
    m=52-m;
    cout<<m;
    return 0;
}