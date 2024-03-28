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
	done = False
	for key, value in capital_cities.items():
		if value == sys.argv[1]:
			for key2, value2 in states.items():
				if value2 == key:
					done = True
					print(key2)
					break
			break
	if not done:
		print("Unknown capital city")

if __name__ == '__main__':
	my_func()
