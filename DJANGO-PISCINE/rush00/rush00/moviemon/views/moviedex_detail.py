from django.shortcuts import redirect, render
from django.views.generic import TemplateView
from moviemon.dto.GameData import GameData
from moviemon.utils.GameManager import GameManager


class Moviedex_detail(TemplateView):
	template_name = "moviemon/moviedex_detail.html"
	context = {}

	def get(self, request, moviemon_id):
		game = GameManager().load_game()
		game_class = GameData().load(game)
		key = request.GET.get("key", None)

		if key == 'b':
			return redirect('moviedex')
		else:
			return render(request, self.template_name, game_class.get_movie(moviemon_id))
