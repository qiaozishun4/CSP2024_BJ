#include<bits/stdc++.h>
using namespace std;
int s(int m){
    if(m<=1) return -1;
    if(m%7==0&&m!=0){
        for(int i=1;i<m/7;i++){
            cout<<"8";
        }
        cout<<"8"<<endl;
        return 0;
    }
    if(m%7==1&&m!=1&&m!=8){
        cout<<"10";
        for(int i=2;i<m/7;i++){
            cout<<"8";
        }
        cout<<"8"<<endl;
        return 0;
    }
    if(m%7==2&&m!=2){
        cout<<"1";
        for(int i=1;i<m/7;i++){
            cout<<"8";
        }
        cout<<"8"<<endl;
        return 0;
    }
    if(m%7==3&&m!=3&&m!=10){
        cout<<"22";
        for(int i=2;i<m/7;i++){
            cout<<"8";
        }
        cout<<"8"<<endl;
        return 0;
    }
    if(m%7==4&&m!=4&&m!=11){
        cout<<"20";
        for(int i=2;i<m/7;i++){
            cout<<"8";
        }
        cout<<"8"<<endl;
        return 0;
    }
    if(m%7==5&&m!=5){
        cout<<"2";
        for(int i=1;i<m/7;i++){
            cout<<"8";
        }
        cout<<"8"<<endl;
        return 0;
    }
    if(m%7==6&&m!=6){
        cout<<"6";
        for(int i=1;i<m/7;i++){
            cout<<"8";
        }
        cout<<"8"<<endl;
        return 0;
    }
    int ans=0;
    int a[10];
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
    long long int j=1;
    while(true){
        long long int n=j;
        while(n>0){
            ans+=a[n%10];
            n/=10;
        }
        if(ans==m){
            cout<<j<<endl;
            return 0;
        }
        j++;
        ans=0;
    }
    return 0;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int a;
    cin>>a;
    int b[a];
    for(int i=0;i<a;i++){
        cin>>b[i];
    }
    for(int i=0;i<a;i++){
        s(b[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
