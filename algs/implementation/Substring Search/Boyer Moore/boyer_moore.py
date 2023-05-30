
t = "данные"


S = set()
m = len(t)
d = {}


for i in range(m-2, -1, -1):

    if t[i] not in S:

        d[t[i]] = m - i - 1
        S.add(t[i])

if t[m-1] not in S:

    d[t[i]] = m

d['*'] = m


a = "большие методанные"

n = len(a)

if n >= m:

    i = m - 1
    
    while(i < n):

        k = 0

        for j in range(m-1, -1, -1):

            if a[i-k] != t[j]:
 
                if j == m - 1:

                    off = d[a[i]] if d.get(a[i], False) else d['*']

                else:

                    off = d[t[j]]

                i += off
                break

            k += 1

        if j == 0:

            print("match at index ", i-k+1)
            break



else:

    print("No match")

    





#print(d)







