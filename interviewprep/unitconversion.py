"""
// Source: https://www.youtube.com/watch?v=V8DGdPkBBxg

/*
Conversions
1 hr -> 60 mins
1 min -> 60 secs
1 ft -> 12 inches

Queries
4 hrs -> ? mins (240 mins)
2 ft -> ? hours (no valid conversion)
"""
from collections import deque

class Node:
    def __init__(self, unit):
        self.unit = unit
        self.neighbors = []

    def add_neighbor(self, unit, conversion):
        self.neighbors.append((unit, conversion))

node_table = {} # mapping from string to Node

def process_conversions(conversions):
    for conversion in conversions: # ( string, int, string)
        if conversion[0] in node_table:
            node = node_table[conversion[0]]
        else:
            node = Node(conversion[0])

        node.add_neighbor(conversions[1], conversions[2])


def process_queries(queries): # int, string, string
    ans = []
    for query in queries:
        queue = deque()
        visited = {}
        measurement, unit, target_unit = query
        queue.insert((measurement, unit)) # measurement, unit
        visited[unit] = True
        found = False
        while len(queue) > 0:
            curr_measurement, curr_unit = queue.popleft()
            if (curr_unit == target_unit):
                ans.append(curr_measurement)
                found = True
                break
            for next_unit, next_node in node_table[curr_unit].neighbors:
                if (visited[next_node]): continue
                visited[next_node] = True
                queue.append((curr_unit * next_unit, next_node))

        if not found:
            ans.append(-1)
    return ans

