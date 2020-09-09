# Box Stacking
Link is [here](https://practice.geeksforgeeks.org/problems/box-stacking/1)  
Reference link to this is [here](https://www.youtube.com/watch?time_continue=1&v=9mod_xRB-O0&feature=emb_title)  

Algorithm used: 
1. First, write all the possible arrangements of the {l, b, h} for each in such a way that l > w.
2. Sort in decreasing order based on the area. 
3. Create a dp[n] where n is the total deduced number of orders and fill it with the original heights for each order
4. for int i = 1->n-1
        for int j = 0->i
            if (l[i] < l[j] && w[i] < w[j] && dp[i] < h[i] + dp[j])        
                dp[i] = h[i] + dp[j]
5. find maximum element of the dp.