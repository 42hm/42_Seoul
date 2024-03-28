import requests

def get_movie_data(title : str):
    key = "5f3fec77"
    url = "http://www.omdbapi.com/?apikey={}&t={}&type=movie&plot=flot&r=json".format(key, title)
    try :
        res = requests.get(url)
        res.raise_for_status()
        dic = eval(res.text)
    except Exception as e:
        assert e
        dic = {}
    return dic



if __name__ == '__main__' :
    print(get_movie_data("kong"))



