import os
from django.conf import settings

from moviemon.utils.omdb import get_movie_data
from moviemon.dto.Moviemon import Moviemon
import random
import pickle


class GameManager:

    def __init__(self):
        pass

    #
    # 데이터 전처리
    #

    @staticmethod
    def init_worldmap():
        map_list = []

        for i in range(settings.TABLE_SIZE) :
            temp = []
            for _ in range(settings.TABLE_SIZE) :
                temp.append(0)
            map_list.append(temp)

        map_list = GameManager.init_monster_position(map_list)
        map_list = GameManager.add_ball_position(map_list, settings.MOVIE_BALL_INIT_FIELD_COUNT)

        return map_list

    @staticmethod
    def init_monster_position(map_list):

        for i in range(10):
            x, y = (0, 0)
            while True :
                pos = random.randint(0,99)
                x, y = divmod(pos, 10)
                if map_list[y][x] == 0 and (x, y) != settings.PLAYER_INIT_POS:
                    break
            map_list[y][x] = 10 + i
        return map_list

    @staticmethod
    def add_ball_position(map_list, num):

        for i in range(num):
            x, y = (0, 0)
            while True :
                pos = random.randint(0,99)
                x, y = divmod(pos, 10)
                if map_list[y][x] == 0 :
                    break
            map_list[y][x] = 2
        return map_list


    @staticmethod
    def init_movies_data():
        ran = random.choice([True, False])

        movie_list = []

        movie_title_list = settings.MOVIE_TITLE_1 if ran else settings.MOVIE_TITLE_2
        for i in range(10) :
            data = get_movie_data(movie_title_list[i])
            movie = Moviemon(
                data['Title'],
                data['Poster'],
                data['Director'],
                data['Released'],
                data['imdbRating'],
                data['Plot'],
                False
            )
            movie_list.append( movie )
        return movie_list

    #
    # 게임 데이터 저장 불러오기
    #


    @staticmethod
    def save_game(game):
        if not os.path.isdir("now_game"):
            os.mkdir("now_game")
        try:
            f = open("now_game/data.bin", "wb")
            pickle.dump(game, f)
            f.close()
            return game
        except:
            return None

    @staticmethod
    def save_slot_game(game, num : int):
        if not os.path.isdir("slot_game"):
            os.mkdir("slot_game")
        try:
            game = GameManager().load_game()
            code = None
            cap_m = len(game['captured_movie'])
            all_m = len(game['all_movies'])
            file_path = "slot_game/slot{}_{}_{}.mmg"

            if num == 1:
                code = 'A'
                # f = open(file_path.format('A', cap_m, all_m), 'wb')
                print("Yesdd")
            elif num == 2:
                code = 'B'
                # f = open(file_path.format('B', cap_m, all_m), 'wb')
            elif num == 3:
                code = 'C'
                # f = open(file_path.format('C', cap_m, all_m), 'wb')
            else :
                pass

            files = os.listdir("slot_game/")
            print("files = " , files)
            for file in files :
                if code in str(file) :
                    os.remove("slot_game/" + file)

            f = open(file_path.format(code, cap_m, all_m), 'wb')


            print("###", f)
            pickle.dump(game, f)
            print("###", game)
            f.close()
            return game
        except:
            return None

    @staticmethod
    def load_game():
        try:
            f = open("now_game/data.bin", 'rb')
            game = pickle.load(f)
            f.close()
            return game
        except:
            return None

    @staticmethod
    def load_slot_game(num : int):
        try:
            #######
            code = None
            #######
            if num == 1 :
                code = 'A'
            elif num == 2:
                code = 'B'
            elif num == 3:
                code = 'C'
            else :
                return None

            files = os.listdir("slot_game/")

            f = None
            print("code " , code)
            print("files " , files)
            for file in files :
                print("!@#!@#" ,file)
                if code in str(file) :
                    print("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
                    f = open("slot_game/" + file, 'rb')

            game = pickle.load(f)
            f.close()
            return game
        except Exception as e:
            return None


    #
    # 행동
    #
    @staticmethod
    def move(x : int, y : int) :
        game = GameManager.load_game()
        now_x, now_y = game['player_pos']
        print(x, y)
        if now_x + x >= settings.TABLE_SIZE :
            return
        if now_x + x < 0:
            return
        if now_y + y >= settings.TABLE_SIZE :
            return
        if now_y + y < 0:
            return

        game['player_pos'] = (now_x + x, now_y + y)
        GameManager.save_game(game)


    @staticmethod
    def throwball(percent : int):
        game = GameManager.load_game()
        game['movie_ball_count'] = 0 if game['movie_ball_count'] <= 0 else game['movie_ball_count'] - 1
        GameManager.save_game(game)

        rand_list = []
        for i in range(percent):
            rand_list.append(True)
        for i in range(100 - percent):
            rand_list.append(False)
        random.shuffle(rand_list)
        num = random.randint(0, 99)
        if not rand_list[num] :
            return False
        return True


    #
    #기타
    #

    #무비몬들 중 아직 포획하지 않은 랜덤한 무비몬을 반환합니다.
    @staticmethod
    def get_random_movie():
        game = GameManager.load_game()
        monsters = game['all_movies']
        while True:
            i = random.randint(0, 9)
            if monsters[i]['isCapture'] :
                return monsters[i]

