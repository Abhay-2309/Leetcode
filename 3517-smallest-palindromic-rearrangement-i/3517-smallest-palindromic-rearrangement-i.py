class Solution:
    def smallestPalindrome(self, s: str) -> str:
        n = len(s)
        if n == 1:
            return s

        freq = [0] * 26
        for i in s:
            freq[ord(i) - ord('a')] += 1

        s1 = ""
        mid = ""

        for i in range(26):
            ele = freq[i]

            if ele & 1:
                if mid == "":
                    mid = chr(i + ord('a'))
                while ele > 1:
                    s1 += chr(i + ord('a'))
                    ele -= 2
            else:
                while ele > 0:
                    s1 += chr(i + ord('a'))
                    ele -= 2

        s2 = s1[::-1]
        return s1 + mid + s2