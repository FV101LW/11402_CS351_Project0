#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function declarations
vector<int> TwoSumArray(const vector<int>& nums, int target);
vector<int> TwoSumHashTable(const vector<int>& nums, int target);
bool ValidateTwoSumResult(const vector<int>& nums, int target, const vector<int>& result);
bool RunTwoSumTests();

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

    std::cout << "  TwoSumArray result: ";
    if (resultArray.empty()) {
        std::cout << "No solution";
    } else {
        std::cout << "[" << resultArray[0] << ", " << resultArray[1] << "]";
    }
    std::cout << " -> " << (ValidateTwoSumResult(nums, target, resultArray) ? "PASS" : "FAIL") << "\n";

    std::cout << "  TwoSumHashTable result: ";
    if (resultHash.empty()) {
        std::cout << "No solution";
    } else {
        std::cout << "[" << resultHash[0] << ", " << resultHash[1] << "]";
    }
    std::cout << " -> " << (ValidateTwoSumResult(nums, target, resultHash) ? "PASS" : "FAIL") << "\n";

    if (!expected.empty()) {
        std::cout << "  Expected indices example: [" << expected[0] << ", " << expected[1] << "]\n";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "Running comprehensive test suite...\n";
    bool testsPassed = RunTwoSumTests();
    if (testsPassed) {
        std::cout << "All tests passed!\n";
        return 0;
    } else {
        std::cout << "Some tests failed!\n";
        return 1;
    }
}