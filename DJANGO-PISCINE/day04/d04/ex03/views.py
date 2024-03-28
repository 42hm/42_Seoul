from django.shortcuts import render


def index(request):
    rgb = 255 / 50
    color = {"rgb" : [int(i * rgb) for i in range(50)]}
    print(color)
    return render(request, 'ex03/index.html', color)