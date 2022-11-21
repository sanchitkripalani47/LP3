# Program to create huffman encoding for strings

# Used to import defaultdict
from collections import *
# Standard implementation of priority queue
from heapq import *

text = input("Enter the string you wish to encode: ")

# Create a dictionary to store freq of chars
dict1 = defaultdict(int)

# Iterate over chars in text
for char in text:
    dict1[char] += 1

# Now create a list of lists to store freqs
queue1 = []

# Note that structure of list is [[freq, [char, ""]]]
# In the end, we've given an empty string. We will store the encoding in that part
for key, value in dict1.items():
    queue1.append([value, [key, ""]])

# make a prority queue out of it
heapify(queue1)

# Iterate when there are still elements in priority queue
while(len(queue1) > 1):
    # Create the left side and right side nodes
    left_element = heappop(queue1)
    right_element = heappop(queue1)

    print("left ", left_element)
    print("right", right_element)

    for pair in left_element[1:]:
        pair[1] = '0' + pair[1]
    for pair in right_element[1:]:
        pair[1] = '1' + pair[1]

    # First add up the frequencies
    left = [left_element[0]+right_element[0]]
    left += right_element[1:]+left_element[1:]

    heappush(queue1, left)

# Store the final result in huff list
huff_list = right_element[1:] + left_element[1:]
print(huff_list)
