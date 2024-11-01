#include<bits/stdc++.h>
using namespace std;
int n,l;
string a[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    l=52-n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<i;j++){
            if(a[i]==a[j]){
                l++;
            }
        }
    }
    cout<<l;
    return 0;
}
