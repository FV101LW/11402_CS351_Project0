#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> TwoSumArray(const std::vector<int>& nums, int target) {
    for (size_t i = 0; i + 1 < nums.size(); ++i) {
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return {static_cast<int>(i), static_cast<int>(j)};
            }
        }
    }
    return {};
}

std::vector<int> ToSumHashTable(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> seen;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int complement = target - nums[i];
        auto it = seen.find(complement);
        if (it != seen.end()) {
            return {it->second, i};
        }
        seen[nums[i]] = i;
    }
    return {};
}

bool ReadTwoSumInput(std::vector<int>& nums, int& target) {
    int count;
    if (!(std::cin >> count)) {
        return false;
    }
    if (count < 0) {
        return false;
    }
    nums.resize(count);
    for (int i = 0; i < count; ++i) {
        std::cin >> nums[i];
    }
    std::cin >> target;
    return true;
}

bool ValidateTwoSumResult(const std::vector<int>& nums, int target, const std::vector<int>& result) {
    if (result.size() != 2) {
        return false;
    }
    int i = result[0];
    int j = result[1];
    if (i < 0 || j < 0 || i >= static_cast<int>(nums.size()) || j >= static_cast<int>(nums.size())) {
        return false;
    }
    if (i == j) {
        return false;
    }
    return nums[i] + nums[j] == target;
}

void RunTwoSumTests() {
    struct TestCase {
        std::vector<int> nums;
        int target;
    };

    const std::vector<TestCase> testCases = {
        {{2, 7, 11, 15}, 9},
        {{-3, 4, 1, 2}, -1},
        {{3, 3, 4}, 6},
        {{0, 4, 3, 0}, 0},
        {{1, 5}, 6},
    };

    for (const auto& test : testCases) {
        auto resultArray = TwoSumArray(test.nums, test.target);
        auto resultHash = ToSumHashTable(test.nums, test.target);

        if (!ValidateTwoSumResult(test.nums, test.target, resultArray)) {
            std::cerr << "TwoSumArray failed for target " << test.target << "\n";
        }
        if (!ValidateTwoSumResult(test.nums, test.target, resultHash)) {
            std::cerr << "ToSumHashTable failed for target " << test.target << "\n";
        }
    }
}