array = [[] for _ in range(10)]
paper_count = [5,5,5,5,5]
result = 26

for i in range(10):
    array[i] = list(map(int,input().split()))

# 3. 탐색중인 내부 범위의 모든 값이 1인지 판별
def check_all_is_one(y, x, size):
    if paper_count[size - 1] == 0:
        return False
    if y + (size - 1) >= 10 or x + (size - 1) >= 10:
        return False

    for i in range(size):
        for j in range(size):
            if array[y + i][x + j] != 1:
                return False
    return True

# 3. 색종이 붙이기
def attach(y, x, size, value):
    for i in range(size):
        for j in range(size):
            array[y + i][x + j] = value
    
# 2. 색종이를 붙일 수 있는지 판별
def is_attach(count):
    global result

    # 색종이를 붙일 수 있는 곳 찾기
    for i in range(10):
        for j in range(10):
            if array[i][j] == 1:
                for size in [5,4,3,2,1]:
                    if check_all_is_one(i, j, size):
                        # 색종이 붙이기
                        attach(i, j, size, 0)
                        paper_count[size - 1] -= 1
                        is_attach(count + 1)
                        # 복구하기
                        attach(i, j, size, 1)
                        paper_count[size - 1] += 1
                # for문 끝내주기
                return

    # result 갱신
    result = min(result, count)

is_attach(0)
if result != 26:
    print(result)
else:
    print(-1)
    