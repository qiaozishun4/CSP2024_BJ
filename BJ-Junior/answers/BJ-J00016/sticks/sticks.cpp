#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n,h;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        if(n<2) cout<<"-1"<<endl;
        else{
            cout<<"1";
            n-=2;
            int a=n/7;
            for(int j=1;j<=a-1;j++) cout<<"8";
            n-=a;
            if(n==0) cout<<"8"<<endl;
            if(n==1) cout<<"07"<<endl;
            if(n==2) cout<<"18"<<endl;
            if(n==3) cout<<"78"<<endl;
            if(n==4) cout<<"48"<<endl;
            if(n==5) cout<<"28"<<endl;
            if(n==6) cout<<"08"<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
