#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t,n,a[100010];
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
    }
    for(int i=0;i<t;i++){
        cout<<a[i]+a[3]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
return 0;}
