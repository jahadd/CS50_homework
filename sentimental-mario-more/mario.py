def get_int(prompt):
    while True:
        try:
            value = int(input(prompt))
            return value
        except ValueError:
            pass

# Prompt user for height
while True:
    height = get_int("Height: ")
    if 1 <= height <= 8:
        break

# Print the pyramid
for i in range(1, height + 1):
    left = " " * (height - i) + "#" * i
    right = "#" * i
    print(f"{left}  {right}")
