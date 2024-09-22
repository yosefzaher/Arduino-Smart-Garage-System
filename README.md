# Algorithm Repository

This repository contains various algorithms, including sorting, searching, divide and conquer, greedy, and Huffman coding algorithms. Each algorithm includes a performance evaluation and time complexity analysis.

## Sorting Algorithms

## Insertion Sort

### Introduction

Insertion Sort is a simple and efficient sorting algorithm that builds the final sorted array one item at a time. It is an in-place comparison-based algorithm and works well for small datasets or nearly sorted datasets.

### How it Works

1. *Start with the second element:* Assume the first element is already sorted. Start the sorting process with the second element of the array.
2. *Compare and Insert:* Compare the second element with the first element. If the second element is smaller, swap them. Now, the first two elements are sorted.
3. *Extend the sorted portion:* Move to the third element. Compare it with the elements in the sorted portion (from left to right) and insert it at the correct position within the sorted portion.
4. *Repeat:* Continue this process for all elements in the array until the entire array is sorted.

### Algorithm Steps

1. *Start Loop:* Start a loop from the second element (index 1) to the last element (index n-1) of the array.
2. *Select Key:* Select the current element as the key to be inserted into the sorted portion.
3. *Compare and Shift:* Compare the key with the elements in the sorted portion (from right to left). If an element is greater than the key, shift it one position to the right.
4. *Insert Key:* Insert the key into its correct position in the sorted portion.
5. *Repeat:* Repeat steps 2-4 until all elements are sorted.

### Example

Let's sort an array [5, 2, 4, 6, 1, 3] using Insertion Sort:

- Start with the second element (2).
- Compare 2 with 5 (first element), as 2 is smaller, swap them: [2, 5, 4, 6, 1, 3].
- Now, consider the third element (4).
- Compare 4 with elements in the sorted portion (5, 2). As 4 is greater than 2 and smaller than 5, insert it between them: [2, 4, 5, 6, 1, 3].
- Continue this process for all elements until the array is sorted: [1, 2, 3, 4, 5, 6].

### Complexity Analysis

- *Time Complexity:*
  - Best Case: O(n) - When the array is already sorted.
  - Worst Case: O(n^2) - When the array is sorted in reverse order.
  - Average Case: O(n^2)
- *Space Complexity:* O(1) - It sorts the array in-place without requiring additional space other than a few variables.

### Advantages

- Simple implementation.
- Efficient for small datasets or nearly sorted datasets.
- In-place sorting algorithm with space complexity of O(1).

### Disadvantages

- Not suitable for large datasets due to its quadratic time complexity.
- Performance degrades significantly for inversely sorted or nearly inversely sorted datasets.

### Conclusion

Insertion Sort is a straightforward sorting algorithm that builds the sorted array incrementally by inserting each element into its correct position in the already sorted portion of the array. While it may not be the most efficient for large datasets, it is easy to implement and works well for small or nearly sorted datasets.

<p align="center"><img src="https://miro.medium.com/v2/resize:fit:1400/format:webp/0*81Yk_fwfCB3iCwRP.png" alt="project-image"></p>

### Merge Sort

Merge Sort is a divide-and-conquer algorithm that divides the input array into two halves, sorts each half recursively, and then merges the sorted halves to produce a sorted array. It is a stable sorting algorithm and works efficiently for large datasets.

### How it Works

1. *Divide:* Divide the input array into two halves until each sub-array contains only one element (base case).
2. *Conquer:* Sort each sub-array recursively using Merge Sort.
3. *Merge:* Merge the sorted sub-arrays to produce a single sorted array.

### Algorithm Steps

1. *Merge Sort Function:*
   - If the array has one or zero elements, return the array (base case).
   - Divide the array into two halves.
   - Recursively call Merge Sort on each half.
   - Merge the sorted halves using a merge function.

2. *Merge Function:*
   - Create a temporary array to store the merged result.
   - Compare elements from both halves and merge them into the temporary array in sorted order.
   - Copy the merged result back to the original array.

### Example

Let's sort an array [38, 27, 43, 3, 9, 82, 10] using Merge Sort:

- Divide the array into [38, 27, 43] and [3, 9, 82, 10].
- Recursively sort each half: [27, 38, 43] and [3, 9, 10, 82].
- Merge the sorted halves: [3, 9, 10, 27, 38, 43, 82].

### Complexity Analysis

- *Time Complexity:*
  - Best Case: O(n log n) - When the array is evenly divided at each level of recursion.
  - Worst Case: O(n log n) - Same as the average case due to consistent splitting and merging.
  - Average Case: O(n log n)
- *Space Complexity:* O(n) - Requires additional space for temporary arrays during the merging process.

