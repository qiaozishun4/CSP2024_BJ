#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    int n,tmp[100010],cnt=1, ans,tmp2[100010];
    int r[100010];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>r[i];


    }
    sort(r,r+n);
    tmp[0]=0;
    for(int i=0,j=0;i<n;i++){

        tmp[j]++;
        if(r[i]==r[i+1]) {

            tmp[j]++;


        }

        else {
            if(i<n-1) {
                j++;
                tmp[j]==0;
                cnt++;
            }




        }

    }

    for(int j=0;j<cnt;j++){

        int ans=tmp[j];

        if(tmp[j]<=tmp[j+1]){

            ans=tmp[j+1];

        }
        else{
            ans=tmp[j];

        }

    }


    if(n-cnt==1) cout<<2;
    else if(n-cnt==0) cout<<1;
    else cout<<n-cnt;




    return 0;
}
