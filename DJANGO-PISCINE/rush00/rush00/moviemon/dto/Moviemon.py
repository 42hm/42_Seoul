

class Moviemon :
    def __init__(self,
                 title = "제목",
                 post_url = "https://noticon-static.tammolo.com/dgggcrkxq/image/upload/v1592437592/noticon/yucvpr6jzidhqlja5zxq.png",
                 director = "감독",
                 year = "년도",
                 rating = "평점",
                 plot = "설명",
                 isCapture = False):
        self.title = title
        self.post_url = post_url
        self.director = director
        self.year = year
        self.rating = rating
        self.plot = plot
        self.isCapture = isCapture

    def __getitem__(self, key) :
        return getattr(self, key)

    def __str__(self):
        return str(self.dump())
    def dump(self):
        return {
            "title": self.title,
            "post_url": self.post_url,
            "director" : self.director,
            "year" : self.year,
            "rating" : self.rating,
            "plot" : self.plot,
            "isCapture" : self.isCapture
        }

    def captured(self):
        self.isCapture = True
