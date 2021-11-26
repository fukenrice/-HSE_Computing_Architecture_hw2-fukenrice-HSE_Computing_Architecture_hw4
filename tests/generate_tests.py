import random
import math


def triangle_area(x1: int, y1: int, x2: int, y2: int, x3: int, y3: int ) -> float:
    a = math.sqrt(math.pow((x2 - x1), 2) + math.pow((y2 - y1), 2))
    b = math.sqrt(math.pow((x3 - x2), 2) + math.pow((y3 - y2), 2))
    c = math.sqrt(math.pow((x1 - x3), 2) + math.pow((y1 - y3), 2))
    p = (a + b + c) / 2
    return math.sqrt(p * (p - a) * (p - b) * (p - c))


def generate_data(filename: str, num: int):
    file = open(filename, 'w', encoding='utf-8')
    for i in range(num):
        figure = random.randint(1, 3)
        color_index = random.randint(0, 7)
        if figure == 1:
            file.write(f"{figure}\n")
            x1 = random.randint(-100, 100)
            y1 = random.randint(-100, 100)
            x2 = random.randint(x1, 100)
            y2 = random.randint(-100, y1)
            while abs(x2 - x1) * abs(y1 - y2) == 0:
                x2 = random.randint(x1, 100) + 1
                y2 = random.randint(-100, y1) - 1
            file.write(f"{x1} {y1} {x2} {y2} {color_index}\n")
        elif figure == 2:
            file.write(f"{figure}\n")
            x1 = random.randint(-100, 100)
            y1 = random.randint(-100, 100)
            x2 = random.randint(-100, 100)
            y2 = random.randint(-100, 100)
            x3 = random.randint(-100, 100)
            y3 = random.randint(-100, 100)
            while triangle_area(x1, y1, x2, y2, x3, y3) == 0:
                x3 = random.randint(-100, 100)
                y3 = random.randint(-100, 100)
            file.write(f"{x1} {y1} {x2} {y2} {x3} {y3} {color_index}\n")
        else:
            file.write(f"{figure}\n")
            x1 = random.randint(-100, 100)
            y1 = random.randint(-100, 100)
            radius = random.randint(1, 100)
            while radius == 0:
                radius = random.randint(1, 100)
            file.write(f"{x1} {y1} {radius} {color_index}\n")
    file.write('0');
    file.close()


if __name__ == '__main__':
    generate_data("test_5_elements.txt", 5)
    print("done")