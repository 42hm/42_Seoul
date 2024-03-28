#!/usr/bin/env python

import sys, requests
from bs4 import BeautifulSoup as bs

def load_trip(text, trace):
    print(text)
    if text in trace:
        print('It leads to an infinite loop !')
        return None, 2
    trace.append(text)
    if text == 'Philosophy':
        return None, 0
    r = requests.get('https://en.wikipedia.org/wiki/' + text.replace(" ", "_"))
    soup = bs(r.text, 'html.parser')
    ps = soup.find_all('p')
    a_cnt = 0
    for p in ps:
        aes = p.find_all('a')
        a_cnt += len(aes)
        for a in aes:
            if '[' not in a.text and ']' not in a.text and '#' not in a.get('href'):
                return a.get('href').replace('/wiki/', ''), 1
    if a_cnt == 0:
        print('It leads to a dead end !')
        return None, 2

def main():
    if len(sys.argv) != 2:
        print("Usage: ./roads_to_philosopy.py <url>")
        return
    cnt = 0
    isdo = 1
    trace = []
    next_text = sys.argv[1]
    try:
        while isdo == 1:
            next_text, isdo = load_trip(next_text, trace)
            cnt += 1
        if isdo == 2:
            print(trace)
            return
        print(f'{cnt} roads from {sys.argv[1]} to philosophy !')
    except Exception as e:
        print("Error:", e)
        return

if __name__ == '__main__':
    main()