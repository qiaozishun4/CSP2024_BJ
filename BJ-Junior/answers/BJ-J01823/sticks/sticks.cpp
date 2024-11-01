#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int r[8]={0,0,1,7,4,2,0,8};
int main(){
    cin>>t;
    for (int v=1;v<=t;v++){
        cin>>n;
        if (n==1){
            cout<<"-1"<<endl;
            continue;
        }
        else if (n>1&&n<=7){
            cout<<r[n]<<endl;
        }
    }
    return 0;
}
