# Minimum no of deletions to form a palindrome in a string. 

Logic: When you want minimum number of deletions, you get the longest sequence. Now you require that you form a palindrome 
after deletion, so you need to find the longest commong subsequence from the string and its substring. For counting the number of 
deletions, it will be length of string - length of longest palindromic subsequence.