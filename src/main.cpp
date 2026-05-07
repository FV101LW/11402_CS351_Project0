#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> TwoSumArray(const vector<int>& nums, int target) {
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

vector<int> TwoSumHashTable(const vector<int>& nums, int target) {
    unordered_map<int, int> seen;
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

bool ValidateTwoSumResult(
    const vector<int>& nums,
    int target,
    const vector<int>& result) {
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

void RunTest(
    const std::string& name,
    const std::vector<int>& nums,
    int target,
    const std::vector<int>& expected) {
    auto resultArray = TwoSumArray(nums, target);
    auto resultHash = TwoSumHashTable(nums, target);

    std::cout << "Test: " << name << "\n";
    std::cout << "  Input: [";
    for (size_t k = 0; k < nums.size(); ++k) {
        std::cout << nums[k];
        if (k + 1 < nums.size()) {
            std::cout << ", ";
        }
    }
    std::cout << "], target = " << target << "\n";

    std::cout << "  TwoSumArray result: [" << resultArray[0] << ", " << resultArray[1] << "]"
              << " -> " << (ValidateTwoSumResult(nums, target, resultArray) ? "PASS" : "FAIL") << "\n";
    std::cout << "  ToSumHashTable result: [" << resultHash[0] << ", " << resultHash[1] << "]"
              << " -> " << (ValidateTwoSumResult(nums, target, resultHash) ? "PASS" : "FAIL") << "\n";

    if (!expected.empty()) {
        std::cout << "  Expected indices example: [" << expected[0] << ", " << expected[1] << "]\n";
    }
    std::cout << "\n";
}

int main() {
    RunTest("Basic valid example", {2, 7, 11, 15}, 9, {0, 1});
    RunTest("Negative numbers", {-3, 4, 3, 90}, 0, {0, 2});
    RunTest("Duplicate values", {3, 3}, 6, {0, 1});
    RunTest("Zero as part of the solution", {0, 4, 3, 0}, 0, {0, 3});
    RunTest("Small input size", {1, 2}, 3, {0, 1});

    return 0;
}