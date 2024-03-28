#!/usr/bin/python3

import sys
import antigravity

def main():
    if len(sys.argv) != 4:
        return print("must have 3 argv")
    else:
        try:
            latitude = float(sys.argv[1])
            longtitude = float(sys.argv[2])
            datedow = sys.argv[3].encode("UTF-8")
            antigravity.geohash(latitude, longtitude, datedow)
        except:
            return print("value type error!")

if __name__ == '__main__':
    main()