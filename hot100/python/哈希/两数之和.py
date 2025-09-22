class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        #等价于def twoSum(self, nums, target):
        #self：作为第一个参数，表明这是类的实例方法（调用时会自动传入实例本身）
        #nums: List[int]：参数 nums 是一个整数列表（List[int] 是类型注解，用于提示参数类型）
        #target: int：参数 target 是一个整数（int 是类型注解）
        #-> List[int]：返回值注解，表明该方法的返回结果是一个整数列表
        '''原始方法
        records = dict()
        index = 0
        for value in nums:
            if target - value in records:
                return [records[target - value],index]
            records[value] = index
            index += 1
        return []
        '''
        records = dict()
        for index,value in enumerate(nums):
            #enumerate()用于遍历列表nums时，同时获取每个元素的索引（index） 和值（value）。
            #本题map的key，value分别对应nums的value，index
            if target - value in records:
                return [records[target - value],index]
            records[value] = index
        return []
        
