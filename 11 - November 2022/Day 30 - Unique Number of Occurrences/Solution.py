class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        # Check for number of elements in the list and the number of elements in the list of count of elements of list.
        return len(set(Counter(arr).values())) == len(set(arr))