#include<iostream>
#include<cstring>
#include<bits/c++io.h>
using namespace std;
int a[1001],n,sum=0;
string b[1001];
int main(){
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        b[i]=s;
    }
    for(int i=1;i<=n;i++){
        int x=1;
        if(b[x]==b[i]){
            sum++;
        }
    }
    if(sum==0){
        cout<<52-n;
    }else{
        cout<<52-n+sum-1;
    }
    
    return 0;
}
