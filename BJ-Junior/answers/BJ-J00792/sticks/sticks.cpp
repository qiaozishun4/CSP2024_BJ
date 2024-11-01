#include<bits/stdc++.h>
using namespace std;
//             0 1 2 3 4 5 6 7 8 9
vector<int> a={6,2,5,5,4,5,6,3,7,6};
int work20(int i) {
    if(i==1) return -1;
    if(i==2) return 1;
    if(i==3) return 7;
    if(i==4) return 4;
    if(i==5) return 2;
    if(i==6) return 6;
    if(i==7) return 8;
    if(i==8) return 10;
    if(i==9) return 18;
    if(i==10) return 22;
    if(i==11) return 20;
    if(i==12) return 28;
    if(i==13) return 68;
    if(i==14) return 100;
    if(i==15) return 108;
    if(i==16) return 188;
    if(i==17) return 200;
    if(i==18) return 208;
    if(i==19) return 288;
    if(i==20) return 688;
}
int work50(int i) {
    if(i==21) return 888;
    if(i==22) return 1088;
    if(i==23) return 1888;
    if(i==24) return 2008;
    if(i==25) return 1888;
    if(i==26) return 2008;
    if(i==27) return 2088;
    if(i==28) return 2888;
    if(i==29) return 6888;
    if(i==30) return 8888;
    if(i==31) return 20088;
    if(i==32) return 20888;
    if(i==33) return 28888;
    if(i==34) return 68888;
    if(i==35) return 88888;
    if(i==36) return 108888;
    if(i==37) return 188888;
    if(i==38) return 200888;
    if(i==39) return 208888;
    if(i==40) return 288888;
    if(i==41) return 688888;
    if(i==42) return 888888;
    if(i==43) return 1088888;
    if(i==44) return 1888888;
    if(i==45) return 2008888;
    if(i==46) return 2088888;
    if(i==47) return 2888888;
    if(i==48) return 6888888;
    if(i==49) return 8888888;
    if(i==50) return 10888888;
}
int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;

        if(n<=20) {
            cout<<work20(n)<<endl;
        }
        else if(n<=50) {
            cout<<work50(n)<<endl;
        }
        else if(n%7==0&&n>=100) {
            n/=7;
            while(n--) {
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==1&&n>=100) {
            cout<<10;
            for(int i=1;i<=n/7-1;i++) {
                cout<<8;
            }
            cout<<endl;
        }
    }

	return 0;
}
