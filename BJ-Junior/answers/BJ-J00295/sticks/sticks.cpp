#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n,x;
    for(int i=1;i<=n;i++){
        cin>>x;
        for(int j=1;j<=x/7;j++) cout<<'8';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}