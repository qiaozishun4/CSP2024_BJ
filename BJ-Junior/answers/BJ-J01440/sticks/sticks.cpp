#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    int p[25]={-1,1,7,4,2,6,8,10,18,22,20,28,38,88,108,188,216,208};
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        cout<<p[a];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}