#include <bits/stdc++.h>
using namespace std;
int groups,tmp;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&groups);
    while (groups--){
        scanf("%d",&tmp);
        if (tmp==1){
            cout << "-1" << '\n';
            continue;}
        if (tmp%7==0){
            for (int i=1;i<=tmp/7;i++)
                cout << "8";}
        else if (tmp%7==1){
            cout << "10";
            for (int i=1;i<=tmp/7-1;i++)
                cout << "8";}
        else if (tmp/6>1&&tmp%6==0){
            cout << "2";
            for (int i=1;i<=tmp/6-2;i++)
                cout << "0";
            cout << "8";}
        else if (tmp<=20){
            if (tmp==2) cout << "1";
            if (tmp==3) cout << "7";
            if (tmp==4) cout << "4";
            if (tmp==5) cout << "2";
            if (tmp==6) cout << "6";
            if (tmp==9) cout << "18";
            if (tmp==10) cout << "22";
            if (tmp==11) cout << "20";
            if (tmp==13) cout << "68";
            if (tmp==16) cout << "188";
            if (tmp==17) cout << "238";
            if (tmp==19) cout << "288";
            if (tmp==20) cout << "688";}
        cout << '\n';}
    return 0;}
