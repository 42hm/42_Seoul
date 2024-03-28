#!/usr/bin/env python
import sys, json, dewiki, requests


def main():
    if len(sys.argv) == 2:
        try:
            URL = "https://en.wikipedia.org/w/api.php"
            PARAMS = {
                "action": "parse",
                "page": sys.argv[1].title(),
                "prop": "wikitext",
                "format": "json",
                "redirects": True
            }
            S = requests.Session()
            try:
                R = S.get(url=URL, params=PARAMS)
                R.raise_for_status()
            except requests.HTTPError as e:
                return print(e)
            try:
                data = json.loads(R.text)
            except Exception as e:
                return print(e)
            try:
                data['parse']['wikitext']['*']
            except Exception as e:
                return print(e)
            try:
                with open(sys.argv[1].replace(" ", "_") + ".wiki", "w") as f:
                    f.write(dewiki.from_string(data["parse"]["wikitext"]["*"]))
            except Exception as e:
                return print(e)
        except Exception as e:
            return print(e)
    else:
        print("argv must 1")

if __name__ == '__main__':
    main()