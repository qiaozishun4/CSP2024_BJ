#include<bits/stdc++.h>
using namespace std;
int n;
bool a[9][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char s1,s2;
        string df;//cout<<"rt";
        cin>>df;
             ///DCHS              ATJQK
        s1=df[0];
        s2=df[1];
        int e,e8;
        //cout<<'g';
        if(s1=='D'){
            e=1;
        }
        if(s1=='C'){
            e=2;
        }
        if(s1=='H'){
            e=3;
        }
        if(s1=='S'){
            e=4;
        }
        if(s2<='9'&&s2>='0'){
            e8=s2-'0';
        }

        if(s2=='A'){
            e8=1;
        }
        if(s2=='T'){
            e8=10;
        }
        if(s2=='J'){
            e8=11;
        }
        if(s2=='Q'){
            e8=12;
        }
        if(s2=='K'){
            e8=13;
        }
        a[e][e8]=true;
        //cout<<'e';
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==false){
                ans++;
                //cout<<i<<" "<<j;
            }
        }
    }
    cout<<ans;
    return 0;
}