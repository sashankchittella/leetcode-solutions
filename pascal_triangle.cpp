#include<bits/stdc++.h>
using namespace std;

int NcR(int n,int r){
    int res = 1;
    for(int i=0;i<r;i++){
        res = res * (n-i);
        res = res/(i+1);
    }
    return res;
}

void rowgen(int n){
    int ans = 1;
    cout<<ans<<" ";
    for(int i=1;i<n;i++){
        ans = ans *(n-i);
        ans = ans / i;
        cout<<ans<<" ";
    }
    cout<<endl;
    return;
}

void pascal(int n){
    for(int i=1;i<=n;i++){
        rowgen(i);
    }
}

int main(){
    int n;cin>>n;
    pascal(n);
    // rowgen(n);
    return 0;
}