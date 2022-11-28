class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        ans = [[], []]
        # Initialise a list to keep track of the wins and losses of each player.
        cnt = [-1] * 100001
        # Traverse the list.
        for winner, loser in matches:
            # Check if the player has not played any match and won the match.
            if cnt[winner] == -1:
                cnt[winner] = 0
            # Check if the player has not played any match and lost the match.
            if cnt[loser] == -1:
                cnt[loser] = 1
            else:
                cnt[loser] += 1
        # Traverse the list of scores and update 'ans'.
        for i in range(100001):
            if cnt[i] == 0:
                ans[0].append(i)
            elif cnt[i] == 1:
                ans[1].append(i)   
        return ans