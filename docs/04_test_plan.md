# Test Plan for Two Sum Implementation

## Introduction

This test plan outlines the testing strategy for the Two Sum problem implementations: TwoSumArray (brute force) and TwoSumHashTable (optimized hash table approach). The goal is to ensure both algorithms correctly find two indices whose elements sum to the target value.

### Purpose
- Validate correctness of both TwoSumArray and TwoSumHashTable functions
- Test edge cases and boundary conditions
- Ensure performance characteristics (O(n^2) for array, O(n) for hash table)
- Verify input validation and error handling

### Scope
- Unit tests for both algorithms
- Functional tests with various input scenarios
- Performance tests (basic timing)
- Integration with main program
- CI/CD testing via GitHub Actions

## Test Cases

### Functional Test Cases
1. **Basic Case**: [2,7,11,15], target=9 → [0,1]
2. **Negative Numbers**: [-3,4,1,2], target=-1 → [0,3]
3. **Duplicate Numbers**: [3,3,4], target=6 → [0,1]
4. **Zero Values**: [0,4,3,0], target=0 → [0,3]
5. **Small Array**: [1,5], target=6 → [0,1]
6. **No Solution**: [1,2,3,4], target=10 → []
7. **Empty Array**: [], target=5 → []
8. **Single Element**: [5], target=10 → []
9. **Large Target**: [1,2,3], target=5 → [1,2]
10. **All Negative**: [-1,-2,-3], target=-5 → [1,2]
11. **Large Numbers**: [1000000,2000000,3000000], target=3000000 → [0,2]

### Edge Cases
- Arrays with minimum size (0,1 elements)
- Arrays with maximum reasonable size (10^5 elements for hash table)
- Target values that are sums of first/last elements
- Target values not achievable
- Arrays with all identical elements
- Arrays with INT_MIN/INT_MAX values

## Testing Methodology

### Unit Testing
- Test each function independently
- Use assertions to verify return values
- Check for correct indices (0-based, valid range)
- Ensure no duplicate indices returned

### Performance Testing
- Measure execution time for large inputs
- Verify O(n^2) vs O(n) complexity
- Test with arrays of size 1000, 10000, 100000

### Integration Testing
- Test input reading function
- Test validation function
- Test main program flow

## Test Environment
- Compiler: g++ (GCC) 9.0+
- C++ Standard: C++11 or later
- Operating System: Linux/Windows/macOS
- Build system: Makefile or direct compilation

## Acceptance Criteria
- All functional test cases pass for both algorithms
- No crashes or undefined behavior
- Correct handling of edge cases
- Performance meets expectations
- Code compiles without warnings
- GitHub Actions CI passes
