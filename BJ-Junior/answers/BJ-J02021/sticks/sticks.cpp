#include<bits/stdc++.h>
using namespace std;
int sticks(int n){
    if(n==1){
        return -1;
    }
    else if(n%2==0){
        return 1;
        }
    else if(n%5==0){
        return 2;
        }
    else if(n%4==0){
        return 4;
        }
    else if(n%6==0){
        return 6;
        }
    else if(n%3==0){
        return 7;
        }
    else if(n%7==0){
        return 8;
        }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int T;
    cin>>T;
    int n;
    for (int i=0;i<T;i++){
        cin>>n;
        int a=sticks(n);
        cout<<a<<endl;
    }



    fclose(stdin);
    fclose(stdout);
}
