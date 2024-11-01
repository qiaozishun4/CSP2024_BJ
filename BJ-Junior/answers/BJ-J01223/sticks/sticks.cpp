
#include<bits/stdc++.h>
using namespace std;
int a[20]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int b[10]={888,108,188,200,208,288,688};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=14){
            cout<<a[n]<<endl;
        }else{
            cout<<b[n%7];
            for(int i=3;i<=(n-1)/7;i++){
                printf("8");
            }
            cout<<endl;
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}