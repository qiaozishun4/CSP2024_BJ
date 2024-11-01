#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    m=n;
    for(int i=1;i<=n;i++){
        cin>>a;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]=a[j]){
                m-=1;
            }
            if(a[i]!=a[j]&&n==52){
                cout<<0<<endl;
                break;
            }
        }
    }
    cout<<52-m<<endl;
    return 0;}
