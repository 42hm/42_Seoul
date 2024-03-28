#!/usr/bin/python3

import sys

def my_func():
	states = {
	"Oregon" : "OR",
	"Alabama" : "AL",
	"New Jersey": "NJ",
	"Colorado" : "CO"
	}
	capital_cities = {
	"OR": "Salem",
	"AL": "Montgomery",
	"NJ": "Trenton",
	"CO": "Denver"
	}
	if len(sys.argv) != 2:
		return
	lst = sys.argv[1].split(",")
	for index in lst:
		index = index.strip()
		if index == "":
			continue
		if not (find_state_or_capital(index, states, capital_cities)):
			print(index + " is neither a capital city nor a state")

def find_state_or_capital(index, states, capital_cities):
    done = False
    for key, value in states.items():
        if key.upper() == index.upper():
            print(capital_cities.get(value) + " is the capital of " + key)
            done = True
            return done
        for key2, value2 in capital_cities.items():
            if value2.upper() == index.upper():
                if value == key2:
                    print(value2 + " is the capital of " + key)
                    done = True
                    return done
    return done

if __name__ == '__main__':
	my_func()
