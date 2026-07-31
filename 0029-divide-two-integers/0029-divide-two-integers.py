class Solution:
    def divide(self, dividend, divisor):
        # Handle overflow case
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        
        if dividend == INT_MIN and divisor == -1:
            return INT_MAX

        # Determine sign
        sign = -1 if (dividend < 0) ^ (divisor < 0) else 1

        # Work with positive numbers
        dvd = abs(dividend)
        dvs = abs(divisor)

        result = 0

        while dvd >= dvs:
            temp = dvs
            multiple = 1

            # Double temp until it exceeds dvd
            while dvd >= (temp << 1):
                temp <<= 1
                multiple <<= 1

            dvd -= temp
            result += multiple

        return sign * result