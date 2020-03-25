# QUERYING A PROPERTY 

## ONE RANGE
* all_of 
* any_of
* none_of

> On an empty collection, all_of, any_of, none_of returns true, false, true.

## TWO RANGE

* equal 
equal returns boolean value if both collections are equal in size and in same order. However, if not in same order, you can check 
it through is_permutation which returns a bool as well. 

* lexicographical_compare 
returns the bool value if first collection is smaller i.e. comes first in the dictionary. 

* mismatch 
return the pair of iterator from the point where the collection begins to match.