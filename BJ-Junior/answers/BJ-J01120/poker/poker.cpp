#include<bits/stdc++.h>
using namespace std;
string a[52];
int n,i,j,m,f;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
                if(a[i]==a[j]){
                    f=1;
                    //m--;
                    break;
                }
        }
        if(f==0){
           m++;
        }
        f=0;

    }
    cout<<52-m;
    return 0;
}