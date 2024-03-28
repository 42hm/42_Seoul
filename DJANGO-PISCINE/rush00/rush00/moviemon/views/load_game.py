from django.shortcuts import redirect, render
from django.views.generic import TemplateView
from moviemon.dto.GameData import GameData
from moviemon.utils.GameManager import GameManager

LoadIndex = {
    'index': 1,
    'isSelect': False,
}


class Load_game(TemplateView):
	template_name = "moviemon/load_game.html"
	context = {}

	def get(self, request):
		key = request.GET.get('key', None)

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
		temp['but_A'] = "Select Slot"

		if key == 'b':
			return redirect('title')
		elif key == 'a' and GameManager().load_slot_game(LoadIndex['index']) != None:
			print(LoadIndex['isSelect'])
			if LoadIndex['isSelect']:
				LoadIndex['isSelect'] = False
				game = GameManager().load_slot_game(LoadIndex['index'])
				GameManager().save_game(game)
				return redirect('worldmap')
			else:
				LoadIndex['isSelect'] = True
				temp['isSelect'] = LoadIndex['isSelect']
				temp['but_A'] = "Load Slot"
				temp['index'] = LoadIndex['index']
				return render(request, self.template_name, temp)
		else :
			LoadIndex['isSelect'] = False

		if key == 'up' and LoadIndex['index'] > 1:
			LoadIndex['index'] -= 1
		elif key == 'down' and LoadIndex['index'] <= 2:
			LoadIndex['index'] += 1

		temp['index'] = LoadIndex['index']
		return render(request, self.template_name, temp)
