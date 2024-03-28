from django.shortcuts import redirect, render
from django.views.generic import TemplateView
# import GameManage
# import GameData


class Options(TemplateView):
	template_name = "moviemon/options.html"
	context = {}

	def get(self, request):
		key = request.GET.get('key', None)
		if key == 'start':
			return redirect('worldmap')
		elif key == 'a':
			return redirect('save_game')
		elif key == 'b':
			return redirect('title')
		else:
			return render(request, self.template_name)
