class TimeMap:

    def __init__(self):
        self.hashmap = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.hashmap:
            self.hashmap[key] = [[value, timestamp]]
        else:
            self.hashmap[key].append([value, timestamp])
        

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.hashmap:
            return ""
        l = 0
        r = len(self.hashmap[key]) - 1
        m = 0
        while (l <= r):
            m = l + ((r - l) // 2)

            if self.hashmap[key][m][1] == timestamp:
                return self.hashmap[key][m][0]
            elif self.hashmap[key][m][1] < timestamp:
                l = m + 1
            else:
                r = m - 1
        return self.hashmap[key][r][0] if r >= 0 else ""



        
