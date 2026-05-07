
# Acceptance Tests for Two Sum Implementation

## Purpose

Acceptance tests validate that the Two Sum implementations meet the specified requirements:
- Correctly find indices of two numbers that sum to target
- Handle edge cases gracefully
- Perform efficiently for large inputs
- Integrate properly with input/output functions

## Acceptance Criteria

### Functional Requirements
1. **Correctness**: Both TwoSumArray and TwoSumHashTable return valid indices where nums[i] + nums[j] == target
2. **No Solution**: Return empty vector when no pair sums to target
3. **Index Validity**: Returned indices are within array bounds and not equal
4. **Any Valid Pair**: Return any pair that satisfies the condition (not necessarily first)

### Performance Requirements
1. **Hash Table**: O(n) time complexity, suitable for large arrays
2. **Array Method**: O(n^2) time complexity, acceptable for small arrays
3. **Memory Usage**: Hash table uses O(n) space, array uses O(1) extra space

### Input/Output Requirements
1. **Input Format**: Read array size, elements, and target from stdin
2. **Output Format**: Print indices or "No solution found"
3. **Error Handling**: Handle invalid inputs gracefully

## Test Scenarios

### Scenario 1: Basic Functionality
- Input: 4\n2 7 11 15\n9
- Expected Output: Indices: 0 1

### Scenario 2: No Solution
- Input: 4\n1 2 3 4\n10
- Expected Output: No solution found

### Scenario 3: Edge Case - Empty Array
- Input: 0\n5
- Expected Output: No solution found

### Scenario 4: Large Input (Performance)
- Input: 10000 elements, target=sum of first and last
- Expected Output: Valid indices within 1 second

## Automated Testing

Acceptance tests are automated in the RunTwoSumTests() function and executed via GitHub Actions CI.
