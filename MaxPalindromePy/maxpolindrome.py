class Palindrome:
    def maxPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        odd = len(s) % 2
        half = int(len(s)/2)
        print("len "+str(len(s)))
        isaved = 0;
        jsaved = 0;
        counter = 0
        max = 0
        palidromeList = []
        if len(s) == 0:
          return
        if len(s) == 1:
          return s
        elif len(s) == 2:
          if s[0] == s[1]:
              return s
          else:
            return
        elif len(s) != 0:
          for i in range (len(s)-1):
            #print("\n")
            #print("i" + str(i))
            for j in range (len(s)-1, i , -1):
              #print("j" + str(j))
              counter = 0
              if s[i] == s[j]:
                ii = i
                jj = j
                while s[ii] == s[jj] and ii <= jj :
                  ii = ii + 1
                  jj = jj - 1
                if j - i > max and ii >= jj:
                  max = j - i
                  isaved = i
                  jsaved = j
                  
        palidromeString = s[isaved:jsaved+1]
        return palidromeString
