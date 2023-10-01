def isValidBracelet(arr):
    # time complexity: O(n), space complexity: O(1)

    # edge cases: number of beads is odd
    if len(arr) % 2:
        return False
    
    # test for beads on 1 axis
    found = False
    for i in range(len(arr)//2):
        left_color, left_side = arr[i].split('_')
        right_color, right_side = arr[len(arr)-1-i].split('_')
        if left_color != right_color or left_side == right_side: # found not matching
            found = True
            break
    if not found: # valid symmetric bracelet    
        return True
    
    # try connecting start and end beads
    start = len(arr)-2
    end = len(arr)-1
    while True:
        left_color, left_side = arr[start].split('_')
        right_color, right_side = arr[end].split('_')
        if left_color != right_color or left_side == right_side: # found not matching
            return False
        start -= 1
        if end == len(arr) - 1:
            end = 0
        else:
            end += 1
        if start < end:
            break
    return True # valid symmetric bracelet

arr1 = ["red_left", "blue_left", "blue_right", "red_right"]
result1 = isValidBracelet(arr1)
# Expected Output: "True"

arr2 = ["red_left", "blue_left", "yellow_left", "yellow_right", "blue_right", "red_right"]
result2 = isValidBracelet(arr2)
# Expected Output: "True"

arr3 = ["red_left", "blue_left", "yellow_left", "blue_right", "red_right"]
result3 = isValidBracelet(arr3)
# Expected Output: "False"

arr4 = ["red_left", "blue_right"]
result4 = isValidBracelet(arr4)
# Exptected Output: "False"

arr5 = []
result5 = isValidBracelet(arr5)
# Exptected Output: "True"

arr6 = ["red_left", "red_right", "blue_left", "blue_right"]
result6 = isValidBracelet(arr6)
# Exptected Output: "True"

print(result1, result2, result3, result4, result5, result6)
