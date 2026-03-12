#include <iostream>
#include <vector>
#include <unordered_map>

class TwoSum {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        throw std::invalid_argument("No two sum solution");
    }
};

int main() {
    TwoSum solution;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = solution.twoSum(nums, target);
    std::cout << "Indices: [" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}