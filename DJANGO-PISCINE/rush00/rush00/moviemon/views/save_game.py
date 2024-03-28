from django.shortcuts import redirect, render
from django.views.generic import TemplateView
from moviemon.dto.GameData import GameData
from moviemon.utils.GameManager import GameManager

SaveIndex = {
    'index': 0
}


class Save_game(TemplateView):
	template_name = "moviemon/save_game.html"
	context = {}

	def get(self, request):
		game = GameManager().load_game()
		key = request.GET.get('key', None)

		if key == 'b':
			return redirect('options')

		temp = dict()
		aslot = GameManager().load_slot_game(1)
		temp['a_captured_monster'] = 0 if aslot == None else len(aslot['captured_movie'])
		temp['a_all_monster'] = 0 if aslot == None else len(aslot['all_movies'])
		bslot = GameManager().load_slot_game(2)
		temp['b_captured_monster'] = 0 if bslot == None else len(bslot['captured_movie'])
		temp['b_all_monster'] = 0 if bslot == None else len(bslot['all_movies'])
		cslot = GameManager().load_slot_game(3)
		temp['c_captured_monster'] = 0 if cslot == None else len(cslot['captured_movie'])
		temp['c_all_monster'] = 0 if cslot == None else len(cslot['all_movies'])


		if key == 'up' and SaveIndex['index'] != 0:
			SaveIndex['index'] -= 1
		elif key == 'down' and SaveIndex['index'] != 2:
			SaveIndex['index'] += 1
		elif key == 'a':
			GameManager().save_slot_game(game, SaveIndex['index'] + 1)
			return redirect('worldmap')
		# elif key == 'start':
		# 	return redirect('worldmap')
		temp['index'] = SaveIndex['index']
		return render(request, self.template_name, temp)