class Solution:
    def permute(self, nums):
        result = []

        def backtrack(path):
            # If permutation is complete
            if len(path) == len(nums):
                result.append(path[:])   # Copy the current permutation
                return

            # Try every number
            for num in nums:
                if num not in path:      # Skip already used numbers
                    path.append(num)     # Choose
                    backtrack(path)      # Recur
                    path.pop()           # Backtrack

        backtrack([])
        return result