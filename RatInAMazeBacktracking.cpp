#include<bits/stdc++.h>
using namespace std;
int MAP[50][50],sol[50][50];
int N=50;
bool issafe(int i,int j)
{
    return (i<N && j<N && MAP[i][j]==1);
}
bool ratsolverec(int i,int j)
{
    if(i==N-1 && j==N-1){
      sol[i][j]=1;
      return true;
    } 
     if(issafe(i,j))
     {
         sol[i][j]=1;
         if(ratsolverec(i+1,j)==true) return true;
         else if(ratsolverec(i,j+1)== true) return true;
         sol[i][j]=0;
     }
     return false;
    
}
bool solve()
{
    if(ratsolverec(0,0)==true)
        return true;
    return false;
}


int main()
{   
    N=3;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>MAP[i][j];
    solve();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<sol[i][j]<<" ";
        cout<<endl;
    }
        
    
    return 0;
}
