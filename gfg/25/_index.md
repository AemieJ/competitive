# Forming the longest common subsequence ( not substring )

This is done through DP where there are 2 major cases : 
if (a[i] == a[j]) => dp[i-1][j-1] + 1 ('cause you need to find the longest subsequence excluding i and j and then add on to it) 
else dp[i][j] = max(dp[i-1][j], dp[i][j-1]) (finding the longest subsequence by excluding either i or j) 