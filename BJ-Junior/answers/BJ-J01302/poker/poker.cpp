#include<iostream>
using namespace std;
string a[128];int n,sum;
int main(){freopen("poker.in","r",stdin);freopen("poker.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];int k=0;
    for(int j=0;j<i;j++){
        if(a[i]==a[j]){
            continue;
        }k++;
    }if(k==i){
    sum++;}
}cout<<52-sum;
return 0;}
