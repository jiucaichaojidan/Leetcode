class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        return ["Fizz" * (not i % 3) + "Buzz" * (not i % 5) or str(i) for i in range(1, n+1)]
        # or:找到第一个非空对象