#include<bits/stdc++.h>
using namespace std;
int n;
string a[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(n==1){
                cout<<51;
                return 0;
            }
            if(a[i]==a[j])
                n--;
        }
    }
    cout<<52-n;
    return 0;
}
