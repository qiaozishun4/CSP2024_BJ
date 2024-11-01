#include<bits/stdc++.h>
using namespace std;
int sti[20]={6,2,5,5,4,5,6,3,7,6};
int t,n;
string s;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1) cout<<-1<<endl;
        else{
            int cnt=0;
            while(n>=7){
                if(n/7==n/6&&n!=7||n==8){
                    s[++cnt]='0';
                    n-=6;
                }
                else{
                    s[++cnt]='8';
                    n-=7;
                }

            }
            if(n>0){
                for(int i=1;i<=9;i++){
                    if(n==sti[i]){
                        cout<<i;
                        break;
                    }
                }
            }
            for(int i=cnt;i>=1;i--){
                cout<<s[i];
            }
            cout<<endl;
        }
    }

    return 0;
}
