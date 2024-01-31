/*
    goal is to generate all the valid paranthesis when the n is given
*/
#include<bits/stdc++.h>
using namespace std;

vector<string> result;
void generate(string &s, int open, int close){
    if(open>0){
        s.push_back('(');
        generate(s,open-1,close);
        s.pop_back(); // for back tracking purpose
    }
    if(close>0){
        if(open<close){ // if open> close then we put '(' bracket.....else we put ')'
            s.push_back(')');
            generate(s,open,close-1);
            s.pop_back();
        }
    }
    if(open == 0 && close == 0){
        result.push_back(s);
        return;
    }
}

/*
    we used recursion here
    - passing the string by reference to avoid the copy
    - open is ( close is ) values in int....initially the number n lets say 3
    - if open count is > 0 we push ( into a string
        - function calls it self by decrementing '(' count since we consumed one
            - recursive call happens and reach a point where open=0 (((
            - executes the close > 0 condition after
                - push ) 
                - when close and open both are 0
                    - push the entire string to a result vector
                    - pop_backs later {here back tracking occurs to return the string to the its previous state}
*/
int main(){
    string s;
    int n;cin>>n;
    generate(s,n,n);
    for(auto it:result){
        cout<<it<<endl;
    }
    cout<<result.size();
    return 0;
}