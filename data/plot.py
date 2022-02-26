import matplotlib.pyplot as plot

class Trans:
    def __init__(self, index, x, y):
        self.index = index
        self.x = x
        self.y = y
    
    def __str__(self):
        return "(%d, %d)" % (self.x, self.y)

file_name = "/home/congxiang/work/TrafficSimulator/data/time_space.txt"
color_table = ["#00FF00", "#0000FF", "#FF0000"]
length = len(color_table)

persons = []
cars = []

with open(file_name) as fin:
    lines = fin.readlines()

for line in lines:
    if line == '\n':
        continue
    data = line.strip().split(";")
    
    y = int(data[0].strip().split(" ")[0])
    
    persons_data = data[1].strip().split(":")
    for i in range(len(persons_data)):
        if persons_data[i] != '':
            person_data = persons_data[i].strip().split(" ")
            
            person = Trans(int(person_data[0]), int(person_data[1]), y)
            persons.append(person)

    cars_data = data[2].strip().split(":")
    for i in range(len(cars_data)):
        if cars_data[i] != '':
            car_data = cars_data[i].strip().split(" ")

            car = Trans(int(car_data[0]), int(car_data[1]), y)
            cars.append(car)

coords_x = []
coords_y = []
colors = []

for person in persons:
    coords_x.append(person.x)
    coords_y.append(person.y)
    color = color_table[person.index % length]
    colors.append(color)

plot.figure(dpi=3000)
plot.title("person", fontsize=14)
plot.xlabel("coord", fontsize=14)
plot.ylabel("time", fontsize=14)
plot.tick_params(axis="both", which="major", labelsize=7)
plot.scatter(coords_x, coords_y, c=colors, edgecolor="none", s=0.5)
plot.savefig("person.png")
plot.close('all')

coords_x.clear()
coords_y.clear()
colors.clear()
for car in cars:
    coords_x.append(car.x)
    coords_y.append(car.y)
    color = color_table[car.index % length]
    colors.append(color)

plot.figure(dpi=3000)
plot.title("car", fontsize=14)
plot.xlabel("coord", fontsize=14)
plot.ylabel("time", fontsize=14)
plot.tick_params(axis="both", which="major", labelsize=7)
plot.scatter(coords_x, coords_y, c=colors, edgecolor="none", s=0.5)
plot.savefig("car.png")
plot.close('all')


