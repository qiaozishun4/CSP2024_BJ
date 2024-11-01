#include<bits/stdc++.h>
using namespace std;
char a[1001];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w"stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n!=4){
        cout<<52-n;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
