
#include <iostream>
using namespace std;
int main(){
int n;
cin>>n;
int a[n],s,cnt=n,o[n];
for(int i=0;i<=n;i++){
    cin>>a[i];
    o[i]=0;
}
for(int i=0;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(a[i]<a[j]){
            s++;
        }else if(a[i]==a[j]){
            o[i]++;
        }
    }
}cout<<o[0];
return 0;}