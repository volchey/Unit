class HotBeverage:
    def __init__(self, price = 0.3, name = 'hot beverage'):
        self.price = price
        self.name = name

    def __str__(self):
        str1 = 'name : ' + self.name + "\n"
        str2 = 'price : ' + "%.2f" % self.price + "\n"
        str3 = 'description : ' + self.description() + "\n"
        return str1 + str2 + str3

    def description(self):
        return "Just some hot water in a cup."

class Coffee (HotBeverage):
    def __init__(self, price = 0.40, name = "coffee"):
        HotBeverage.__init__(self, price, name)
    
    def description(self):
        return "A coffee, to stay awake."
    
class Tea (HotBeverage):
    def __init__(self, price = 0.30, name = "tea"):
        HotBeverage.__init__(self, price, name)

class Chocolate (HotBeverage):
    def __init__(self, price = 0.50, name = "chocolate"):
        HotBeverage.__init__(self, price, name)

    def description(self):
        return "Chocolate, sweet chocolate..."

class Cappuccino (HotBeverage):
    def __init__(self, price = 0.45, name = "cappuccino"):
        HotBeverage.__init__(self, price, name)

    def description(self):
        return "Un po’ di Italia nella sua tazza!"

if __name__ == '__main__':
    print(HotBeverage())
    print(Coffee())
    print(Tea())
    print(Chocolate())
    print(Cappuccino())