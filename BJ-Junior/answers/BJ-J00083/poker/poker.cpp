#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    string a;
    cin>>n;
    int zh=51,c=n-3;
    for(int i=1;i<=n;i++){
        cin>>a;
        string b=a;
        if(i>=2){
            for(int j=1;j<=i-1;j++){
                if(b==a){
                    zh++;
                }
            }
        }
    }
    if(n==1){
        cout<<51-n*4;
        return 0;
    }
    else{
        cout<<zh-n;
    }
    return 0;
}
