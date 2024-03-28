#!/usr/bin/python3

import sys

def my_func():
	states = { #앞이 KEY
	"Oregon" : "OR",
	"Alabama" : "AL",
	"New Jersey": "NJ",
	"Colorado" : "CO"
	}
	capital_cities = {
	"OR": "Salem",
	"AL": "Montgomery",
	"NJ": "Trent"
	"CO": "Denver"
	}
	if len(sys.argv) != 2:
		return
	index = states.get(sys.argv[1])
	if states.get(sys.argv[1]):
		print(capital_cities.get(index))
	else:
		print("Unknwon state")
		return

if __name__ == '__main__':
	my_func()
