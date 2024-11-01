#include<bits/stdc++.h>
using namespace std;
long long a[10];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long b;
    cin>>b;
    for(long long q=0;q<b;q++){
        long long c;
        cin>>c;
        if(c==1){
            cout<<"-1";
        }while(1){
            if(c>=15){
                c-=7;
                a[8]++;
            }else{
                break;
            }
        }
        if(c==14){
            a[8]++;a[8]++;
        }else if(c==13){
            a[8]++;a[0]++;
        }else if(c==12){
            a[8]++;a[2]++;
        }else if(c==11){
            a[2]++;a[0]++;
        }else if(c==10){
            a[2]++;a[2]++;
        }else if(c==9){
            a[1]++;a[8]++;
        }else if(c==8){
            a[1]++;a[0]++;
        }else if(c==7){
            a[8]++;
        }else if(c==6){
            a[0]++;
        }else if(c==5){
            a[2]++;
        }else if(c==4){
            a[4]++;
        }else if(c==3){
            a[7]++;
        }else if(c==2){
            a[1]++;
        }

        if(a[0]>=1){
            if(a[1]>0){
                cout<<1;
                a[1]--;
            }else if(a[2]>0){
                cout<<2;
                a[2]--;
            }else if(a[3]>0){
                cout<<3;
                a[3]--;
            }else if(a[4]>0){
                cout<<4;
                a[4]--;
            }else if(a[5]>0){
                cout<<5;
                a[5]--;
            }else if(a[6]>0){
                cout<<6;
                a[6]--;
            }else if(a[7]>0){
                cout<<7;
                a[7]--;
            }else if(a[8]>0){
                cout<<8;
                a[8]--;
            }else if(a[9]>0){
                cout<<9;
                a[9]--;
            }else{
                cout<<6;
                a[0]--;
            }
        }for(long long i=0;i<=9;i++){
            for(long long j=0;j<a[i];j++){
                cout<<i;
            }
            a[i]=0;
        }cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
	return 0;
}
