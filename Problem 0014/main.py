def next_collatz(n):
    if n % 2 == 0:
        return n / 2
    else:
        return 3 * n + 1

collatz_steps = {1: 1}
longest = 0
longest_start = -1
for i in range(2, 1000000):
    count = 0
    n = i
    while n not in collatz_steps:
        n = next_collatz(n)
        count += 1
    count += collatz_steps[n]
    collatz_steps[i] = count
    if count > longest:
        longest = count
        longest_start = i

print(f"The longest collatz sequence starts with {longest_start}.")