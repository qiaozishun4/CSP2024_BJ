#include<bits/stdc++.h>
using namespace std;
string a[54];
int n,sum;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        bool f=true;
        for(int j=1;j<i;j++){
            if(a[j]==a[i]){
                f=false;
                break;
            }
        }
        if(f==true){
            sum++;
        }
    }
    cout<<52-sum;
    return 0;
}