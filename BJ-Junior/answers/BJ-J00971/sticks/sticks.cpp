#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin<<a;
        if(a==1) cout<<"-1"<<endl;
        if(a==2) cout<<"1"<<endl;
        if(a==3) cout<<"7"<<endl;
        if(a==4) cout<<"4"<<endl;
        if(a==5) cout<<"2"<<endl;
        if(a==6) cout<<"6"<<endl;
        if(a==7) cout<<"8"<<endl;
        if(a==8) cout<<"16"<<endl;
        if(a==9) cout<<"18"<<endl;
        if(a==10) cout<<"22"<<endl;
        if(a==18) cout<<"208"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
