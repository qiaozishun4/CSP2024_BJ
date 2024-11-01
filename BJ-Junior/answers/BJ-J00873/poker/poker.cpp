#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
string a[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<i;j++){
            if(a[j][0]==a[i][0]&&a[j][1]==a[i][1]){
                i--;
                n--;
            }
        }
    }
    cout<<(52-n);
    return 0;
}
