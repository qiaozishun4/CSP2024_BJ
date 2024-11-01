#include<bits/stdc++.h>
using namespace std;

string str[60];

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    bool flag=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str[i];
        for(int j=1;j<i;j++){
            if(str[j]==str[i]){
                flag=1;
                break;
            }
        }
        if(flag==0) ans++;
        flag=0;
    }
    cout<<52-ans;
    return 0;
}
