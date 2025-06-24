from itertools import combinations

def recursive(round):
    global res
    
    # basis part (15판 게임 모두 확인한 경우)
    if round == 15:
        res = 1
        for game in games:
            if game.count(0) != 3:
                res = 0
                break
        return
 
        
    # inductive part
    # 조합의 round번째 idx -> 대결하는 나라
    g1, g2 = comb[round]
    
    # 승무패
    for x, y in ((0,2), (1, 1), (2,0)):
        # 무승부가 아닌 승패의 결과
        if games[g1][x] > 0 and games[g2][y] > 0:
            games[g1][x] -= 1
            games[g2][y] -= 1
            recursive(round + 1)
            games[g1][x] += 1
            games[g2][y] += 1

# 가능한 15 경기의 모든 조합 구하기
comb = list(combinations(range(6),2))

# 각 나라의 승무패로 인덱싱
result = []
for d in range(4):
    tmp = list(map(int,input().split()))
    games = []
    for i in range(0, 16, 3):
        games.append(tmp[i:i+3])
    res = 0
    recursive(0)
    result.append(res)
    
print(*result)