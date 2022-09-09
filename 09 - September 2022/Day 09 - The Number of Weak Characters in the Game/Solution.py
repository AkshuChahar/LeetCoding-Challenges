class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        ans, n = 0, len(properties)
        # Sort the array in descending order based on 'attack'.
        properties.sort(key = lambda x:(-x[0], x[1]))
        # Initialise variables to keep track of current minimum attack and defence.
        attack, defence = properties[0][0], properties[0][1]
        # Traverse the array.
        for i in range(1, n):
            # Check if the current character is weak.
            if (properties[i][0] < attack) and (properties[i][1] < defence):
                ans += 1
            # Update 'attack' and 'defence'.
            else:
                attack, defence = properties[i][0], properties[i][1]
        return ans