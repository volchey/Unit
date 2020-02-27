import beverages
import random

class CoffeeMachine:
    def __init__(self):
        self.serve_count = 0

    class EmptyCup (beverages.HotBeverage):
        def __init__(self, price = 0.90, name = "empty cup"):
            beverages.HotBeverage.__init__(self, price, name)
       
        def description(serlf):
            return "An empty cup ?! Gimme my money back!"

    class BrokenMachineException (Exception):
        def __init__(self):
            Exception.__init__(self, "This coffee machine has to be repaired.")

    def repair(self):
        self.serve_count = 0

    def serve(self, obj: beverages.HotBeverage):
        if (self.serve_count > 9):
            raise self.BrokenMachineException()
        
        if random.randint(0, 1):
            self.serve_count = self.serve_count + 1
            # print (self.serve_count)
            return obj
        else:
            return self.EmptyCup()

if __name__ == '__main__':

    machine = CoffeeMachine()
    for i in range(0, 8):
        try:
            print(machine.serve(beverages.HotBeverage()))
            print(machine.serve(beverages.Coffee()))
            print(machine.serve(beverages.Tea()))
            print(machine.serve(beverages.Chocolate()))
            print(machine.serve(beverages.Cappuccino()))
        except Exception as a:
            print("***************** Warning ********************")
            print(a)
            print("==============================================\n")
            machine.repair()
    

