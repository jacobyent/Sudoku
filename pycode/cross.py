def cross(A,B):
    return [a+b for a in A for b in B]
digits = '123456789'
rows = 'ABCDEFGHI'
cols = digits
squares = cross(rows, cols)


unitlist = ([cross(rows,c) for c in cols] + 
            [cross(r,cols) for r in rows] +
            [cross(rs,cs) for rs in ('ABC','DEF','GHI') for cs in ('123','456','789')])

for value in unitlist:
    print(value)
