class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        record = dict()#key为字符串，value为字符串列表
        for i in strs:#与c++不同，这里的i可以直接代表字符串
            #sorted() 返回的是字符列表，需要用 ''.join() 拼接成字符串作为键。本题是空字符串拼接排序后字符串
            key = ''.join(sorted(i))
            if key in record:
                record[key].append(i) # 已存在的键，追加到列表
            else:
                record[key] = [i]  # 新键，初始化列表存储第一个元素
        return list(record.values())
