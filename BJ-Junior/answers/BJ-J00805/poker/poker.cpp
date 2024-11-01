#include <bits/stdc++.h>
using namespace std;
string a[100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=1;i<n;i++){
        bool x=false;
        for (int j=0;j<i;j++){
            if (a[i]==a[j]) break;
            if (j==i-1) x=true;
        }
        if (x) cnt++;
    }
    cout<<51-cnt;
    return 0;
}
