/*
    26. Remove Duplicates from Sorted Array
    Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
    The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set <int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int index = 0;
        for(auto it:s){
            nums[index] = it;
            index++;
        }
        return index;
    }
};

/*
    w.k.t set keeps unique values
    - insert the vector elements to a set 
    - keep index as 0 and nums[index] will be the iterators value (rewriting the nums)
    - increments the index which is the new nums.size() so we return the index;
*/