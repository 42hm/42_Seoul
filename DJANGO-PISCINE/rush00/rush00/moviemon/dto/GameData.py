from django.conf import settings

from moviemon.utils.GameManager import GameManager


class GameData():
    def __init__(self):
        self.player_pos = settings.PLAYER_INIT_POS
        self.player_strength = settings.PLAYER_STRENGTH
        self.movie_ball_count = settings.MOVIE_BALL_INIT_COUNT
        self.captured_movie = []
        self.all_movies = []
        self.worldmap =[]


    def __getitem__(self, key) :
        return getattr(self, key)

    def __str__(self):
        return str({
            'player_pos' : self.player_pos,
            'player_strength' : self.player_strength,
            'movie_ball_count' : self.movie_ball_count,
            'captured_movie' : self.captured_movie,
            'all_movies' : self.all_movies,
            'worldmap' : self.worldmap
        })


    # settings으로부터 클래스 인스턴스에 있는 게임 데이터를 불러옵니다.
    # IMDb로부터 무비몬 데이터를 리퀘스트하여 불러옵니다. 현재 인스턴스를 반환합니다.
    @staticmethod
    def load_default_settings():
        answer = GameData()
        answer.all_movies = GameManager.init_movies_data()
        answer.worldmap = GameManager.init_worldmap()
        return answer


    #클래스 인스턴스의 패러미터로 받아온 게임 데이터를 불러옵니다. 현재 인스턴스를 반환합니다
    @staticmethod
    def load(data):
        answer = GameData()
        answer.player_pos = data['player_pos']
        answer.player_strength = data['player_strength']
        answer.movie_ball_count = data['movie_ball_count']
        answer.captured_movie = data['captured_movie']
        answer.all_movies = data['all_movies']
        answer.worldmap = data['worldmap']
        return answer

    #게임 데이터를 반환합니다.
    def dump(self):
        return {
            'player_pos' : self.player_pos,
            'player_strength' : self.player_strength,
            'movie_ball_count' : self.movie_ball_count,
            'captured_movie' : self.captured_movie,
            'all_movies' : self.all_movies,
            'worldmap' : self.worldmap
        }

    #현재 플레이어의 강함(을 리턴합니다.
    def get_setrength(self):
        return self.player_strength

    # 패러미터로 받은 무비몬의 이름과 Detail 페이지에서 필요로 하는 모든 상세 데이터를 Python 딕셔너리에 저장하여 반환합니다.
    def get_movie(self, title : str):
        for movie in self.all_movies:
            if str(movie['title']) == str(title) :
                return movie.dump()
        return None


def test():
    pass

if __name__ == '__main__' :
    test()
