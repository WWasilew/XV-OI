class Stack:                # stworzenie struktury stosu
    def __init__(self):
        self.stack = list()

    def push(self, value):
        self.stack.append(value)

    def pop(self):
        self.stack.pop()

    def top(self):
        return self.stack[len(self.stack)-1]

    def isEmpty(self):
        if len(self.stack) == 0:
            return 1
        return 0


if __name__ == "__main__":

    n = int(input())        # liczba bloków

    widths = list()         # długości bloków - niepotrzebne
    heights = list()        # wysokości bloków

    for i in range(n):      # czytanie wartości
        data = input().split()
        widths.append(data[0])
        heights.append(data[1])

    stack_of_buildings = Stack()        # stos przechowujący bloki
    minimum_number_of_posters = 0       # liczba potrzebnych plakatów

    for i in range(n):                  # implementacja pseudoalgorytmu
        while (not stack_of_buildings.isEmpty() and heights[stack_of_buildings.top()] > heights[i]):
            stack_of_buildings.pop()
        if (stack_of_buildings.isEmpty() or heights[i] > heights[stack_of_buildings.top()]):
            stack_of_buildings.push(i)
            minimum_number_of_posters = minimum_number_of_posters + 1

    print(minimum_number_of_posters)
