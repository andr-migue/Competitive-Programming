def prefix_function(s):
    q = 0
    n = len(s)
    
    pi = [0 for i in range(n)]
    
    for i in range(1, n):
        while q > 0 and s[i] != s[q]:
            q = pi[q - 1]
            
        if s[q] == s[i]:
            q += 1
            
        pi[i] = q
        
    return pi

def kmp(pat, txt):
    text = pat + '$' + txt
    pi = prefix_function(text)
    
    ans = 0
    n = len(pat)
    
    for i in range(n + 1, len(pi)):
        if pi[i] == n:
            ans += 1
            
    return ans