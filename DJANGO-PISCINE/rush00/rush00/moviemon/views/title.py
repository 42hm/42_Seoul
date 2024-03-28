from django.shortcuts import redirect, render
from django.views.generic import TemplateView
from moviemon.dto.GameData import GameData
from moviemon.utils.GameManager import GameManager


class Title(TemplateView):
	template_name = "moviemon/title.html"

	def get(self, request):

		key = request.GET.get('key', None)
		if key == 'a':
			game = GameData().load_default_settings().dump()
			GameManager.save_game(game)
			return redirect('worldmap')
		elif key == 'b':
			return redirect('load_game')
		else:
			return render(request, self.template_name)
