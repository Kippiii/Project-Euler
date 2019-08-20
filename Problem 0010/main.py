LENGTH = 2000000

def attempt_removal(n, nums):
    for i in range(2 * n, LENGTH + 1, n):
        nums[i] = 0
    
nums = [0] * (LENGTH + 1)
for i in range(2, len(nums)):
    nums[i] = i;

for n in nums:
    if n != 0:
        attempt_removal(n, nums)

sum = 0
for i in nums:
    sum += i
    
print(f'The sum is {sum}.')