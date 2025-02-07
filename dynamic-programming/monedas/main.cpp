#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long MAX = 10e9+9;
int main()
{
    long long monedas,cambio;
    cin>>monedas>>cambio;

    vector<int> Mmonedas(monedas);

    for(int i=0;i<monedas;i++){
        cin>>Mmonedas[i];
    }
    vector<vector<int>> dp (monedas+1,vector<int>(cambio+1,0));

    for(int i=1;i<=cambio;i++){
        dp[0][i]=MAX;
    }

    for(int i=1;i<=monedas;i++){
            cout<<endl;
        for(int j=1;j<=cambio;j++){
            if(Mmonedas[i-1]<=j){
                dp[i][j]=min(dp[i-1][j],(dp[i][j-Mmonedas[i-1]])+1);
            }else{
                dp[i][j]=dp[i-1][j];
            }
            cout<<dp[i][j]<<" ";
        }
    }
    return 0;
}
