import math


def can_reach_without_touching(t, test_cases):
    results = []
    for case in test_cases:
        n, circles, x_s, y_s, x_t, y_t = case
        d_st = (x_s - x_t) ** 2 + (y_s - y_t) ** 2
        possible = True
        for x_i, y_i in circles:
            d_s = (x_i - x_t) ** 2 + (y_i - y_t) ** 2
            if d_s <= d_st:
                possible = False
                break
        results.append("YES" if possible else "NO")
    return results


t = int(input())
test_cases = []
for _ in range(t):
    n = int(input())
    circles = [tuple(map(int, input().split())) for _ in range(n)]
    x_s, y_s, x_t, y_t = map(int, input().split())
    test_cases.append((n, circles, x_s, y_s, x_t, y_t))

results = can_reach_without_touching(t, test_cases)

for result in results:
    print(result)
