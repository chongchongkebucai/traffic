import matplotlib.pyplot as plot

times = []
person_coords = []
car_coords = []

persons_coord_x = []
persons_coord_y = []
cars_coord_x = []
cars_coord_y = []
 
file_name = "/home/congxiang/work/TrafficSimulator/data/traffic_data.txt"
with open(file_name) as fin:
    lines = fin.readlines()

for line in lines:
    if line == '\n':
        continue
    coords = line.strip().split(";")
    
    x = int(coords[0].strip().split(" ")[0])
    ys = coords[1].strip().split(" ")
    for i in range(len(ys)):
        y = int(ys[i])
        persons_coord_x.append(x)
        persons_coord_y.append(y)
    ys = coords[2].strip().split(" ")
    for i in range(len(ys)):
        y = int(ys[i])
        cars_coord_x.append(x)
        cars_coord_y.append(y)

plot.figure(dpi=3000)
plot.title("person", fontsize=14)
plot.xlabel("time", fontsize=14)
plot.ylabel("coord", fontsize=14)
plot.tick_params(axis="both", which="major", labelsize=7)
plot.scatter(persons_coord_x, persons_coord_y, color='b', edgecolor="none", s=0.2)
plot.savefig("person.png")
plot.close('all')

plot.figure(dpi=3000)
plot.title("car", fontsize=14)
plot.xlabel("time", fontsize=14)
plot.ylabel("coord", fontsize=14)
plot.tick_params(axis="both", which="major", labelsize=7)
plot.scatter(cars_coord_x, cars_coord_y, color='r', edgecolor="none", s=0.2)
plot.savefig("car.png")
plot.close('all')


