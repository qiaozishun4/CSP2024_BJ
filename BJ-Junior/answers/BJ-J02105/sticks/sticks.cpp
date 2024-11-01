#include<bits/stdc++.h>
using namespace std;
ifstream fin("sticks.in");
ofstream fout("sticks.out");
int main1(){
    /*
    0 6
    1 2
    2 5
    4 4
    6 6
    7 3
    8 7
    2 3 4 5 6 7
    1 7 4 2 6 8
    */
    long long a,b,c,d,e,f,g,h,n,i,w;
    fin>>n;
    w=(n-1)/7+1;
    int shu[8]={-1,-1,1,7,4,2,6,8};
    int zhuan[10]={6,2,5,5,4,5,6,3,7,6};
    if(n<=1){
        fout<<-1<<"\n";
        return 0;
    }
    if(n%7==0){
        for(a=1;a<=w;a++){
            fout<<8;
        }
    }
    else if(w==1){
        fout<<shu[n];
    }
    else {
        long long duandianjilu=0;
        for(a=1;a<=w;a++){
            if(a==1){
                if((w-a)*7<n-2){
                    if((w-a)*7<n-5){
                        if((w-a)*7<n-6){
                            duandianjilu=w;
                            break;
                        }
                        else {
                            fout<<6;
                            n-=6;
                        }
                    }
                    else {
                        fout<<2;
                        n-=5;
                    }
                }
                else {
                    fout<<1;
                    n-=2;
                }
            }
            else {
                if((w-a)*7<n-6){
                    duandianjilu=w-a+1;
                    break;
                }
                else {
                    fout<<0;
                    n-=6;
                }
            }
        }
        if(duandianjilu!=0){
            for(a=1;a<=duandianjilu;a++){
                fout<<8;
            }
        }
    }
    fout<<'\n';
    return 0;
}
int main(){
    long long a,t;
    fin>>t;
    for(a=1;a<=t;a++){
        main1();
    }
    return 0;
}