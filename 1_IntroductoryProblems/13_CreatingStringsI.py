from itertools import permutations

if __name__ == "__main__":
    sol = {}
    for st in permutations(sorted(str(input()))):
        sol[''.join(st)] = 1
    print(len(sol))
    print("\n".join(sol.keys()))
