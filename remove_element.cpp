/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, 
you need to do the following things:

- Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 
- The remaining elements of nums are not important as well as the size of nums.
- Return k.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(auto it = nums.begin();it!=nums.end();){
            if(*it==val){
                it = nums.erase(it);
                continue;
            }
            it++;
        }
        return nums.size();
    }
};
/*
    val should be erased and elements should be shifted 
    whenever iterator matches with the value it erases and continues
    but iterator cannot be increment in for loop further after removing the element
    thats the reason to increment it inside the loop
*/
