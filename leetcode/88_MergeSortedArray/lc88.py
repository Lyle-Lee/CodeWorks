class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        nums1[m:] = nums2
        nums1.sort()
        #if n == 0:
        #   return
        #len_nums1, len_nums2 = len(nums1), len(nums2)
        #while m > 0:
        #    if nums1[len_nums1-m-n] <= nums2[0]:
        #       m -= 1
        #    else:
        #       tmp = nums1[len_nums1-m-n]
        #       nums1[len_nums1-m-n] = nums2[0]
        #      nums2[0] = tmp
        #     nums2 = sorted(nums2)
        #     m -= 1
        #for i in range(len_nums1 - len_nums2, len_nums1):
        #    nums1[i] = nums2[len_nums2-n]
        #    n -= 1
