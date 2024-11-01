#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int a,n=0;
    string b[60];
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b[i];
        int m=0;
        for(int j=1;j<i;j++){
            if(b[i]==b[j]){
                m++;
            }
        }
        if(m==0){
            n++;
        }
    }
    cout<<52-n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}