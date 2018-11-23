###########################################################
#
#
# driver file that calls Summation Class
#
#
###########################################################

import array as arr
from summation import Summation

array = [1,2,3,4,5,6,7,8,9,10]
target  = 6
test = Summation()

print(test.twoSum(array,target))
