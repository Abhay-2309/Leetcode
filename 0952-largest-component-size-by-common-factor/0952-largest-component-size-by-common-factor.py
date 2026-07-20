class Solution:
    def largestComponentSize(self, nums: List[int]) -> int:
        max_val = max(nums)

        spf = list(range(max_val + 1))
        for i in range(2, int(max_val**0.5) + 1):
            if spf[i] == i:
                for j in range(i * i, max_val + 1, i):
                    if spf[j] == j:
                        spf[j] = i

        parent = list(range(max_val + 1))

        def find(x: int) -> int:
            if parent[x] == x:
                return x
            parent[x] = find(parent[x])
            return parent[x]

        def union(x: int, y: int):
            rootX = find(x)
            rootY = find(y)
            if rootX != rootY:
                parent[rootX] = rootY

        for x in nums:
            temp = x
            while temp > 1:
                prime = spf[temp]
                union(x, prime)

                while temp % prime == 0:
                    temp //= prime

        component_sizes = {}
        for x in nums:
            root = find(x)
            component_sizes[root] = component_sizes.get(root, 0) + 1

        return max(component_sizes.values())