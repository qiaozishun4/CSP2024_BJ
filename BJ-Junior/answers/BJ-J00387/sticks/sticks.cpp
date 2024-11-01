#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int easy[15]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68};
int bo[100010];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<14){
            cout<<easy[n]<<endl;
        }else{
        int m=n/7,g=n%7;
        if(g==0){
            for(int i=1;i<=m;i++){
                cout<<"8";
            }
        }else if(g==1){
            cout<<"10";
            for(int i=1;i<m;i++){
                cout<<"8";
            }
        }else if(g==2){
            cout<<"1";
            for(int i=1;i<=m;i++){
                cout<<"8";
            }
        }else if(g==3){
            cout<<"200";
            for(int i=1;i<m-1;i++){
                cout<<"8";
            }
        }else if(g==4){
            cout<<"20";
            for(int i=1;i<m;i++){
                cout<<"8";
            }
        }else if(g==5){
            cout<<"2";
            for(int i=1;i<=m;i++){
                cout<<"8";
            }
        }else{
            cout<<"6";
            for(int i=1;i<=m;i++){
                cout<<"8";
            }
        }
        cout<<endl;
        }
    }
    return 0;
}
