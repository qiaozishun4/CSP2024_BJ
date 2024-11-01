#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n<=1) cout<<-1;
        else{
            int a[10]={};
            a[8]=n/7;
            else if(n%7==1){
                a[0]++;
                a[8]--;
                a[1]++;
            }
            else if(n%7==6) a[6]++;
            if(s>1){
                a[0]=a[6];
                a[6]=0;
            }
            for(int i=1;i<=9;i++){
                if(a[i]>0){
                    cout<<i;
                    a[i]--;
                    break;
                }
            }
            for(int i=0;i<=9;i++){
                while(a[i]>0){
                    cout<<i;
                    a[i]--;
                }
            }
        }
        cout<<'\n';
    }
    return 0;
}
