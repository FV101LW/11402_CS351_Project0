# 11402_CS351_Project0
Project Null for CS351 (AI-Assisted Software Dev)

## The Two Sum Problem

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers that add up to the target. You may assume that each input has exactly one solution, and you cannot use the same element twice.

### Example

**Input:** `nums = [2, 7, 11, 15]`, `target = 9`  
**Output:** `[0, 1]`  
**Explanation:** `nums[0] + nums[1] = 2 + 7 = 9`

### Constraints

- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- Only one valid answer exists per input.

## Implementations

This project provides two C++ implementations of the Two Sum problem:

1. **TwoSumArray**: Brute force approach with O(n²) time complexity
2. **TwoSumHashTable**: Optimized approach using unordered_map with O(n) time complexity

## Building and Testing

### Prerequisites
- C++ compiler (g++ recommended)
- C++11 or later standard support

### Build Instructions
```bash
cd src
g++ -std=c++11 -o two_sum_test main.cpp two_sum.cpp
```

### Run Tests
```bash
./two_sum_test
```

The test suite includes comprehensive test cases covering:
- Basic functionality
- Edge cases (empty array, single element, no solution)
- Negative numbers and large values
- Duplicate elements

### GitHub Actions CI/CD

The project uses GitHub Actions for automated testing. The workflow:
- Triggers on push and pull requests to main and test branches
- Compiles the C++ code
- Runs the test suite
- Reports pass/fail status

Workflow file: `.github/workflows/ci.yml`

## Project Structure

```
.
├── src/
│   ├── main.cpp          # Test driver and main function
│   └── two_sum.cpp       # Two Sum implementations
├── docs/
│   ├── 04_test_plan.md   # Detailed test plan
│   └── 05_acceptance_tests.md # Acceptance criteria
├── .github/
│   └── workflows/
│       └── ci.yml        # GitHub Actions workflow
└── README.md
```

## Documentation

- [Test Plan](docs/04_test_plan.md)
- [Acceptance Tests](docs/05_acceptance_tests.md)
- [Software Requirements Specification](docs/02_SRS.md)
- [Software Design Specification](docs/03_SDS.md)
  - Complete breakdown of YAML file
  - Triggers: Push and PR events on both main and planning branches.
  - Detailed 9-step job process with all the tools and commands.

2. Recommended CI Workflow Best Practices
  - Multi-language support in single workflow.
  - Container validation approach.
  - Cross-platform compatibility.
  - Automated triggers and version pinning.
  - Comprehensive testing strategy.

3. Workflow Status Badge
  - Ready-to-use markdown code for adding CI/CD status badges.
  - Links for monitoring both main & current branch workflows.

## Deployment

Deployment of the Two Sum Problem solution involves building and running the C++ implementations (array-based and hash table-based approaches) in production or testing environments. This process ensures the algorithms work correctly, are optimized for performance, and can be containerized for reproducibility.

### Key Considerations

- **Building the Code**: Compile the C++ source files using a C++ compiler (e.g., g++). Ensure dependencies like STL are available.
- **Environment Setup**: Use Docker for containerized builds to maintain consistency across different systems.
- **Testing & Validation**: Run the provided test cases to verify correctness, including edge cases like negative numbers and duplicates.
- **Performance Monitoring**: Track execution time and memory usage, especially for large inputs (up to 10^4 elements).
- **CI/CD Integration**: Use GitHub Actions for automated building, testing, and deployment on push/PR events.
- **Containerization**: Build Docker images that include the compiled binaries and run the test suite inside containers.
- **Version Control**: Tag releases and manage different versions of the solution implementations.