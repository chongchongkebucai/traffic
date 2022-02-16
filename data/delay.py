file_name = "/home/congxiang/traffic/data/delay.txt"

with open(file_name) as fin:
    lines = fin.readlines()

num = 0
delays = 0
for line in lines:
    if line == '\n':
        continue
    
    num = num + 1
    data = line.strip()
    delay = int(data[0])

    delays += delay

avg_delay = delays / num
print(delays)
print(num)
print(avg_delay)