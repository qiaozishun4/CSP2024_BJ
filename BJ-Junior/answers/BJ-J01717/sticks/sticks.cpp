#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin>>t;
    for(int c=1;c<=t;c++){
        int n;
        cin>>n;
        if(n==1) cout<<"-1"<<endl;
        else if(n==2) cout<<"1"<<endl;
        else if(n==3) cout<<"7"<<endl;
        else if(n==4) cout<<"4"<<endl;
        else if(n==5) cout<<"2"<<endl;
        else if(n==6) cout<<"6"<<endl;
        else if(n==7) cout<<"8"<<endl;
        else if(n==8) cout<<"10"<<endl;
        else if(n==9) cout<<"18"<<endl;

        else if(n==10) cout<<"22"<<endl;
        else if(n==11) cout<<"20"<<endl;
        else if(n==12) cout<<"28"<<endl;
        else if(n==13) cout<<"68"<<endl;
        else if(n==14) cout<<"88"<<endl;
        else if(n==15) cout<<"108"<<endl;
        else if(n==16) cout<<"188"<<endl;
        else if(n==17) cout<<"200"<<endl;
        else if(n==18) cout<<"208"<<endl;
        else if(n==19) cout<<"288"<<endl;

        else if(n==20) cout<<"688"<<endl;
        else if(n==21) cout<<"888"<<endl;
        else if(n==22) cout<<"1088"<<endl;
        else if(n==23) cout<<"1888"<<endl;
        else if(n==24) cout<<"2008"<<endl;
        else if(n==25) cout<<"2088"<<endl;
        else if(n==26) cout<<"2888"<<endl;
        else if(n==27) cout<<"6888"<<endl;
        else{
            if(n%7==1){
                cout<<"10";
                n-=8;
            }
            else if(n%7==2){
                cout<<"2000";
                n-=23;
            }
            else if(n%7==3){
                cout<<"200";
                n-=17;
            }
            else if(n%7==4){
                cout<<"20";
                n-=11;
            }
            else if(n%7==5){
                cout<<"2";
                n-=5;
            }
            else if(n%7==6){
                cout<<"6";
                n-=6;
            }

            for(int i=1;i<=n/7;i++)
            {
                cout<<"8";
            }cout<<endl;
        }
    }
    return 0;
}


