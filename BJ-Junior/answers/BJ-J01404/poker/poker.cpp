#include<iostream>
#include<vector>
using namespace std;

int main()
{
  freopen("poker.in","r",stdin);
  freopen("poker.out","w",stdout);
  int n,num;
  cin>>n;
  num=52-n;
  vector<string>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(a[i]==a[j]&&a[i]!="0")
      {
        num++;
        a[j]="0";
      }
    }
  }
  cout<<num<<endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}