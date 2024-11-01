#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        if(n<2) cout<<-1<<endl;
        else if(n>=2&&n<8){
            if(n==2) cout<<1;
            if(n==3) cout<<7;
            if(n==4) cout<<4;
            if(n==5) cout<<2;
            if(n==6) cout<<6;
            if(n==7) cout<<8;
            cout<<endl;
        }
        else if(n>=8){
            if(n%7==1) cout<<10;
            else if(n%7==2&&n>=9) cout<<18;
            else if(n%7==3&&n>=10) cout<<40;
            else if(n%7==4&&n>=11) cout<<20;
            else if(n%7==5&&n>=12) cout<<28;
            else if(n%7==6&&n>=13) cout<<68;
            for(int i=1;i<n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
