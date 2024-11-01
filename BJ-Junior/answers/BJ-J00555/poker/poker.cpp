#include<bits/stdc++.h>
using namespace std;
bool a[10][17];
int f(char x){
    if(x=='D'||x=='A')return 1;
    if(x=='C'||x=='2')return 2;
    if(x=='H'||x=='3')return 3;
    if(x=='S'||x=='4')return 4;
    if(x=='5'||x=='6'||x=='7'||x=='8'||x=='9')return x-'0';
    if(x=='T')return 10;
    if(x=='J')return 11;
    if(x=='Q')return 12;
    if(x=='K')return 13;

}

int main (){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;
    char l1,l2;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l1>>l2;
        if(a[f(l1)][f(l2)]==false){
            a[f(l1)][f(l2)]=true;
            ans++;
        }
    }
    cout<<52-ans;
}
