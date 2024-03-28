from django.shortcuts import redirect, render
from django.views.generic import TemplateView
from moviemon.dto.GameData import GameData
from moviemon.utils.GameManager import GameManager

CurrentIndex = {
    'index': 0
}



class Moviedex(TemplateView):
	template_name = "moviemon/moviedex.html"
	context = {}

	def get(self, request):
		game = GameManager().load_game()
		key = request.GET.get("key", None)

		game['index'] = CurrentIndex['index']
		captured_count = len(game['captured_movie'])
		print(CurrentIndex['index'])

		# dictionary = {i : game['captured_movie'][i] for i in range(captured_count)}
		# print(dictionary)
		# movie = {}
		# movie['movies'] = game['captured_movie']
		# print(movie)

		if key == 'a' and captured_count != 0:
			return redirect('moviedex_detail', game['captured_movie'][CurrentIndex['index']]['title'])

		if key == 'left' and CurrentIndex['index'] != 0:
			CurrentIndex['index'] -= 1
		elif key == 'right' and (CurrentIndex['index'] < captured_count - 1): # 저장
			CurrentIndex['index'] += 1
		elif key == 'select':
			return redirect('worldmap')

		movie_lst = []
		if captured_count != 0:
			if CurrentIndex['index'] == 0:
				movie_lst.append({'': ''})
			else:
				movie_lst.append(game['captured_movie'][CurrentIndex['index'] - 1])

			movie_lst.append(game['captured_movie'][CurrentIndex['index']])
			if CurrentIndex['index'] + 1 >= captured_count:
				movie_lst.append({'', ''})
			else:
				movie_lst.append(game['captured_movie'][CurrentIndex['index'] + 1])

		movies = {}
		movies['movie'] = movie_lst
		movies['index'] = CurrentIndex['index']
		print(CurrentIndex['index'])
		return render(request, self.template_name, movies)
