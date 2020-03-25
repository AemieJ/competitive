# SORTING TECHNIQUE 

Let numbers be an array as defined: [4, 5, 3, 1, 8, 2]

## SORT 

In sort, it is a normal sort that will sort from beginning of the array to end of the array. 
```
Result: [1, 2, 3, 4, 5, 8]
```

## PARTIAL_SORT 

In partial sort, two indexes, the beginning and the end, are specified. Within this specified indexes, the numbers are sorted and other than the indexes specified, it is in random order. 
```
eg: start: 1, end: 3
Result: [1, 2, 3, 4, 8, 5];
```

## NTH_ELEMENT

In nth_element, a particular element with index n is chosen such that at the nth place will be taken by the number that would be as in the original sort. All the elements before nth index will be lesser than the nth element and after the nth index will be greater than the nth element.
```
eg: n: 2
Result: [1, 2, 3, 4, 8, 5]
```

## SORT_HEAP

It takes in the use of heap. First, you make the heap of the range and continue using pop_heap() to sort the entire range.

## INPLACE_MERGE

It makes use of the merge sort. Two halves are sorted and then you use merge sort to sort the entire range of number.