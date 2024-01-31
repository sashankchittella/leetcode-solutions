/*
    Given an array nums of size n, return the majority element.

    The majority element is the element that appears more than ⌊n / 2⌋ times.
    You may assume that the majority element always exists in the array.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            int x = it.second;
            if(x>nums.size()/2){
                return it.first;
            }
        }
        return 0;
    }
};

/*
    maps the elements of vector to their frequency;
    and run a iterator such that when it.second (the frequency count) matches with ⌊n / 2⌋
    the return the corresponding it.first
*/