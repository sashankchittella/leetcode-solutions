#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    
public:
    Node(int x, Node* y){
        val = x;
        next = y;
    }
    Node(int x){
        val = x;
        next = nullptr;
    }
};

// detection of loop using tortoise and hare
bool hasCycle(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while(fast!= NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }
    return false;
}

// if theres a loop then find the length of loop in a linked list
int Loop(Node *slow, Node* fast){
    int cnt = 1;
    fast = fast->next;
    while(slow!=fast){
        cnt++;
        fast = fast->next;
    }
    return cnt;
}

int lengthOfLoop(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return Loop(slow,fast);
    }
    return 0;
}

// find the position of the loop starting node
Node *detectCycle(Node *head) {
        Node *slow = head;
        Node *fast = head;
        int c=0;
        while(fast!=NULL and fast->next!= NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;

    }

// segregate odd even
Node* odd_even(Node *head){
	
	Node *current = head;
	Node *odd_start = NULL;
	Node *even_start = NULL;
	Node *odd_end = NULL;
	Node *even_end= NULL;
	int count = 1;
	while(current!=NULL){
// 		int val = current->val;
		if(count%2 == 1){
			if(odd_start == NULL){
				odd_start = odd_end =current;
				// odd_end = odd_start;
			}
			else{
				odd_end->next = current;
				odd_end = odd_end->next;
			}
		}
		else{
			if(even_start == NULL){
				even_start = even_end =current;
				// even_end = even_start;
			}
			else{
				even_end->next = current;
				even_end = even_end->next;
			}
		}
		current = current->next;
		count++;
	}	
	
	odd_end->next = even_start;
	even_end->next = NULL;
	head = odd_start;
	
	return head;
}

// midpoint of Linked list
Node* mid(Node* head){
	Node* slow = head;
	Node* fast = head;
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	// cout<<slow->val<<" ";
	return slow;
}