### Advantages

- Stable sorting algorithm.
- Efficient for large datasets.
- Consistent time complexity regardless of input distribution.

### Disadvantages

- Requires additional space for temporary arrays during the merging process.
- Recursive implementation may lead to stack overflow for very large arrays.

### Conclusion

Merge Sort is a divide-and-conquer sorting algorithm that efficiently sorts large datasets by dividing them into smaller sub-arrays, sorting them recursively, and then merging the sorted halves. While it requires additional space for merging, its consistent time complexity makes it suitable for a wide range of applications.


<p align="center"><img src="https://www.w3schools.com/dsa/img_mergesort_long.png" alt="project-image"></p>

## Searching Algorithms

### Binary Search

Binary Search is a fast search algorithm that works on sorted arrays. It repeatedly divides the search interval in half until the target element is found or the interval is empty. It is an efficient algorithm for searching in large datasets.

### How it Works

1. *Initialize:* Set low to the first index and high to the last index of the array.
2. *Loop:* Repeat until low is less than or equal to high.
   - Calculate mid as (low + high) / 2.
   - If the target element is equal to the element at mid, return mid.
   - If the target element is less than the element at mid, set high to mid - 1.
   - If the target element is greater than the element at mid, set low to mid + 1.
3. *Return:* If the loop exits without finding the target element, return -1 (not found).

### Algorithm Steps

1. *Binary Search Function:*
   - Set low to 0 and high to n-1 (where n is the size of the array).
   - Repeat the loop until low is less than or equal to high.
     - Calculate mid as (low + high) / 2.
     - If the target element is equal to the element at mid, return mid.
     - If the target element is less than the element at mid, set high to mid - 1.
     - If the target element is greater than the element at mid, set low to mid + 1.
   - If the loop exits without finding the target element, return -1.

### Example

Let's search for the element 35 in a sorted array [10, 20, 30, 40, 50, 60, 70, 80]:

- Initialize low = 0, high = 7.
- First iteration: mid = (0 + 7) / 2 = 3 (element 40).
  - 35 < 40, so set high = 3 - 1 = 2.
- Second iteration: mid = (0 + 2) / 2 = 1 (element 20).
  - 35 > 20, so set low = 1 + 1 = 2.
- Third iteration: mid = (2 + 2) / 2 = 2 (element 30).
  - 35 > 30, so set low = 2 + 1 = 3.
- Fourth iteration: low > high, exit loop (element not found).

### Complexity Analysis

- *Time Complexity:*
  - Best Case: O(1) - When the target element is found at the first comparison.
  - Worst Case: O(log n) - When the target element is at the middle or not in the array.
  - Average Case: O(log n)
- *Space Complexity:* O(1) - Requires constant space for variables.

### Advantages

- Efficient search algorithm for sorted arrays.
- Time complexity of O(log n) ensures fast search even in large datasets.

### Disadvantages

- Requires the array to be sorted beforehand.
- Not applicable for unsorted or dynamically changing arrays.

### Conclusion

Binary Search is a fast search algorithm that efficiently finds a target element in a sorted array by repeatedly dividing the search interval in half. It offers a time complexity of O(log n), making it suitable for large datasets where quick searches are required.


<p align="center"><img src="https://miro.medium.com/v2/resize:fit:1400/format:webp/1*M8nxu1oYQy2vpWRjlVdXNA.png" alt="project-image"></p>

## Divide and Conquer Technique

Divide and conquer is a fundamental algorithmic technique for solving problems. It works by breaking down a complex problem into several subproblems of the same type, solving them independently, and combining their solutions to solve the original problem.

- *Performance Evaluation:*
  - Best Case: O(n log n)
  - Average Case: O(n log n)
  - Worst Case: O(n log n)
- *Time Complexity Classes:*
  - Time Complexity: O(n log n)
  - Space Complexity: O(log n)

## Greedy Technique

### Activity Selection Problem

The Activity Selection Problem is a scheduling algorithm that aims to maximize the number of activities that can be performed within a given time frame. It involves selecting a subset of mutually compatible activities that do not overlap in their time intervals.

### How it Works

1. *Sort Activities:* Sort the activities based on their finish times in ascending order.
2. *Select First Activity:* Select the first activity with the earliest finish time.
3. *Iterate:* For each remaining activity:
   - If the start time of the current activity is greater than or equal to the finish time of the previously selected activity, select the current activity.
4. *Repeat:* Continue this process until all activities are processed.

### Algorithm Steps

1. *Activity Selection Function:*
   - Sort activities based on finish times.
   - Select the first activity as the first selected activity.
   - Iterate through remaining activities:
     - If start time >= finish time of last selected activity, select the current activity.
   - Return the selected activities.

