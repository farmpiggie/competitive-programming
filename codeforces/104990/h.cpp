N = int(input())
s = input()


def val(c) -> int:
    return ord(c)-ord('a')


freq = [0 for x in range(26)]  # frequency of each
loc = [set() for x in range(26)]  # locations of each

b = 0
for i in range(N):
    c = s[i]
    freq[val(c)] += 1
    b = max(freq[val(c)], b)
    loc[val(c)].add(i)

ans = ''

for k in range(26):
    if freq[k] < b:
        continue
    start = chr(k+ord('a'))
    # for each location of character, check loc+i, if they are all the same then good
    # if they are different, or one of them is same as the character/out of bounds, bad
    best = chr(k+ord('a'))
    for i in range(1, N):
        works = True
        currchar = '='
        for l in loc[k]:
            if l+i >= N:
                works = False
                break
            if s[l+i] == start:
                works = False
                break
            if currchar == '=':
                currchar = s[l+i]
            elif currchar != s[l+i]:
                works = False
                break
        if currchar == '=':
            break
        if works:
            best += currchar
        else:
            break
    if len(ans) < len(best):
        ans = best
    elif len(ans) == len(best) and best < ans:
        ans = best

print(ans)
