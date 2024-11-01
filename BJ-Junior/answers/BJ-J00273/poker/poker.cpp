#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int a[13][4]={0};
    for(int i=0;i<n;i++){
        char h[2];
        cin>>h[1]>>h[2];
        if(h[2]=='A'){
            h[2]='1';
        }
        if(h[2]=='T'){
            if(h[1]=='D'){
                a[9][0]++;
            }
            if(h[1]=='C'){
                a[9][1]++;
            }
            if(h[1]=='H'){
                a[9][2]++;
            }
            if(h[1]=='S'){
                a[9][3]++;
            }
        }else if(h[2]=='J'){
            if(h[1]=='D'){
                a[10][0]++;
            }
            if(h[1]=='C'){
                a[10][1]++;
            }
            if(h[1]=='H'){
                a[10][2]++;
            }
            if(h[1]=='S'){
                a[10][3]++;
            }
        }else if(h[2]=='Q'){
            if(h[1]=='D'){
                a[11][0]++;
            }
            if(h[1]=='C'){
                a[11][1]++;
            }
            if(h[1]=='H'){
                a[11][2]++;
            }
            if(h[1]=='S'){
                a[11][3]++;
            }
        }else if(h[2]=='K'){
            if(h[1]=='D'){
                a[12][0]++;
            }
            if(h[1]=='C'){
                a[12][1]++;
            }
            if(h[1]=='H'){
                a[12][2]++;
            }
            if(h[1]=='S'){
                a[12][3]++;
            }
        }else{
            if(h[1]=='D'){
                a[h[2]-48][0]++;
            }
            if(h[1]=='C'){
                a[h[2]-48][1]++;
            }
            if(h[1]=='H'){
                a[h[2]-48][2]++;
            }
            if(h[1]=='S'){
                a[h[2]-48][3]++;
            }
        }
    }int sum=0;
    for(int i=0;i<13;i++){
        for(int j=0;j<4;j++){
            if(a[i][j]==0){
                sum++;
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
return 0;
}