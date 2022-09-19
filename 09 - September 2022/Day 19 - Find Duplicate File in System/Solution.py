class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        # Initialise a dictionary to store thr files with same contents.
        d = defaultdict(list)
        # Traverse the list.
        for path in paths:
            # Split the path to get the directory and file names.
            files = path.split(" ")
            n = len(files)
            # Traverse the files skipping the directory path.
            for i in range(1, n):
                # Get the index where the content starts and update the dictionary.
                ind = files[i].index("(")
                d[files[i][ind:]].append(files[0] + "/" + files[i][:ind])
        # Traverse the dictionary and return the required answer.
        return [d[i] for i in d if len(d[i]) > 1]