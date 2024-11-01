#include <iostream>
using namespace std;
string a;
char p[2][100];
char num[2][100];
int n;
int sum=0;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","W",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[1][i];
        cin>>num[1][i];
        sum++;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(p[1][i]==p[1][j]&num[1][i]==num[1][j]){
                sum--;
            }

        }
    }
    cout<<52-sum<<endl;
    return 0;
}
