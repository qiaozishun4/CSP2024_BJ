#include <bits/stdc++.h>
using namespace std;
int dd[60]={0,-1,1,7,4,2,6,8,16,18,22,20,28,68,88,168,188,200,208,288,688};
/*
1 2
2 5
4 4
6 6
7 3
8 7
9 6
0 6
3 5
5 5
*/
int bai(int x){
    if(x<=20){
        return dd[x];
}
    /*int tmp=x;
    if(x==1){
        return -1;
    }
    if(x<=7&&x>=2){
        sort(a+1,a+p+1);
        int ans1=0;
        for(int i=1;i<=p;i++){
            ans1=ans1*10+a[i];
        }
        ans1+=d[x];
        minn=min(minn,ans1);
        return d[x];
    }
    for(int i=2;i<=7;i++){
        if((tmp-i-1)/7<tmp/7){
            p++;
            a[p]=d[i];
            bai(tmp-i);
        }
    }
    /*
    while(tmp>=0){
        if(tmp>=7){
            p++;
            a[p]=8;
            tmp-=7;
        }else if(tmp>=6){
            p++;
            a[p]=6;
            break;
        }else if(tmp>=5){
            p++;
            a[p]=2;
            break;
        }else if(tmp>=4){
            p++;
            a[p]=4;
            break;
        }else if(tmp>=3){
            p++;
            a[p]=7;
            break;
        }else if(tmp>=2){
            p++;
            a[p]=1;
            break;
        }else{
            int maxp=1;
            for(int i=1;i<=p;i++){
                if(a[maxp]<a[i]){
                    maxp=i;
                }
            }
            a[maxp]--;
            p++;
            a[p]=1;
            break;
        }
    }
    sort(a+1,a+p+1);
    int ans1=0;
    for(int i=1;i<=p;i++){
        ans1=ans1*10+a[i];
    }
    tmp=x,p=0;
    while(tmp>=0){
        if(tmp>=7){
            p++;
            a[p]=8;
            tmp-=7;
        }else if(tmp>=6){
            p++;
            a[p]=0;
            break;
        }else if(tmp>=5){
            p++;
            a[p]=2;
            break;
        }else if(tmp>=4){
            p++;
            a[p]=4;
            break;
        }else if(tmp>=3){
            p++;
            a[p]=7;
            break;
        }else if(tmp>=2){
            p++;
            a[p]=1;
            break;
        }else{
            int maxp=1;
            for(int i=1;i<=p;i++){
                if(a[maxp]<a[i]){
                    maxp=i;
                }
            }
            a[maxp]--;
            p++;
            a[p]=1;
            break;
        }
    }
    sort(a+1,a+p+1);
    int ans2=0;
    if(a[1]==0){
        int no0=2;
        for(int i=2;i<=p;i++){
            if(a[i]!=0){
                no0=i;
                break;
            }
        }
        a[0]=a[no0];
        for(int i=no0-1;i>=0;i++){
            a[i+1]=a[i];
        }
    }
    int ans2=0;
    for(int i=1;i<=p;i++){
        ans2=ans2*10+a[i];
    }
    return max(ans1,ans2);*/
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n;
        if(n%7==0){
            for(int j=1;j<=n/7;j++){
                cout << "8";
            }
            cout << "\n";
        }else if(n%7==1){
            cout << "16";
            for(int j=2;j<=n/7;j++){
                cout << "8";
            }
            cout << "\n";
        }else{
            cout << bai(n) << "\n";
        }
    }
    return 0;
}
