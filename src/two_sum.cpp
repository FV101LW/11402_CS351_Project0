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

std::vector<int> TwoSumHashTable(const std::vector<int>& nums, int target) {
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

bool RunTwoSumTests() {
    struct TestCase {
        std::vector<int> nums;
        int target;
    };

    const std::vector<TestCase> testCases = {
        {{2, 7, 11, 15}, 9},      // Basic case
        {{-3, 4, 1, 2}, -1},      // Negative numbers
        {{3, 3, 4}, 6},           // Duplicate numbers
        {{0, 4, 3, 0}, 0},        // Zero values
        {{1, 5}, 6},              // Small array
        {{1, 2, 3, 4}, 10},       // No solution
        {{}, 5},                  // Empty array
        {{5}, 10},                // Single element
        {{1, 2, 3}, 5},           // Large target
        {{-1, -2, -3}, -5},       // All negative
        {{1000000, 2000000, 3000000}, 3000000}, // Large numbers
    };

    bool allPassed = true;
    for (const auto& test : testCases) {
        auto resultArray = TwoSumArray(test.nums, test.target);
        auto resultHash = TwoSumHashTable(test.nums, test.target);

        bool arrayValid = ValidateTwoSumResult(test.nums, test.target, resultArray);
        bool hashValid = ValidateTwoSumResult(test.nums, test.target, resultHash);

        if (!arrayValid) {
            std::cerr << "TwoSumArray failed for target " << test.target << "\n";
            allPassed = false;
        }
        if (!hashValid) {
            std::cerr << "TwoSumHashTable failed for target " << test.target << "\n";
            allPassed = false;
        }
    }
    return allPassed;
}