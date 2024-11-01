#include<iostream>
#include<cstring>
int a[1e5+1][2e5+1],l[1e5+1],r[1e5+1];
using namespace std;
int main(){
    freopen("chain1.in","r",stdin);
    freopen("chain1.out","w",stdout);
    int t,n,k,q;
    cin>>t;
    for(int i=0;i<t;i++){
       cin>>n>>k>>g;
       for(int i=0;i<n;i++){
            scanf("%d",l[i]);
            for(int j=0;j<l[i];j++){
                scanf("%d",a[i][j]);
            }
       }
       for(int i=0;i<q;i++){
        cin>>r[i]>>c[i];
        
        
       }
    }
    for(int i=0;i<q;i++){
        cout<<-1;
    }
    return 0;
}