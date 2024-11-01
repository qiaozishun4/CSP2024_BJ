#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("duel.in","r",stdin);
freopen("duel.out","w",stdout);

int n[100000];
int a;
cin>>a;
for(int i=0;i<a;i++){
        cin>>n[i];}

if(a%2==0){
    cout<<a/2;
}
if(a%2!=0){
        a=a-1;
    cout<<a/2;

}
return 0;
}
