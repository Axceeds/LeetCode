#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i =0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        result.push_back({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }

        for(int i=0;i<result.size();i++){
            for(int j =i+1;j<result.size();){
                    if(result[i][0]==result[j][0]&&result[i][1]==result[j][1]&&result[i][2]==result[j][2]){
                        result.erase(result.begin()+j);
                    }
                    else{
                        j++;
                    }
            }
        }
        return result;

    }
};



int main(){
    Solution s;
    vector<int> v1={-1,-1,0,0,1,1,2};

    vector<vector<int>> v2 = s.threeSum(v1);
    for(int i=0;i<v2.size();i++){
        for(int j=0;j<v2[i].size();j++){
            cout<<v2[i][j]<<' ';
        }
        cout<<endl;
    }
    


    system("pause");
    return 0;
}
