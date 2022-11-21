from collections import *
from heapq import *

text = "aabcd"

dict1 = defaultdict(int)

for chars in text:
    dict1[chars] += 1

queue1 = []

for key, value in dict1.items():
    queue1.append([value, [key, '']])

heapify(queue1) 

while(len(queue1) > 1):

    left_element = heappop(queue1)
    right_element = heappop(queue1)

    for pair in left_element[1:]:
        pair[1] = '0' + pair[1]

    for pair in right_element[1:]:
        pair[1] = '1' + pair[1]

    left = [left_element[0]+right_element[0]]
    left += right_element[1:]+left_element[1:]

    print(left)

    heappush(queue1, left)


huff_list = right_element[1:] + left_element[1:]
print(huff_list)
    