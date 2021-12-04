# SortingAlgorithms

- A collection of sorting algorithms implemented in c++.
- Includes a small program to compare their sorting times.

## Time complexity

| Algorithm | Worst case time |
| --- | --- |
| Bubble sort | O(n^2) |
| Selection sort | O(n^2) |
| Insertion sort | O(n^2) |
| Merge sort | O(n log n) |
| Quick sort | O(n^2) |
| Heap sort | O(n log n) |
| Shell sort | O(n^2) |

Quick sort is O(n log n) on average.

## How to use

Build with a C++11 compiler and make:

```sh
make
./prac1
./prac1 20 reversed
```

Defaults to 1000 random numbers. You can change the size and use `random`,
`sorted`, `reversed` or `duplicates`.

Run `make test` to check the sorts.
