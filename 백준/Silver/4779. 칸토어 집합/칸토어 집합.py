def recursive(len):
    # basis part
    if len == 1:
        return "-"
        
    # inductive part
    left = recursive(len // 3)
    middle = " " * (len // 3)
    return left + middle + left
    
while True:
    try:
        data = input()
        len = 3 ** int(data)
        print(recursive(len))
        
    except:
        break