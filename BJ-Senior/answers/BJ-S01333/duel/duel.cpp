#include<bits/stdc++.h>
using namespace std;
int a[50];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int compare;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1) compare=a[1];
        if(compare!=a[i]) flag=0
    }
    if(flag==1){
        cout<<n;
        return 0;
    }
    else cout<<n-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
