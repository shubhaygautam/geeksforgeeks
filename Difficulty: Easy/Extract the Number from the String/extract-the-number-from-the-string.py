class Solution:
    def ExtractNumber(self,sentence):
        #code here
        return max((int(item) for item in sentence.split() if item.isnumeric() and "9" not in item), default = -1)


#{ 
 # Driver Code Starts
t = int(input())
for _ in range(t):
    S = input()
    ob = Solution()
    ans = ob.ExtractNumber(S)
    print(ans)

# } Driver Code Ends