#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > retvec;

        if (nums.size() <= 2)
            return retvec;

        sort(nums.begin(), nums.end());

        for (int i = nums.size() - 1; i > 1; --i) {
            if (i < nums.size() -1 && nums.at(i) == nums.at(i + 1))
                continue;

            twoSum(nums, i, -nums.at(i), retvec);
        }

        return retvec;
    }

    void twoSum(vector<int>& nums, int top, int target, vector<vector<int> >& retvec) {
        int begin = 0;
        int end = top - 1;

        while (begin < end) {
            if (nums.at(begin) + nums.at(end) == target) {
                vector<int> tmp;
                tmp.push_back(nums.at(begin));
                tmp.push_back(nums.at(end));
                tmp.push_back(nums.at(top));
                retvec.push_back(tmp);

                while(begin + 1 <= top && nums.at(begin) == nums.at(begin + 1))
                    begin++;
                while(end - 1 >= 0 && nums.at(end) == nums.at(end - 1))
                    end--;

                begin++;
                end--;
            } else if (nums.at(begin) + nums.at(end) < target) {
                while(begin + 1 <= top && nums.at(begin) == nums.at(begin + 1))
                    begin++;
                begin++;
            } else {
                while(end - 1 >= 0 && nums.at(end) == nums.at(end - 1))
                    end--;
                end--;
            }
        }
    }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int nums[] = {7,-10,7,3,14,3,-2,-15,7,-1,-7,6,-5,-1,3,-13,6,-15,-10,14,8,5,-10,-1,1,1,11,6,8,5,-4,0,3,10,-12,-6,-2,-6,-6,-10,8,-5,12,10,1,-8,4,-8,-8,2,-9,-15,14,-11,-1,-8,5,-13,14,-2,0,-13,14,-12,12,-13,-3,-13,-12,-2,-15,4,8,4,-1,-6,11,11,-7,-12,-2,-8,10,-3,-4,-6,4,-14,-12,-5,0,3,-3,-9,-2,-6,-15,2,-11,-11,8,-11,8,-7,8,14,-5,4,10,3,-1,-15,10,-6,-11,13,-5,1,-15}
  vector<int> myVec;
  int len = sizeof(nums) / sizeof (int);
  myVec.insert(myVec.begin(), nums, nums + len);
  vector<vector<int> > tmp = s.threeSum(myVec, target);
  for (size_t i = 0; i < tmp.size(); i++) {
    for (size_t j = 0; j < tmp.at(i).size(); j++) {
      cout << tmp.at(i).at(j) << endl;
    }
    cout << endl;
  }
  return 0;
}
