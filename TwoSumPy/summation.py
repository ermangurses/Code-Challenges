###########################################################
#
#
#  Summation Class
#
#
###########################################################


class Summation:

    # twoSum takes array and target value to find two 
    # numbers that summation of them equals to target
    # It is implemented using hash so complexity is
    # O(n)
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for i in range (len(nums)):
            if nums[i] not in d:
                d[nums[i]] = i
            
            if target - nums[i] in d:
                if d[target - nums[i]] != i:
                    return [d[target - nums[i]],i]
        return[-1,-1]
