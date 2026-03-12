# 11402_CS351_Project0
Project Null for CS351 (AI-Assisted Software Dev)
# Da Twosome Problem

## Problem Statement

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers that add up to the target. You may assume that each input has exactly one solution, and you cannot use the same element twice.

## Example

**Input:** `nums = [2, 7, 11, 15]`, `target = 9`  
**Output:** `[0, 1]`  
**Explanation:** `nums[0] + nums[1] = 2 + 7 = 9`

## Constraints

- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- Only one valid answer exists per input.

## Requirements

1. Provide 2 solution implementations (e.g., in different languages or using different approaches).
  - TwoSumArray: A direct array-based approach.
  - ToSumHashTable: A hash table-based approach using STL.

2. Each implementation must:
  - Accept an integer array and a target value.
  - Return the indices of the 2 matching elements.
  - Avoid using the same element twice.

3. Include test cases for:
  - Basic valid example.
  - Negative numbers.
  - Duplicate values.
  - Zero as part of the solution.
  - Small input sizes.

4. Add GitHub Actions for automated CI/CD (e.g., building and testing the code + trigger on pull & push request).

5. Add Docker support for containerizing the project.
  - Build the C++ project in a reproducible environment.
  - Run the test suite inside a container.

[2026/03/12]
Just write down something.