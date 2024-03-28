#!/usr/bin/python3

import random
from beverages import *

class CoffeeMachine:

    class EmptyCup(HotBeverage):
        def __init__(self):
            HotBeverage.__init__(self, 0.90, "empty cup")
        def description(self):
            return "An empty cup?! Gimme my money back!"

    class BrokenMachineException(Exception):
        def __init__(self):
            super().__init__("This coffee machine has to be repaired.")

    def __init__(self):
        self.count = 10

    def repair(self):
        self.count = 10

    def serve(self, drink):
        if self.count <= 0:
            raise CoffeeMachine.BrokenMachineException()
        if random.randint(1,3) == 2:
            self.count -= 1
            return CoffeeMachine.EmptyCup()
        return drink()

def main():
    coffeeMachine = CoffeeMachine()
    for x in range(30):
        try:
            print(coffeeMachine.serve(random.choice(
                [Coffee, Tea, Cappuccino, Chocolate])))
        except CoffeeMachine.BrokenMachineException as e:
            print(e)
            coffeeMachine.repair()


if __name__ == '__main__':
    main()
