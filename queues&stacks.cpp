//  implements stacks and queues using each other
#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q1,q2;
public:
    void push(int x){
        q2.push(x); // push elements to q2
        while(!q1.empty()){ // push all the elements of q1 to q2
            q2.push(q1.front());
            q1.pop();
        }
        //swap queues names q1<-->q2
        queue<int> temp = q2;
        q2=q1;
        q1=temp; 
    }
    
    void pop(){
        if(q1.empty()) return;
        q1.pop();
    }
    int top(){
        if(q1.empty()) return -1;
        return q1.front(); 
    }
    int size(){
        return q1.size();
    }
};

class Queue{
    stack<int> s1,s2;
public:
    void enqueue(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    /*
        enqueue --> initially empty s1 and store in s2; 
                --> push new element then to s2;
                --> empty all the s2 and store in s1
    */
    int dequeue(){
        if(s1.empty()) return -1;
        int x = s1.top();
        s1.pop();
        return x;
    }

    int size(){
        if(s1.empty()) return -1;
        return s1.size();
    }

};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top()<<endl;s.pop();
    cout<<s.top()<<endl;s.pop();
    cout<<s.top()<<endl;s.pop();
    cout<<endl;
    
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    return 0;
}
