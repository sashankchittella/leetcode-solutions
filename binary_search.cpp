#include<bits/stdc++.h>
using namespace std;

int Binary_search(vector<int> &v,int x){
    int low = 0;
    int high = v.size()-1;
    int mid;
    while(high-low > 1){
        mid = (high+low)/2;
        if(v[mid]<x){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    if(v[low]==x) return low;
    else if(v[high]==x) return high;
    else return -1;
}
int main(){
    vector<int> v ={1,2,3,4,5,6,7,8};
    int x; cin>>x;
    cout<<"the index is at : "<<Binary_search(v,x);
    return 0;
}