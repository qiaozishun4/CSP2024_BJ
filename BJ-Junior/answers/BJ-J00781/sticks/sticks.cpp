//correct!
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mn[8]={-1,-1,1,7,4,2,0,8};
int t;
int n;
/*
1~7
8 10
9 18
10 22
11 20
12 28
13 80
14 88
*/
void ck(int x){
     if(n<8){
        if(n==6){
            printf("6");
            return;
        }
        printf("%d",mn[x]);
        return;
    }
    switch(x){
        case 8:{printf("10");break;}
        case 9:{printf("18");break;}
        case 10:{printf("22");break;}
        case 11:{printf("20");break;}
        case 12:{printf("28");break;}
        case 13:{printf("80");break;}
        case 14:{printf("88");break;}
        default:break;
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<8){
            if(n==6){
                cout<<6<<"\n";
                continue;
            }
            cout<<mn[n]<<"\n";
            continue;
        }else if(n<=14){
            ck(n);
            puts("");
            continue;
        }else{
            int sl=(n-7)/7;
            n-=sl*7;
           // cout<<n;
            ck(n);
            if(sl>0){
                while(sl--){
                    putchar('8');
                }
            }
            puts("");
        }
    }
    return 0;
}
/*
10
6
24
235
22
23
6
23
22
2445
*/
