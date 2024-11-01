#include<iostream>
#include<stdio.h>
using namespace std;
char hs[10001][10001];
int sum;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string a[1001];
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<i;j++){
            if(a[j]==a[i]){
                sum++;
            }
        }
        }
        cout<<52-n+sum;
return 0;}
