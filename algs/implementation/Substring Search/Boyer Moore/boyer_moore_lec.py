
s = "Большие метeоданные"
x = "данные"

n = len(s)
m = len(x)

i = 0
f = False

while(i < n - m + 1) and not f:

    j = m - 1
    while(j > 0 and s[i + j] == x[j]):
        j -= 1

    if j == 0:
        f = True
    else:
        i += 1
