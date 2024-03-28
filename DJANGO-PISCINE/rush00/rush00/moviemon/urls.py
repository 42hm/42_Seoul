from django.urls import path
from .views.title import Title
from .views.worldmap import Worldmap
from .views.prebattle import Prebattle
from .views.battle import Battle
from .views.moviedex import Moviedex
from .views.moviedex_detail import Moviedex_detail
from .views.options import Options
from .views.save_game import Save_game
from .views.load_game import Load_game


urlpatterns = [
	path('', Title.as_view(), name='title'),
	path('worldmap/', Worldmap.as_view(), name='worldmap'),
	path('prebattle/', Prebattle.as_view(), name='prebattle'),
    path('battle/<str:moviemon_id>', Battle.as_view(), name='battle'),
	path('moviedex/', Moviedex.as_view(), name='moviedex'),
	path('moviedex/<str:moviemon_id>', Moviedex_detail.as_view(), name='moviedex_detail'),
	path('options/', Options.as_view(), name='options'),
	path('options/save_game', Save_game.as_view(), name='save_game'),
	path('options/load_game', Load_game.as_view(), name='load_game'),
]
