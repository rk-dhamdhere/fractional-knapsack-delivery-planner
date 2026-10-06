# Smart Delivery Planning - Fractional Knapsack

## Student Details

- **PBLE Number:** 1
- **Roll Number:** 25102B0075
- **Name:** Rishikesh Dhamdhere

## Problem Description

A delivery company has a vehicle with a fixed carrying capacity and a set of packages. Each package has a weight and an associated profit. The goal is to maximize the total profit carried without exceeding the vehicle's capacity. Since a package can be divided, the algorithm may take all or a fraction of a package.

This C program solves the Fractional Knapsack problem with the greedy method. It calculates each package's profit-to-weight ratio, sorts packages in descending order of that ratio using bubble sort, and takes packages in that order until the vehicle is full. The menu lets the user enter package details, inspect and sort packages, calculate the maximum value, and display the selected portions.

## Build and Run

With GCC installed, compile and run from this directory:

```sh
gcc knapsack.c -o knapsack
./knapsack
```

On Windows, run the compiled program with:

```powershell
gcc knapsack.c -o knapsack.exe
.\knapsack.exe
```

Use the menu to enter package details, calculate ratios, sort packages, and find the maximum value. The program supports up to 100 packages.

## Time Complexity

| Step | Operation | Complexity |
| --- | --- | --- |
| Calculate profit/weight ratios | One pass over all packages | O(n) |
| Sort by ratio | Bubble sort | O(n^2) |
| Greedy selection | One pass over sorted packages | O(n) |
| **Overall** | Dominated by bubble sort | **O(n^2)** |

The ratio calculation and greedy selection are linear. Replacing bubble sort with a comparison sort such as merge sort could reduce the overall time complexity to O(n log n); bubble sort is used here for simplicity and consistency with the lab exercises.

## Conclusion

The Fractional Knapsack problem was solved using the greedy method by selecting packages in decreasing order of profit-to-weight ratio. A package is taken whole when it fits, or fractionally when only part of it fits in the remaining capacity. This strategy maximizes the value carried for the Fractional Knapsack problem. Unlike the 0/1 Knapsack problem, where packages cannot be divided and a greedy choice is not always optimal, the ratio-based greedy strategy is optimal when fractions are allowed. The menu-driven program implements package entry, ratio calculation, sorting, and value selection.