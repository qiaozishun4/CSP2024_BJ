#include<iostream>
using namespace std;
int arr[15]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;
    }
    for(int i=1;i<=T;i++){
            if(n==arr[i]){
                cout<<i<<endl;
            }else{
                cout<<"-1"<<endl;
            }
    }
    return 0;
}