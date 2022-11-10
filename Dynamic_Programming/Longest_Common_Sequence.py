X = [1, 0, 0, 1, 0, 1, 0, 1]
Y = [0, 1, 0, 1, 1, 0, 1, 1, 0]


def LCS(X, Y):
    X = [None] + X
    Y = [None] + Y
    def get_lengths(X, Y):        
        n = len(X) - 1
        m = len(Y) - 1
        
        c = []
        for i in range(n+1):
            c.append([0]*(m+1))
    
        if n * m == 0:
            return c
            
        for i in range(1, n+1):
            for j in range(1, m+1):
                if X[i] == Y[j]:
                    c[i][j] = c[i-1][j-1] + 1
                elif c[i-1][j] >= c[i][j-1]:
                    c[i][j] = c[i-1][j]
                else:
                    c[i][j] = c[i][j-1]
        
        return c
    

    def get_solution(X, Y, c):
        def helper(i, j):
            if i == 0 or j == 0:
                return []
            
            if X[i] == Y[j]:
                return helper(i-1, j-1) + [X[i]]
            elif c[i-1][j] >= c[i][j-1]:
                return helper(i-1, j)
            else:
                return helper(i, j-1)
            
        return helper(len(X) - 1, len(Y) - 1)
    
    return get_solution(X, Y, get_lengths(X, Y))

def LCS_Memoized(X, Y):
    X = [None] + X
    Y = [None] + Y
    n = len(X) - 1
    m = len(Y) - 1
    
   
    def get_length_memoized(X, Y, i, j, c):    
        if i * j == 0:
            q = 0
            c[i, j] = q
            return q
            
        if X[i] == Y[j]:
            q = c.get((i-1, j-1), get_length_memoized(X, Y, i-1, j-1, c)) + 1
            c[i, j] = q
            return q
        
        a = c.get((i-1, j), get_length_memoized(X, Y, i-1, j, c))
        b = c.get((i, j-1), get_length_memoized(X, Y, i, j-1, c))
        if a >= b:
            c[i, j] = a
            return a
        else:
            c[i, j] = b
            return b
    

    def get_solution(X, Y, c):
        def helper(i, j):
            if i == 0 or j == 0:
                return []
            
            if X[i] == Y[j]:
                return helper(i-1, j-1) + [X[i]]
            elif c[i-1, j] >= c[i, j-1]:
                return helper(i-1, j)
            else:
                return helper(i, j-1)
            
        return helper(len(X) - 1, len(Y) - 1)
    c = {}
    get_length_memoized(X, Y, n, m, c)
    return get_solution(X, Y, c)
#    return get_solution(X, Y, get_lengths(X, Y, c))

print(LCS_Memoized(X, Y))