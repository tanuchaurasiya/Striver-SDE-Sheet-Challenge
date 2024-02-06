class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = {}
        for word in strs:
            print(sorted(word))
            sortedWord = "".join(sorted(word))
            if sortedWord in anagrams:
                anagrams[sortedWord].append(word)
            else:
                anagrams[sortedWord] = [word] 
        # print(anagrams)
        return list(anagrams.values())