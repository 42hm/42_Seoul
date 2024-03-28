from django.http.response import HttpResponse
from .models import Image
from .forms import ImageForm
from django.views.generic import FormView, ListView
from django.shortcuts import render
from django.urls import reverse_lazy

# 제네릭뷰 사용. 상속을 이용해 뷰를 생성 [추상적(?)]
# https://my-repo.tistory.com/29

# Class-level 속성을 가지는 객체들은 import 될 때 배치되는데 URL-seolving 규칙은 import 시간에 세팅되어있지 않아 class 내에서 reverse()를 사용하면 URLconf의 규칙을 인식하지 못한다.
# 따라서 class내에서 사용되는 reverse()함수는 URL 규칙을 적용하지 못하여 Included URLconf “does not appear to have any patterns in it” 에러을 뿜어내며 서버가 죽어버린다.
# 그러나 def 속성 객체는 import 이후에 배치되므로 URLconf의 규칙을 적용할 수 있다.
# 그러므로 class 형 뷰를 사용할때는 from django.urls import reverse_lazy 로 reverse_lazy() 함수를 import 해서 사용해주자.

class Index(ListView, FormView):
    success_url = reverse_lazy('index')
    template_name = 'index.html'
    form_class = ImageForm
    model = Image
    queryset = model.objects.all().order_by('-id')

    def form_valid(self, form: ImageForm) -> HttpResponse:
        form.save()
        return super().form_valid(form)
# 슈퍼클래스인 FromView의 메소드 from_vaild 호출 (django.http.HttpResponse)반환 상속받았기때문.

    def form_invalid(self, form: ImageForm) -> HttpResponse:
        print(form.errors)
        return super().form_invalid(form)