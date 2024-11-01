#include<bits/stdc++.h>
using namespace std;
int n;
string a[69];

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
   cin>>a[i];
    }
    sort(a+1,a+n+1);
    int uu=1;
    for(int i=2;i<=n;i++){
    if(a[i]!=a[i-1])uu++;}
    cout<<52-uu;
    fclose(stdin);
   fclose(stdout);
    return 0;
}
