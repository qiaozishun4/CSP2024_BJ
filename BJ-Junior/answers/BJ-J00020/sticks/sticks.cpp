#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,numbers[1026]={6,2,5,5,4,5,6,3,7,6};
    cin >> t;
    for(int k=1;k<=t;k++){
        int n;
        cin >> n;
        int sum=0,flag=true;
        int sss=n*100;
        for(int i=1;i<=sss;i++){sum=0;
            int a[1005],pos=0,num=i;
            while(num){pos++;
                a[pos]=num%10;
                num/=10;
            }
            int mmm=0;
            for(int j=pos;j>=1;j--){
                if(a[j]!=0)mmm=1;
                if(mmm)sum+=numbers[a[j]];
            }
            if(n==sum){
                cout << i;
                flag=false;
                break;
            }//cout << sum <<" " <<i <<"n";


        }if(flag)cout << -1;
        cout << "\n";
    }
    fclose(stdin);
    fclose(stdout);
}

