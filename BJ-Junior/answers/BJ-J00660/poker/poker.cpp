#include <bits/stdc++.h>


using namespace std;

int main(){

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    int a[4][14]={0};//0D,1C,2H,3S
    //A23456789TJQK
    char tmph,tmps,nh,ns;
    for(int i=1;i<=n;i++){
        cin >> tmph >> tmps;
        if(tmph=='D'){  //huasepanduan
            nh=0;
        }else if(tmph=='C'){
            nh=1;
        }else if(tmph=='H'){
            nh=2;
        }else if(tmph=='S'){
            nh=3;
        }

        if(tmps=='A'){  //shuzipanduan
            ns=1;
        }else if(tmps=='2'){
            ns=2;
        }else if(tmps=='3'){
            ns=3;
        }else if(tmps=='4'){
            ns=4;
        }else if(tmps=='5'){
            ns=5;
        }else if(tmps=='6'){
            ns=6;
        }else if(tmps=='7'){
            ns=7;
        }else if(tmps=='8'){
            ns=8;
        }else if(tmps=='9'){
            ns=9;
        }else if(tmps=='T'){
            ns=10;
        }else if(tmps=='J'){
            ns=11;
        }else if(tmps=='Q'){
            ns=12;
        }else if(tmps=='K'){
            ns=13;
        }

        a[nh][ns]=1;
    }
    int ans=0;
    for(int i=0;i<=3;i++){
        for(int j=1;j<=13;j++){
            if(a[i][j]==0){
                ans+=1;
            }
            //printf("%d ",a[i][j]);
        }
        //printf("\n");
    }
    cout << ans;
    return 0;
}
