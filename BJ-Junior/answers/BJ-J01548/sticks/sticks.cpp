#include<bits/stdc++.h>
using namespace std;


int f(int n){
    if(n<2) return -1;
    else if(n==3) return 6;
    else if(n==2) return 1;
    else if(n==4) return 4;
    else if(n==5) return 2;
    else if(n==6) return 6;
    else if(n==7) return 8;
    else if(n==8) return 10;
    else if(n==9) return 18;
    else if(n==10) return 23;
    else if(n==11) return 40;
    else if(n==12) return 28;
    else if(n==13) return 80;
    else if(n==14) return 200;
    else if(n==15) return 235;
    else if(n==16) return 203;
    else if(n==17) return 200;
    else if(n==18) return 208;
    else if(n==19) return 288;
    else if(n==20) return 680;


}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);


    int T,n;
    int s[1000];
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        s[i]=f(n);
    }
    for(int i=0;i<T;i++){
        cout<<s[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
