#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int N[n+1];
    for(int i=1;i<=n;i++){
        cin>>N[i];
    }
    int a;
    for(int i=1;i<=n;i++){
        for(int j=2;j<=n-i+1;j++){
        if(N[j]>N[j-1]){
            a=N[j];
            N[j]=N[j-1];
            N[j-1]=a;
        }
        }
    }
    int m[n]={};
    int b=1;
    a=1;
    for(int i=1;i<=n-1;i++){
        if(i==n-1){
            if(N[i]==N[i+1]){
                b++;
                m[a]=b;
                b=1;
            }
            else{
                m[a]=b;
                m[a+1]=b;
                a++;
            }
            break;
        }
        if(N[i]==N[i+1])
            b++;
        else{
            m[a]=b;
            a++;
            b=1;
        }
    }
    for(int i=1;i<=a-1;i++){
        n=n-min(m[i],m[i+1]);
    }
    cout<<n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}