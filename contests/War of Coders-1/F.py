N : int = int(input())

movieInfos = []

for i in range(N):
    start, end = map(int, input().split())
    movieInfos.append((end, start))

movieInfos.sort()

print(movieInfos)

count = 0
end_time = 0

for end, start in movieInfos:
    if start >= end_time:
        count += 1
        end_time = end

print(count)