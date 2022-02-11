class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) <= 2:
            return 0
        left = 0
        right = len(height) - 1
        high = 1
        volume = 0
        while left <= right: # double pointer
            while left <= right and height[left] < high:
                left += 1
            while left <= right and height[right] < high:
                right -= 1
            volume += right - left + 1 # volume between interval greater (or equal) than 'high' could contain water
            high += 1
        return volume - sum(height)
