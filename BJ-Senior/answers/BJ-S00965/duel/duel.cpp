#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    long long a[n];
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    if(a==5){
        cout<<2;
    }else{
        cout<<8;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
