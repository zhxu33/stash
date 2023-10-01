def isValidBracelet(array_of_beads):
    # time complexity: O(n), space complexity: O(1)

    # edge cases: number of beads is odd
    if len(array_of_beads) % 2:
        return 'False'
    
    # test for beads on 1 axis
    found = False
    for i in range(len(array_of_beads)//2):
        left_color, left_side = array_of_beads[i].split('_')
        right_color, right_side = array_of_beads[len(array_of_beads)-1-i].split('_')
        if left_color != right_color or left_side == right_side: # found not matching
            found = True
            break
    if not found: # valid symmetric bracelet    
        return 'True'
    
    # try connecting start and end beads
    start = len(array_of_beads)-2
    end = len(array_of_beads)-1
    while True:
        left_color, left_side = array_of_beads[start].split('_')
        right_color, right_side = array_of_beads[end].split('_')
        if left_color != right_color or left_side == right_side: # found not matching
            return 'False'
        start -= 1
        if end == len(array_of_beads) - 1:
            end = 0
        else:
            end += 1
        if start < end:
            break
    return 'True' # valid symmetric bracelet