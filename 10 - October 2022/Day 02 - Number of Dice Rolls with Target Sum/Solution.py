class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        MOD = 10 ** 9 + 7
        # Initialise a dp list to keep track of number of dices and target sum remaining.
        dp = [0] * (target + 1)
        dp[0] = 1
        # Traverse through the dices.
        for _ in range(n):
            # Initialise a new list to keep the updated 'dp'.
            temp = [0] * (target + 1)
            # Traverse through the target sum.
            for tar in range(target, -1, -1):
                # Traverse through the number of faces in the dice.
                for ele in range(1, k + 1):
                    # Check if the current face can be included in the sum.
                    if ele <= tar:
                        temp[tar] += dp[tar - ele]
                temp[tar] %= MOD
            # Update 'dp'.
            dp = temp
        return dp[-1]