#include <iostream>
#include <cmath>
using namespace std;
int n,ans=1;
int gg(int x){
    if (x==1) return 2;
    if (x==7) return 3;
    if (x==4) return 4;
    if (x==5 || x==2 || x==3) return 5;
    if (x==0 || x==6 || x==9) return 6;
    if (x==8) return 7;

}
int main()
{
    int ans[999];
    int T,tmp;
    cin >>T;
    tmp=T;
    int h=0;
    while (T--){
        cin >> n;
    if(n<=1) ans[h]=-1;
    int t1,t2,t3,t4;
    for (int i=0; i<9999; i++){
        if (i<=9 && gg(i)==n) ans[h]=i;
        if (i >=10 && i<=99){
            t1=i%10;
            t2=i/10;
            if (gg(t1)+gg(t2)==n){
                ans[h]=i;
            }
        if (i>=100 && i<=999){
            t1=i%10;
            t2=(i/10)%10;
            t3=i/100;
            if (gg(t1)+gg(t1)+gg(t3)==n) ans[h]=i;
        }
        if (i>=1000 &&i<=9999){
            t1=i%10;
            t2=(i/10)%10;
            t3=(i/100)%10;
            t4=i/1000;
            if (gg(t1)+gg(t1)+gg(t3)+gg(t4)==n) ans[h]=i;
        }
    }
    }
    }
    for (int i=0; i<tmp;i++){
        cout <<ans[i]<<' ';
    }
    return 0;
}
