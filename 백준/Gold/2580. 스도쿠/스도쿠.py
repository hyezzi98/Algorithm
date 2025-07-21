import sys
array = [[] for _ in range(9)]
for i in range(9):
    array[i] = list(map(int,input().split()))

visited_row = [[False] * 10 for _ in range(9)]
visited_column = [[False] * 10 for _ in range(9)]
visited_squre = [[False] * 10 for _ in range(9)]

# 빈 칸 좌표 넣기
blank_list = []
for i in range(9):
    for j in range(9):
        num = array[i][j]
        if num == 0:
            blank_list.append((i,j))
        else:
            visited_row[i][num] = True
            visited_column[j][num] = True
            box_idx = (i // 3) * 3 + (j // 3)
            visited_squre[box_idx][num] = True
            
                
def recursive(depth):
    # basis part -> 모든 칸에 값을 넣었을 때 종료
    if depth == len(blank_list):
        for row in array:
            print(*row)
        sys.exit()
        
    # inductive part
    y, x = blank_list[depth]
    box_num = (y // 3) * 3 + (x // 3)

    # 넣을 수 있는 숫자 찾기
    for i in range(1, 10):
        if not visited_row[y][i] and not visited_column[x][i] and not visited_squre[box_num][i]:
            array[y][x] = i
            visited_row[y][i] = True
            visited_column[x][i] = True
            visited_squre[box_num][i] = True

            recursive(depth + 1)

            array[y][x] = 0
            visited_row[y][i] = False
            visited_column[x][i] = False
            visited_squre[box_num][i] = False
            
recursive(0)
