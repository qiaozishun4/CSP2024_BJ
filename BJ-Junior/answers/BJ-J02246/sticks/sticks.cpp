#include<bits/stdc++.h>
using namespace std;
int d[]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int t=-100;
        if(n<2){cout<<-1<<endl;continue;}
        if(n%7==0){
            for(int i=0;i<9;i++){
                if(n%d[i]==0)t=i;
            }
            if(t>-100&&t<10)for(int i=0;i<n/d[t];i++)cout<<t;
            cout<<endl;
        }
        if((n-1)%7==0){
            cout<<27;

            n-=8;
            for(int i=0;i<n/d[8];i++)cout<<8;
            cout<<endl;
        }
        cout<<-1<<endl;
    }


}
