#include<iostream>
using namespace std;
int main(){
    int n,num=1;
    cin>>n;
    string a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int flag;
    for(int i=1;i<n;i++){
        flag=0;
        for(int j=0;j<i;j++){
            if(a[i]==a[j]){
                break;
                flag=1;
            }
        }
        if(flag==0){
            num++;
        }
    }
    cout<<52-num;
    return 0;
}
