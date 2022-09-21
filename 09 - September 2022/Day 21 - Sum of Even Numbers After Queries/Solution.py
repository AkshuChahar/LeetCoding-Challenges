class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        n, m = len(nums), len(queries)
        ans = []
        # Get the sum of all even numbers.
        curr_sum = 0
        for num in nums:
            if num % 2 == 0:
                curr_sum += num
        # Run all queries.
        for query in queries:
            rem_num = nums[query[1]] % 2
            rem_val = query[0] % 2
            # Case 1: Both numbers are odd.
            if rem_num and rem_val:
                curr_sum += nums[query[1]] + query[0]
                nums[query[1]] += query[0]
            # Case 2: Both numbers are even.
            elif (not rem_num) and (not rem_val):
                curr_sum += query[0]
                nums[query[1]] += query[0]
            # Case 3: Old value is even and new value is odd.
            elif (not rem_num) and rem_val:
                curr_sum -= nums[query[1]]
                nums[query[1]] += query[0]
            # Case 4: Old value is odd and new value is even.
            else:
                nums[query[1]] += query[0]
            # Update 'ans'.
            ans.append(curr_sum)
        return ans