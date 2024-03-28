from django.shortcuts import redirect, render
from django.views.generic import TemplateView
from moviemon.dto.GameData import GameData
from moviemon.utils.GameManager import GameManager

class Prebattle(TemplateView):
	template_name = "moviemon/prebattle.html"
	context = {}

	def get(self, request):
		game = GameManager().load_game()
		key = request.GET.get("key", None)

		now_x, now_y = game['player_pos']
		worldmap = game['worldmap']

		movie_id = worldmap[now_y][now_x] - 10

		movie_list = game['all_movies']

		if key == 'a':
			return redirect('battle', moviemon_id= movie_list[movie_id]['title'])
		else:
			return render(request, self.template_name)
