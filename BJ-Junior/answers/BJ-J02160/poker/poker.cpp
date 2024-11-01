#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=52;
    string s,u;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>u;
        if(s.find(u)==-1){
            cnt--;
            s=s+u+" ";
        }
    }
    cout<<cnt;
    return 0;
}