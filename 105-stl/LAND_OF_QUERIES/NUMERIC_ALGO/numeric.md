# NUMERIC ALGORITHM( QUERYING A VALUE )

## COUNT
Take beginning and end index and returns the number of times the element repeats

## ACCUMULATE/(TRANSFORM_)REDUCE 
* Makes the sum of the element of collection with operator or function and produces in value. 
* Reduce is similar to accumulate and it doesn't take any initial value.
* transform_reduce() takes the function and then applies reduce to it.

## PARTIAL_SUM 
* So it takes in account such first pos will have value of first pos, second pos will have first + second and so forth. 
* In newer versions, we have: 
    1. (transform_)inclusive_scan: similar to partial_sum except it runs in parallel
    2. (transform_)exclusive_scan: similar to inclusive_scan but doesn't include the current element. 

## INNER_PRODUCT 
* Takes product of counter part of 2 collections and then summation of whole things.

## ADJACENT_DIFFERENCE 
* Takes the difference of two adjacent neighbors in the collection. 

## SAMPLE 
* Takes a number n and product n number of that collection selected randomly. 



