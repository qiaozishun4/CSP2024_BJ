#include<bits/stdc++.h>
using namespace std;
string a[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    int c=52;
    cin>>n;
    cin>>a[1];
    c--;
    for(int i=2;i<=n;i++){
        cin>>a[i];
        c--;
        for(int j=1;j<i;j++){
            if(a[i]==a[j]){
                c++;
            }
        }
    }
    cout<<c;
    return 0;
}

