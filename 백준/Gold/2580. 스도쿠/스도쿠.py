import sys
array = [[] for _ in range(9)]
for i in range(9):
    array[i] = list(map(int,input().split()))

# 빈 칸 좌표 넣기
blank_list = []
for i in range(9):
    for j in range(9):
        if array[i][j] == 0:
            blank_list.append([i,j])

def find_number(y, x):
    number_list = []
    visited = [0] * 10
    
    # 행 탐색
    for i in range(9):
        num = array[y][i]
        if num != 0:
            visited[num] = 1

    # 열 탐색
    for i in range(9):
        num = array[i][x]
        if num != 0:
            visited[num] = 1

    # 3 x 3 탐색
    start_y = (y // 3) * 3
    start_x = (x // 3) * 3

    for i in range(start_y, start_y + 3):
        for j in range(start_x, start_x + 3):
            num = array[i][j]
            if num != 0:
                visited[num] = 1

    # 넣을 수 있는 수 리턴하기
    for i in range(1, 10):
        if visited[i] == 0:
            number_list.append(i)
    return number_list
                
def recursive(depth):
    # basis part -> 모든 칸에 값을 넣었을 때 종료
    if depth == len(blank_list):
        for row in array:
            print(*row)
        sys.exit()
        
    # inductive part
    y, x = blank_list[depth]
    # 넣을 수 있는 숫자 찾기
    number_list = find_number(y, x)
    
    # 숫자 넣으면서 백트래킹
    for i in range(len(number_list)):
        array[y][x] = number_list[i]
        recursive(depth + 1)
        array[y][x] = 0

recursive(0)
