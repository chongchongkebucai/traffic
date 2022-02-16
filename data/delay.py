file_name = "/home/congxiang/traffic/data/delay.txt"

with open(file_name) as fin:
    lines = fin.readlines()

person_num = 0
car_num = 0
person_delays = 0
car_delays = 0

for line in lines:
    if line == '\n':
        continue
    
    data = line.strip().split()
    trans_type = int(data[0])
    delay = int(data[1])
    
    if trans_type == 1:
        person_num += 1
        person_delays += delay    
    elif trans_type == 2:
        car_num += 1
        car_delays += delay


person_avg_delay = person_delays / person_num
car_avg_delay = car_delays / car_num
print("person:\n\tsum of person delay is %d, \n\tthe number of perosn are %d, \n\taverage delay is %f" %(person_delays, person_num, person_avg_delay))
print("car:\n\tsum of car delay is %d, \n\tthe number of car are %d, \n\taverage delay is %f" %(car_delays, car_num, car_avg_delay))