### Example

Let's consider the following activities with their start and finish times:
- Activity A: (1, 3)
- Activity B: (2, 5)
- Activity C: (4, 7)
- Activity D: (6, 9)

Sorted by finish times: A(1, 3), B(2, 5), C(4, 7), D(6, 9)

Selected activities: A(1, 3), C(4, 7)

### Complexity Analysis

- *Time Complexity:* O(n log n) - Due to sorting the activities by finish times.
- *Space Complexity:* O(1) - Requires constant space for variables.

### Advantages

- Maximizes the number of activities performed within a given time frame.
- Efficient scheduling algorithm for resource optimization.

### Disadvantages

- Requires activities to be sorted based on finish times.
- May not always select the optimal subset of activities for all scenarios.

### Conclusion

The Activity Selection Problem is a scheduling algorithm that efficiently selects a subset of mutually compatible activities to maximize utilization within a given time frame. While it requires sorting activities initially, it offers an efficient solution for resource optimization and scheduling tasks.

 <p align="center"><img src="https://iq.opengenus.org/content/images/2019/03/Example1.png" alt="project-image"></p>
 <p align="center"><img src="https://iq.opengenus.org/content/images/2019/03/Example2-2.png" alt="project-image"></p>

### Huffman Coding

Huffman coding is a data compression algorithm that assigns variable-length codes to input characters based on their frequencies. It achieves compression by replacing frequently occurring characters with shorter codes and less frequently occurring characters with longer codes.

### How it Works

1. *Frequency Calculation:* Calculate the frequency of each character in the input data.
2. *Build Huffman Tree:*
   - Create leaf nodes for each character with their frequencies as weights.
   - Combine two nodes with the lowest frequencies to create a new internal node with a combined frequency.
   - Repeat this process until all nodes are combined into a single tree.
3. *Generate Codes:*
   - Traverse the Huffman tree to assign codes to each character.
   - Left branches represent '0' and right branches represent '1'.
   - The code for each character is the path from the root to that character in the tree.
4. *Encode Data:*
   - Replace each character in the input data with its corresponding Huffman code.
   - Create a compressed bitstream using the generated codes.
5. *Decode Data:*
   - Use the Huffman tree to decode the compressed bitstream back into the original data.

### Algorithm Steps

1. *Frequency Calculation Function:*
   - Calculate the frequency of each character in the input data.
2. *Build Huffman Tree Function:*
   - Create leaf nodes for each character with their frequencies.
   - Combine nodes with lowest frequencies to build the Huffman tree.
3. *Generate Codes Function:*
   - Traverse the Huffman tree to assign codes to each character.
4. *Encode Data Function:*
   - Replace characters with their Huffman codes to create a compressed bitstream.
5. *Decode Data Function:*
   - Use the Huffman tree to decode the compressed bitstream back into original data.

### Example

Let's compress the string "ABRACADABRA" using Huffman coding:
- Frequencies: A(5), B(2), R(2), C(1), D(1)
- Huffman Tree:
            ___
           /     \
        A(5)   __
               /    \
            B(2)   _
                   /    \
                R(2)  _
                      /    \
                   C(1)  D(1)
- Codes: A(0), B(10), R(110), C(1110), D(1111)
- Compressed Data: 010011010011110101010

### Complexity Analysis

- *Time Complexity:* O(n log n) - Constructing the Huffman tree.
- *Space Complexity:* O(n) - Storage for the Huffman tree and codes.

### Advantages

- Achieves efficient data compression by assigning shorter codes to frequently occurring characters.
- Can be used for lossless compression, preserving the original data.

### Disadvantages

- Requires the frequency of characters in the input data, which may add overhead for small datasets.
- Huffman coding may not always achieve optimal compression for all types of data.

### Conclusion

Huffman coding is a widely used data compression algorithm that efficiently reduces the size of data by assigning variable-length codes to characters based on their frequencies. While it requires initial overhead for constructing the Huffman tree, it offers effective compression for various types of data.

 
<p align="center"><img src="https://kamilmysliwiec.com/wp-content/uploads/2017/04/chart.png" alt="project-image"></p>

## Practice Problems

- Sorting:
  - [Sorting Algorithms](https://leetcode.com/tag/sorting/)
- Searching:
  - [Binary Search](https://leetcode.com/tag/binary-search/)
- Divide and Conquer:
  - [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/)
- Greedy:
  - [Activity Selection](https://leetcode.com/problems/activity-selection-ii/)
  - [Huffman Coding](https://leetcode.com/problems/maximum-binary-tree/)
