#include<bits/stdc++.h>
using namespace std;
int a[11]= {6,2,5,5,4,5,6,3,7,6};
int b[11]={-1,-1,1,7,4,2,6,8};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n,m=0;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        if(n<=7 && n>=0){
            cout<<b[n]<<endl;
            continue;
        }
        if(n%7==0){
            for(int j=0;j<n/7;j++){
                cout<<"8";
            }
            cout<<endl;
            continue;
        }
        int ans=n%7;
        int num=n/7;
        if(ans==1){
            num--;
            cout<<"10";
            for(int j=0;j<num;j++){
                cout<<"8";
            }
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
