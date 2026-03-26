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

## GitHub Actions CI/CD Details:
1. Workflow Configuration Details
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