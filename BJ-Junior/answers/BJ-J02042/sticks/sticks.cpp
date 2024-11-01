#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        bool flag=0;
        cin>>n;
        for(int i=1;i<=pow(10,n);i++){
            int s=0,z=i;
            while(z!=0){
                int x=z%10;
                if(x==(0||6||9)){
                    s+=6;
                }
                else if(x==1){
                    s+=2;
                }
                else if(x==(2||3||5)){
                    s+=5;
                }
                else if(x==4){
                    s+=4;
                }
                else if(x==7){
                    s+=3;
                }
                else{
                    s+=7;
                }
                z/=10;
            }
            if(s==n){
                flag=1;
                cout<<s<<endl;
                break;
            }
        }
        if(flag==0){
            cout<<-1<<endl;
        }
    }
    return 0;
}
