#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    string b[55];
    int sum=0;
    for(int i=1;i<=n;i++){
        string a;
        cin>>a;
        int p=0;
        for(int j=1;j<=i;j++){
            if(b[j]!=a){
                p=p+1;
            }
        }
        if(p==i){
            b[i]=a;
            sum=sum+1;
        }
    }
    int c=52-sum;
    cout<<c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

