#include <bits/stdc++.h>
using namespace std;
int a[11];
//14 7744 1111111
//2 3 4 5 6 7
//7 25 34 7
//14 77
int main (){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
a[0]=6;
a[1]=2;
a[2]=5;
a[3]=5;
a[4]=4;
a[5]=5;
a[6]=6;
a[7]=3;
a[8]=7;
a[9]=6;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if(n%7==1){
            if(n<=15){
                if(n==8){
                    cout << -1;
                    continue;
                }
                if(n==15){
                    cout << 108;
                    continue;
                }
                if(n==1){
                    cout << -1 << endl;
                    continue;
                }
            }
            cout << 10;
            for(int i=1;i<=((n-1)/7)-1;i++){
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if(n%7==2){
            cout << 1;
            for(int i=1;i<=n/7;i++){
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if(n%7==4){
            if(n==4){
                cout << 4 << endl;
                continue;
            }
            if(n==11){
            cout << 20 << endl;
            continue;
            }
            cout << 20;
            for(int i=1;i<=n/7;i++){
                cout << 8;
            }
            cout << endl;
             continue;
        }
        if(n%7==5){
            cout << 2;
            for(int i=1;i<=n/7;i++){
                cout << 8;
            }
            cout << endl;
            continue;
        }
        if(n%7==6){
            cout << 6;
            for(int i=1;i<=n/7;i++){
                cout<< 8;
            }
            cout << endl;
            continue;
        }
        if(n==1){
            cout << -1;
            cout << endl;
            continue;
        }
        if(n==2){
            cout << 1;
            cout << endl;
            continue;
        }
        if(n==3){
            cout << 7;
            cout << endl;
            continue;
        }
        if(n==4){
            cout << 4;
            cout << endl;
            continue;
        }
        if(n==5){
            cout << 2;
            cout << endl;
            continue;
        }
        if(n==6){
            cout << 6;
            cout << endl;
            continue;
        }
        if(n==7){
            cout << 8;
            cout << endl;
            continue;
        }
        if(n==8){
            cout << -1;
            cout << endl;
            continue;
        }
        if(n==9){
            cout << 18;
            cout << endl;
            continue;
        }
        bool f=0;
        for(int i=1;i<=9;i++){
            if(f){
                break;
            }
            for(int j=0;j<=9;j++){
                if(a[i]+a[j]==n){
                    cout << i*10+j << endl;
                    f=1;
                    break;
                }
            }
        }
        if(f==0){
            for(int i=1;i<=9;i++){
                    if(f){
                        break;
                    }
                for(int j=0;j<=9;j++){
                        if(f){
                            break;
                        }
                    for(int k=0;k<=9;k++){
                        if(a[i]+a[j]+a[k]==n){
                            cout << i*100+j*10+k << endl;
                            f=1;
                            break;
                        }
                    }
                }
            }
        }
        if(f==0){
            for(int i=1;i<=9;i++){
                if(f){
                    break;
                }
                for(int j=0;j<=9;j++){
                        if(f){
                    break;
                }
                    for(int k=0;k<=9;k++){
                        if(f){
                    break;
                }
                        for(int s=0;s<=9;s++){
                            if(a[i]+a[j]+a[k]+a[s]==n){
                                cout << i*1000+j*100+k*10+s << endl;
                                f=1;
                            }
                        }
                    }
                }
            }
        }
        if(f==0){
            for(int i=1;i<=9;i++){
                if(f){
                    break;
                }
                for(int j=0;j<=9;j++){
                        if(f){
                    break;
                }
                    for(int k=0;k<=9;k++){
                        if(f){
                    break;
                }
                        for(int s=0;s<=9;s++){
                                if(f){
                    break;
                }
                            for(int q=0;q<=9;q++){
                                if(a[i]+a[j]+a[k]+a[q]==n){
                                    cout << i*10000+j*1000+k*100+s*10+q << endl;
                                    f=1;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(f==0){
            for(int i=1;i<=9;i++){
                    if(f){
                    break;
                }
                for(int j=0;j<=9;j++){
                    if(f){
                    break;
                }
                    for(int k=0;k<=9;k++){
                            if(f){
                    break;
                }
                        for(int s=0;s<=9;s++){
                            if(f){
                    break;
                }
                            for(int q=0;q<=9;q++){
                                    if(f){
                    break;
                }
                                for(int t=0;t<=9;t++){
                                    if(a[i]+a[j]+a[k]+a[s]+a[q]==n){
                                        cout << i*100000+j*10000+k*1000+s*100+q*10+t << endl;
                                        f=1;
            break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
