# Find median in a stream
Links is [here](https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0)  
Reference link for this is [here](https://www.youtube.com/watch?v=EIm2n8iPA4I)  
Make use of 2 heaps (implementation using priority queue), max and min heap.  
Priority queue in [c++](https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/)  

STEPS 
1. Add the element into the max heap
2. Take the top of element from max heap into min heap
3. If size of max heap is less than the min heap, take the top element of min heap and add it to max heap
4. If the size of max heap is greater than min heap then, peek the element from max heap or else if the size of 
both heaps is same, take peak of top element from max and min heap and do average of the two.