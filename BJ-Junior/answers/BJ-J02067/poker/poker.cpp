#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt[14][5]={0};
    char a[4];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        //cout<<"A[0]:"<<a[0]<<endl;
        if(a[0]=='D'){
            if(a[1]=='T'){
                cnt[10][1]=1;
            }else if(a[1]=='A'){
                cnt[1][1]=1;
            }else if(a[1]=='J'){
                cnt[11][1]=1;
            }else if(a[1]=='Q'){
                cnt[12][1]=1;
            }else if(a[1]=='K'){
                cnt[13][1]=1;
            }else{
                cnt[a[1]-'0'][1]=1;
            }
        }else if(a[0]=='C'){
            //cout<<"in C"<<endl;
            if(a[1]=='T'){
                cnt[10][2]=1;
            }else if(a[1]=='A'){
                cnt[1][2]=1;
                //cout<<a<<endl;
                //cout<<"***"<<endl;
            }else if(a[1]=='J'){
                cnt[11][2]=1;
            }else if(a[1]=='Q'){
                cnt[12][2]=1;
            }else if(a[1]=='K'){
                cnt[13][2]=1;
            }else{
                cnt[a[1]-'0'][2]=1;
            }
        }else if(a[0]=='H'){
            if(a[1]=='T'){
                cnt[10][3]=1;
            }else if(a[1]=='A'){
                cnt[1][3]=1;
            }else if(a[1]=='J'){
                cnt[11][3]=1;
            }else if(a[1]=='Q'){
                cnt[12][3]=1;
            }else if(a[1]=='K'){
                cnt[13][3]=1;
            }else{
                cnt[a[1]-'0'][3]=1;
            }
        }else if(a[0]=='S'){
            if(a[1]=='T'){
                cnt[10][4]=1;
            }else if(a[1]=='A'){
                cnt[1][4]=1;
            }else if(a[1]=='J'){
                cnt[11][4]=1;
            }else if(a[1]=='Q'){
                cnt[12][4]=1;
            }else if(a[1]=='K'){
                cnt[13][4]=1;
            }else{
                cnt[a[1]-'0'][4]=1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(cnt[j][i]!=1){
                //cout<<"###"<<j<<" "<<i<<endl;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}