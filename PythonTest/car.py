class Car: 

    number_of_cars = 0
    def __init__(self, make, model, year, color):
        self.make = make
        self.model = model
        self.year = year
        self.color = color
        Car.number_of_cars +=1

    def drive(self):
        print("car", self.model, "is driving")
    
    def stop(self):
        print("car", self.model,"is stopped")

    def number_of_people(cls): #act on class itself, rather than object
        return cls.number_of_cars

    @staticmethod # bound to class rather than object
    def add5():
        number_of_cars+=5


class Truck(Car):
    def __init__(self, make, model, year, color, size):
        super().__init__(make, model, year, color)
        self.size = size
    def drive(self):
        print("sheessh")