#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
int n;
const int zhong=52;
string a[60];
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
int jia=0;
sort(a,a+n);
for(int i=0;i<n;i++){
    if(a[i]==a[i-1]){
        jia++;
    }
}
cout<<(zhong+jia)-n;
return 0;
}
