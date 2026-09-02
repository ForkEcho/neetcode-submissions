class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        A, B = nums1, nums2
        total = len(nums1) + len(nums2)
        half = total // 2

        if len(B) < len(A):
            A, B = B, A

        l, r = 0, len(A) - 1
        while True:
            am = l + ((r - l) // 2)
            bm = half - am - 2
            
            aleft = A[am] if am >= 0 else float("-infinity")
            aright = A[am + 1] if (am + 1) < len(A) else float("infinity")
            bleft = B[bm] if bm >= 0 else float("-infinity")
            bright = B[bm + 1] if (bm + 1) < len(B) else float("infinity")

            if (aleft <= bright and bleft <= aright):
                if total % 2:
                    return min(bright, aright)
                else:
                    return (max(aleft, bleft) + min(aright, bright)) / 2
            elif aleft > bright:
                r = am - 1
            else:
                l = am + 1


        