#include <bits/stdc++.h>
using namespace std;
int n;
string a[1001];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<52-n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
