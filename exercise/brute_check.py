from itertools import product


def brute(n, m, k):
    best = None
    bestmat = None
    for bits in product([0, 1], repeat=n * m):
        ok = True
        for i in range(n - 1):
            for j in range(m - 1):
                s = (bits[i * m + j] + bits[i * m + j + 1]
                     + bits[(i + 1) * m + j] + bits[(i + 1) * m + j + 1])
                if s != k:
                    ok = False
                    break
            if not ok:
                break
        if ok:
            t = sum(bits)
            if best is None or t < best:
                best = t
                bestmat = bits
    return best, bestmat


def classes(n, m):
    sz = [[0, 0], [0, 0]]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            sz[i % 2][j % 2] += 1
    return sz


for n in range(2, 5):
    for m in range(2, 5):
        if n * m > 16:
            continue
        for k in (1, 2, 3):
            b, bm = brute(n, m, k)
            sz = classes(n, m)
            vals = sorted([sz[0][0], sz[0][1], sz[1][0], sz[1][1]])
            if k == 1:
                pred = vals[0]
            elif k == 2:
                pred = vals[0] + vals[1]
            else:
                pred = sum(vals) - vals[3]
            tag = "OK" if b == pred else "MISMATCH"
            print(n, m, k, "brute =", b, "pred =", pred, tag,
                  "best =", bm if b != pred else "")
