#include<bits/stdc++.h>
using namespace std;
int t,n,s,z;
int a[15]={0,-1,1,7,4,2,6};
int b[15]={6,2,5,5,4,5,6,3,7,6};
int c[15]={0,10,1,200,20,2,6};
int d[15]={0,1,0,2,1};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int l=1;l<=t;l++){
        cin>>n;
        if(n<7){
            cout<<a[n]<<endl;
            continue;
        }
        z=n/7;
        n%=7;
        if(n==0){
            for(int i=1;i<=z-d[n];i++){
                cout<<"8";
            }
            cout<<endl;
        }
        else{
           cout<<c[n];
            for(int i=1;i<=z-d[n];i++){
                cout<<"8";
            }
            cout<<endl;
            }
        }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
