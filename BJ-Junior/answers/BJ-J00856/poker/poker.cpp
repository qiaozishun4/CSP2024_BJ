#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
freopen("poker.in",'r',stdin);
freopen("poker.out",'w',stdin);
cin>>n;
int sum=52;
string str[n];
for(int i=0;i<n;i++){
cin>>str[i];
}
for(int i=0;i<n;i++){
        sum--;
    for(int j=0;j<n&&j!=i;j++){
        if(str[i]==str[j]){
            sum++;
        }
    }
}
cout<<sum;
}
