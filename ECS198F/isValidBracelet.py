def isValidBracelet(arr):
    for i in range(len(arr)//2):
        color, side = arr[i].split('_')
        color2, side2 = arr[len(arr)-1-i].split('_')
        if color != color2:
            print(False)
            return
    print(True)


arr1 = ["red_left", "blue_left", "blue_right", "red_right"]
result1 = isValidBracelet(arr1)
# Expected Output: True

arr2 = ["red_left", "blue_left", "yellow_left", "yellow_right", "blue_right", "red_right"]
result2 = isValidBracelet(arr2)
# Expected Output: True

arr3 = ["red_left", "blue_left", "yellow_left", "blue_right", "red_right"]
result3 = isValidBracelet(arr3)
# Expected Output: False

arr4 = ["red_left", "blue_right"]
result4 = isValidBracelet(arr4)
# Exptected Output: False