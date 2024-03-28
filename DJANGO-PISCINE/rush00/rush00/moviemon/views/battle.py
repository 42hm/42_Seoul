from django.shortcuts import redirect, render
from django.views.generic import TemplateView
from moviemon.dto.GameData import GameData
from moviemon.utils.GameManager import GameManager
import random


class Battle(TemplateView):
	template_name = "moviemon/battle.html"
	context = {}

	def get(self, request, moviemon_id):
		game = GameManager().load_game()
		key = request.GET.get("key", None)
		now_x, now_y = game['player_pos']
		worldmap = game['worldmap']
		self.text = None

		if worldmap[now_y][now_x] == 0 :
			#redirect
			# 저장
			# print("0임 ㅋ")
			self.text = "잡았다!"
			if key == 'a' :
				return redirect('worldmap')

		elif key == 'a' and game['movie_ball_count'] >= 1:
			self.text = "놓쳤다"
			if GameManager().throwball(int(self.calculate_winning_rate(game, moviemon_id))): # 잡았는지 여부 T/F
				game = GameManager().load_game()
				now_x, now_y = game['player_pos']
				game['worldmap'][now_y][now_x] = 0
				game_class = GameData.load(game)

				game['captured_movie'].append(game_class.get_movie(moviemon_id))
				self.text = "잡았다!"

				GameManager.save_game(game)

		elif key == 'b' and worldmap[now_y][now_x] != 0:
			index = game['worldmap'][now_y][now_x]
			game['worldmap'][now_y][now_x] = 0
			while True:
				next_x = random.randint(0, 9)
				next_y = random.randint(0, 9)
				if game['worldmap'][next_y][next_x] == 0 and not (now_x == next_x and now_y == next_y):
					game['worldmap'][next_y][next_x] = index
					break
			GameManager().save_game(game)
			return redirect('worldmap')

		game_class = GameData().load(game)
		temp = dict()
		temp['game'] = game
		temp['movie'] = game_class.get_movie(moviemon_id)
		temp['sibal'] = self.calculate_winning_rate(game, moviemon_id)
		if key != None and self.text != None:
			temp['text'] = self.text

		return render(request, self.template_name, temp)

	def calculate_winning_rate(self, game, moviemon_id):
		temp = GameData().load(game)
		print(moviemon_id)
		print(temp.get_movie(moviemon_id)['rating'])
		return 50 - float(temp.get_movie(moviemon_id)['rating']) * 10 + float(game['player_strength']) * 5
