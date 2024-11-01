#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,num=51;
    cin>>n;
    string a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<"51";
        return 0;
    }
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(a[j]==a[i]){
                break;
            }else if(j==0){
                num-=1;
            }
        }
    }
    cout<<num;
    return 0;
}
