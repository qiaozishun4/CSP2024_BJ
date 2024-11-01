#include <iostream>
using namespace std;
int st[11]={6,2,5,5,4,5,6,3,7,6};
long long szh(int m){
    long long sum=0;
    while(m!=0){
        sum+=st[m%10];
        m/=10;
    }
    return sum;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long t,k;
    cin>>t;
    for(long long i=0,kkk=0;i<t;i++){
        cin>>k;
        if(k<14){
            if(k%7==0){
                for(long long iii=0;iii<k/7;iii++){
                    cout<<8;
                }
                cout<<endl;
                continue;
            }
            while(1){
                kkk++;
                if(k<2){
                    cout<<-1<<endl;
                    break;
                }
                if(szh(kkk)==k){
                    cout<<kkk<<endl;
                    break;
                }
            }
            kkk=0;
        }else{
            if(k%7==0){
                for(long long iii=0;iii<k/7;iii++){
                    cout<<8;
                }
                cout<<endl;
            }else if(k%7==1){
                cout<<"10";
                for(long long iii=1;iii<k/7;iii++){
                    cout<<8;
                }
                cout<<endl;
            }else if(k%7==2){
                cout<<"1";
                for(long long iii=0;iii<k/7;iii++){
                    cout<<8;
                }
                cout<<endl;
            }else if(k%7==3){
                cout<<"200";
                for(long long iii=2;iii<k/7;iii++){
                    cout<<8;
                }
                cout<<endl;
            }else if(k%7==4){
                cout<<"20";
                for(long long iii=1;iii<k/7;iii++){
                    cout<<8;
                }
                cout<<endl;
            }else if(k%7==5){
                cout<<"2";
                for(long long iii=0;iii<k/7;iii++){
                    cout<<8;
                }
                cout<<endl;
            }else if(k%7==6){
                cout<<"6";
                for(long long iii=0;iii<k/7;iii++){
                    cout<<8;
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
