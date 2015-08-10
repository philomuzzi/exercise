class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        if (size < 3)
            return 0;

        sort(nums.begin(), nums.end());
        int value = nums.at(0) + nums.at(1) + nums.at(2);

        for (int i = 0; i < size - 2; ++i) {
            if (i > 0 && nums.at(i) == nums.at(i - 1))
                continue;

            int tmp = twoSum(nums, i, target);
            if (tmp == target)
                return tmp;
            else if (abs(tmp-target) < abs(value-target))
                value = tmp;
        }

        return value;
    }

    int twoSum(vector<int>& nums, int bottom, int target) {
        int begin = bottom + 1;
        int end = nums.size() - 1;

        int value = nums.at(begin) + nums.at(end) + nums.at(bottom);
        int tmp = 0;

        while (begin < end) {
            tmp = nums.at(begin) + nums.at(end) + nums.at(bottom);
            if (tmp == target) {
                return tmp;
            }

            if (abs(tmp - target) < abs(value - target))
                value = tmp;

            if (tmp < target) {
                while (begin + 1 < end && nums.at(begin) == nums.at(begin + 1))
                    begin++;
                begin++;
            } else {
                while (end - 1 > begin && nums.at(end) == nums.at(end - 1))
                    end--;
                end--;
            }
        }

        return value;
    }
};
