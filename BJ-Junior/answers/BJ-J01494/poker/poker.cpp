#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, num[52];
    memset(num, 0, sizeof(num));
    string a;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cin>>a;
        int tmp=0;
        if(a[0]=='S') tmp+=0;
        else if(a[0]=='D') tmp+=13;
        else if(a[0]=='C') tmp+=26;
        else if(a[0]=='H') tmp+=39;

        if(a[1]=='A') tmp+=1;
        else if(a[1]=='2') tmp+=2;
        else if(a[1]=='3') tmp+=3;
        else if(a[1]=='4') tmp+=4;
        else if(a[1]=='5') tmp+=5;
        else if(a[1]=='6') tmp+=6;
        else if(a[1]=='7') tmp+=7;
        else if(a[1]=='8') tmp+=8;
        else if(a[1]=='9') tmp+=9;
        else if(a[1]=='T') tmp+=10;
        else if(a[1]=='J') tmp+=11;
        else if(a[1]=='Q') tmp+=12;
        else if(a[1]=='K') tmp+=13;
        //printf("%d\n", tmp);
        num[tmp]=1;
    }
    int ans=0;
    for(int i=1; i<=52; i++){
        if(num[i]==0)
            ans++;
    }
    printf("%d", ans);
    return 0;
}
