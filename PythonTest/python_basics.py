#data types
# int
from re import S


a = 9
#float 
b = 10.5
#string 
string = "hello"
#bool
bool = True

#print
string_world = "hello world"
print(string_world)

#input
#name = input("Name: ")
#print("hello", name)

x = 9
y = 3
result = (int)(x/y) #divide returns float
print(result)
result = x**y
print(result)

#num = input("number: ") #convert to int!! this is string
#print(int(num) - 5)

# string methods
hello = 'hello'.upper()
print(hello.count('LL'))

x = 'hello'
y = 3
print(x * y)

#comparisons
x = "hello"
y = "hello"
z = 'lol'
print(x == y)
print(ord('a')) # print char as a numerical value for comparison

#and, or, not
#if statement
x = "hello"
if (x == 'hello'):
    print("hello")
elif (x == 'bye'):
    print("bye")
else:
    print("lol")

#list
x = [4, True, 'hi'] 
x.append(4)
x.extend([3, 4])
x.pop()
print(x)
y = len(x)
print(y)
x[0] = 'lol'
print(x)

#tuple (cannot be changed)
x= (0, 0, 2, 2)
print(x)

#for loop
for i in range(1, 10, 2): #range args: start, stop, step
    print(i)

for i in [3, 4, 42, 3]: #range args: start, stop, step
    print(i)

for i in range(len(x)): #range args: start, stop, step
    print(x[i], end = " ")

#while loop
i=0
while i<10:
    print('i')
    i+=1
    break

#slice
sliced = x[0:4:2]
print(sliced)

#set, faster to add, remove, checking things than list
x = set()
s = {4, 32, 2, 2}
s.add(5)
s.remove(5)
s2 = {2, 3, 1}
print(s)
print(32 in s)
print(s.union(s2)) #difference, intersection

#dictionary
x = {'key': 4}
print(x['key'])
x[2] = "LOLOL"
x['key2'] = 5
print(x)
print(list(x.values()))
print(list(x.keys()))
del x['key']
print(x)

for key, value in x.items():
    print(key, value)

#comprehension, wtf is this shit
x = [x+5 for x in range(5)]
print(5)

#function 
def func(x, y, z=None):
    print('run', x, y, z)
    return x*y, x/y

print(func(5,6,7))
r1, r2 = func(5,6)
print(r1, r2)

def func(x):
    def func2():
        print(x)

    return func2

x = func(3)
print(x)

#args, **kwargs
def func(x, y):
    print(x,y)

x = [1,2,3,4]
print(*x) #unpack, separate all elements in list
pairs = [(1,2), (3,4)]

func(**{'y':5, 'x':2,})

for pair in pairs:
    func(*pairs)

def func(*args, **kwargs):
    print(*args)

func(1,2,3,4,5, one=0, two=1)

#global and scope
x = 'lol'
def func(huh):
    x = huh

func("xdd")
print(x) #x cant get changed in function

#exception
#raise Exception('bad')
#try: 
#    x = 7/0
#except Exception as e:
#    print(e)
#finally:
#    print('finally')

#lambda
x = lambda x, y: x+y
print(x(2,3))

#map and filter
x = [1,2,3,4,5,313,2,23]

def func(i):
    i=i*3
    return i%2==0

mp = map(lambda i: i+2, x)
mp = filter(func, x)
print(list(mp))

#fstring
tim = 89
x = f'hello {6 + 8} [tim] '
print(x)

#Object Oriented Programming
from car import Car #import class from another file
from car import Truck #import class from another file

car_1 = Car("honda", "civic", 2022, "black")
print(car_1.make, car_1.model, car_1.year, car_1.color)
car_1.drive()
car_1.stop()

car_2 = Car("Ford", "Mustang", 2022, "red")
car_2.stop()
print(Car.number_of_cars)

truck = Truck("Ford", "Mustang", 2022, "red", 10)
truck.drive()