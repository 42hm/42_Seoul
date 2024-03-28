# from rush00.moviemon.views.prebattle import Prebattle
from django.shortcuts import redirect, render
from django.views.generic import TemplateView
from moviemon.dto.GameData import GameData
from moviemon.utils.GameManager import GameManager
from django.conf import settings

IsState = {
    'isBattle': False,
    'isWin':False,
    'moviemon_id': ''
}


class Worldmap(TemplateView):
	template_name = "moviemon/worldmap.html"
	context = {}

	def get(self, request):
		game = GameManager().load_game()
		key = request.GET.get("key", None)

		# 이겻는지 체크
		count = 0
		movie_list = game['all_movies']
		for movie in movie_list :
			if movie['isCapture'] :
				count += 1
		if count == 10 :
			IsState['isWin'] == True
			return render(request, self.template_name, IsState)

		if IsState['isBattle']:
			if key == 'a':
				IsState['isBattle'] = False
				return redirect('battle', IsState['moviemon_id'])
			else:
				return render(request, self.template_name, IsState)

		now_x, now_y = game['player_pos']
		worldmap = game['worldmap']
		game['x'] = str(now_x)
		game['y'] = str(now_y)
		if 10 <= worldmap[now_y][now_x] and worldmap[now_y][now_x] < 20 :
			IsState['isBattle'] = True
			IsState['moviemon_id'] = movie_list[worldmap[now_y][now_x] - 10]['title']
			return render(request, self.template_name, IsState)
			# return redirect('prebattle')
		if worldmap[now_y][now_x] == 2 :
			worldmap[now_y][now_x] = 0
			game['movie_ball_count'] += 5
			GameManager().save_game(game)
			return render(request, self.template_name, game)
		if key == 'select':
			# 저장
			return redirect('moviedex')
		if key == 'start':
			# 저장
			return redirect('options')
		if key == 'up':
			GameManager().move(0, -1)
		elif key == 'down':
			GameManager().move(0, 1)
		elif key == 'left':
			GameManager().move(-1, 0)
		elif key == 'right':
			GameManager().move(1, 0)
		# 저장
		game = GameManager().load_game()
		now_x, now_y = game['player_pos']
		game['x'] = str(now_x)
		game['y'] = str(now_y)
		return render(request, self.template_name, game)
