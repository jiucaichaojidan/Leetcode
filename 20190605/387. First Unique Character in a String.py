class Solution:
    def firstUniqChar(self, s: str) -> int:
        mystr = 'abcdefghijklmnopqrstuvwxyz';
        l = [s.index(c) for c in mystr if s.count(c) == 1]
        return min(l) if len(l) > 0 else -1