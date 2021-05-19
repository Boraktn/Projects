def fcfs(input):
  output.write("First Come First Serve Scheduling"+"\n")
  output.write("\n")
  list=[]
  for i in range(len(input)):
      min = input[0]
      #print(i)
      for j in input:
          if  j[1] < min[1]:
              #print(j)
              min = j
      list = list + [min]
      #print(list)
      output.write("Will run Name: "+list[i][0]+"\n")
      output.write("Priority: " + list[i][2]+"\n")
      output.write("Burst: " + list[i][3]+"\n")
      output.write("\n")
      output.write("Task "+list[i][0]+" Finished"+"\n")
      output.write("\n")
      input.pop(input.index(min))


def sjf(input):
    output.write("Shortest Job First Scheduling" + "\n")
    output.write("\n")
    #print("Shortest Job First Scheduling")
    list = []
    arrived=[]
    storage= []
    now = 0
    for i in range(len(input)):
        min = input[0]
        # print(i)
        if list == []:
            for j in input:
                # print(j)
                if j[1] < min[1]:
                    # print(j)
                    min = j
            now = now + int(min[1])
        else:
            for j in arrived:
            # print(j)
                if j[3] < min[3]:
                # print(j)
                    min = j
            arrived.remove(min)
        list = list + [min]
        now = now + int(min[3])
        for ln in input:
            if int(ln[1]) < now and ln not in storage:
                arrived.append(ln)
                storage.append(ln)
        #print(list)
        output.write("Will run Name: " + list[i][0] + "\n")
        output.write("Priority: " + list[i][2] + "\n")
        output.write("Burst: " + list[i][3] + "\n")
        output.write("\n")
        output.write("Task " + list[i][0] + " Finished" + "\n")
        output.write("\n")
        input.pop(input.index(min))


def pri(input):
    output.write("Priority Scheduling" + "\n")
    output.write("\n")
    #print("Priority Scheduling")
    list = []
    arrived=[]
    storage= []
    now = 0
    for i in range(len(input)):
        min = input[0]
        # print(i)
        if list == []:
            for j in input:
                # print(j)
                if j[1] < min[1]:
                    # print(j)
                    min = j
            now = now + int(min[1])
        else:
            #print(arrived)
            for j in arrived:
            # print(j)
                if j[2] <= min[2]:
                # print(j)
                    #print(j)
                    min = j
                #print(arrived)
                #print("hüğ")
            arrived.remove(min)
            #print(arrived)
        list = list + [min]
        now = now + int(min[3])
        for ln in input:
            if int(ln[1]) < now and ln not in storage:
                arrived.append(ln)
                storage.append(ln)
        #print(list)
        output.write("Will run Name: " + list[i][0] + "\n")
        output.write("Priority: " + list[i][2] + "\n")
        output.write("Burst: " + list[i][3] + "\n")
        output.write("\n")
        output.write("Task " + list[i][0] + " Finished" + "\n")
        output.write("\n")
        input.pop(input.index(min))


def rr(input):
    output.write("Round Robin Scheduling" + "\n")
    output.write("\n")
    list = []
    for i in range(len(input)):
        min = input[0]
        # print(i)
        for j in input:
            #print(min)
            #print(j)
            #print()
            if j[1] < min[1]:
                # print(j)
                min = j
        list = list + [min]
        if len(list) == 1:
            minn = input.pop(input.index(min))
        else:
            input.pop(input.index(min))
    #arrived = []
    storage = []
    for i in list:
        storage.append(0)
    now = int(minn[1])
    i = 0
    #print(list)
    while list != []:
        list[i][3] = int(list[i][3]) - 10
        storage[i] = storage[i] + 10
        output.write("Will run Name: " + list[i][0] + "\n")
        output.write("Priority: " + list[i][2] + "\n")
        output.write("Burst: " + str(list[i][3]+storage[i]) + "\n")
        output.write("\n")
        now = now + list[i][3]
        if list[i][3] <= 0:
            output.write("Task " + list[i][0] + " Finished" + "\n")
            output.write("\n")
            dl = i
            #print(list)
            #print(i)
            #print()
            if len(list)-1 == i: #or# deleted[1] == list[i]:
                i = 0
            elif int(list[i+1][1])>now:
                i = 0
            list.pop(dl)
            storage.pop(dl)
        else:
            if len(list)-1 != i and int(list[i+1][1])<now:
                i = i + 1
            else:
                i = 0
inp1= input("Name of the scheduling algorithm: ") #type
inp2= input("Name of the file: ") #name
file = open(inp2+".txt", "r")
output = open("output.txt", "w")
input = file.readlines()
input=input[::2]
for i in range(len(input)):
    #x = input[i]
    input[i] = input[i].split(",")
    #print(input)
    input[i][3] = input[i][3].replace("\n", "")
if inp1 == "fcfs":
    fcfs(input)
elif inp1 == "sjf":
    sjf(input)
elif inp1 == "pri":
    pri(input)
elif inp1 == "rr":
    rr(input)