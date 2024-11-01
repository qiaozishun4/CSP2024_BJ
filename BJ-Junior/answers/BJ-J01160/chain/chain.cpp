#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int n,d,p,s,molata,pi,a,b;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d>>p>>s;
    }
    for(int i=1;i<=d;i++){
        cin>>molata;
        for(int i=1;i<=molata;i++){
            cin>>pi;
        }
    }
    for(int i=1;i<=s;i++){
        cin>>a>>b;
        if(a==b&&a%2==0){
            cout<<1<<endl;
        }else if(a==b&&a%2!=0){
            cout<<0<<endl;
        }else if((b-a)%2!=0){
            cout<<0<<endl;
        }else{
            cout<<1<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
