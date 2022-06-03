//
//  main.cpp
//  PERMUTATION-WITHOUT DUPLICATS
//
//  Created by Nishan gautam on 6/3/22.
//

#include <iostream>
#include<vector>
#include<map>

using namespace std;

void helper(vector<int>& nums, vector<int>& perm, vector<vector<int>>& result, map<int, int> temp) {
    if (perm.size() == nums.size())
    {
        result.push_back(perm);
        return;
        
    }
    
    
    for (auto i: temp)
    {
        if(i.second > 0)
        {
            perm.push_back(i.first);
            temp[i.first]-=1;
            
            helper(nums, perm, result, temp);
            
            perm.pop_back();
            temp[i.first] +=1;
        }
    }
}


vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> perm;
    map<int, int> count;
    for (auto i : nums) {
        count[i]++;
    }
    helper(nums, perm, res, count);
    
    return res;
}

int main()
{
    cout<<"Hello World\n";
    vector<int> nums {1,1,2};
    permute(nums);
    
    

    return 0;
}
