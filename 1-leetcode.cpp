/* 
***MY INITIAL SOLUTION**(Brute Force Approach)
int nums[] = {3, 2, 4};
int target = 6;

for (int i=0; i <= sizeof(nums); i++){

    for (int j=i + 1; j<sizeof(nums); j++){

        if (nums[i] + nums[j] == target){

            cout << "output = ["<< i << ", " << j << "]";
            return 0;
        }
    }

}
cout << "No outcome";
 */

/* 
//////SECOOND APPROACH Hash Map-Based://////////// */


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

    vector<int> twoSum(vector<int>& nums, int target){

        unordered_map<int, int> hashTable;           // define an unordered_map to store the integer and its index from the array
        for (int i = 0; i < sizeof(nums); i++){
            int complement = target - nums[i];       // calculate the complement, the number that if added to nums[i] will result in target.
            
            if (hashTable.count(complement)){        // check if the complement exist in the hashTable
                return {hashTable[complement], i};    // if it does return the two numbers indicies
            }

            hashTable[nums[i]] = i;                  // if not add the current number and its index to the hashtable
        }
    return {};    
    }

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "indecies: "<< result[0] << "," << result[1];
    } else{
        cout << "No numbers found to sum up to ``target` ";
    }
 return 0;
}
