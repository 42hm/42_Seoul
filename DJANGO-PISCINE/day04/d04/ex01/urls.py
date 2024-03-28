from django.urls import path
from django.urls.resolvers import URLPattern
from . import views

urlpatterns = [
    path('django', views.django, name='django'),
    path('display', views.display, name='dispaly'),
    path('templates', views.templates, name='templates'),
]