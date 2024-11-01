#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    for(int q=1;q<=a;q++){
        int n,o;
        cin>>n;
        long long int A[n]={};
        long long int C[n]={};
        for(int i=1;i<=n;i++){
            C[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>o;
            A[i]=o;
        }
        for(int i=2;i<=n;i++){
            if(A[i-1]==A[i])    C[i]=A[i];
        }
        int p=0;
        for(int i=1;i<=n;i++){
            if(C[i]!=0){
                p+=C[i];
            }
        }
        cout<<p<<endl;
    }

    return 0;
}
