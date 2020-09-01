# Combination Sum - Part 2
Link is [here](https://practice.geeksforgeeks.org/problems/combination-sum-part-2/0)  
Explanation is:  
- You add the element to vector, check if its solvable while including that element and once the target isn't achieved, we remove
the element from the combination, and move on to check if its solvable while excluding the element.  
- As it stated that number in A may only be used once in the combination that is you can't use repetitive combinations and hence you sort 
the array in the beginning itself and check for the duplicates.