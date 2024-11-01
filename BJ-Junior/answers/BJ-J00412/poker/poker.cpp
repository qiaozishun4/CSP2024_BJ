#include<bits/stdc++.h>
using namespace std;
string s[52];
int a[52][2],n;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        if(s[i][1]-'0'<=9&&s[i][1]-'0'>=0){
            switch(s[i][0]){
                case'D':{
                    a[i][0]=1;
                    break;
                }
                case'C':{
                    a[i][0]=2;
                    break;
                }
                case'H':{
                    a[i][0]=3;
                    break;
                }
                case'S':{
                    a[i][0]=4;
                    break;
                }
            }
            a[i][1]=s[i][1]-'0';
        }
        else{
            switch(s[i][0]){
                case'D':{
                    a[i][0]=1;
                    break;
                }
                case'C':{
                    a[i][0]=2;
                    break;
                }
                case'H':{
                    a[i][0]=3;
                    break;
                }
                case'S':{
                    a[i][0]=4;
                    break;
                }
            }
            switch(s[i][1]){
                case'T':{
                    a[i][1]=10;
                    break;
                }
                case'J':{
                    a[i][1]=11;
                    break;
                }
                case'Q':{
                    a[i][1]=12;
                    break;
                }
                case'K':{
                    a[i][1]=13;
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(a[j][1]>a[j+1][1]){
                swap(a[j][1],a[j+1][1]);
                swap(a[j][0],a[j+1][0]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(a[j][0]>a[j+1][0]){
                swap(a[j][0],a[j+1][0]);
                swap(a[j][1],a[j+1][1]);
            }
        }
    }
    int cnt=n;
    for(int i=0;i<n-1;i++){
        if(a[i][0]==a[i+1][0]&&a[i][1]==a[i+1][1])cnt--;
    }
    cout<<52-cnt;
    return 0;
}
