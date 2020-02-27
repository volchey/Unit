from django.shortcuts import render
from .models import MyForm, MyImage
from django.views.generic import FormView
from PIL import Image

class MyImages(FormView):
    form_class = MyForm
    template_name = 'ex00/my_images.html'
    initial = {'key': 'value'}
    success_url = 'my_images'

    def get(self, request):
        form_class = MyForm
        form = self.form_class(initial={'key': 'value'})
        print('aaaa')
        files = MyImage.objects.all()
        return render(request, self.template_name, {'form': form, 'files':files})

    def post(self, request):
        form_class = MyForm(request.POST, request.FILES)

        files = MyImage.objects.all()
        if not form_class.is_valid():
            return render(request, self.template_name, {'form':form_class, 'files':files})
        title = form_class.cleaned_data.get('title')
        img = form_class.cleaned_data.get('img')

        new_img = MyImage(title=title, img=img)
        new_img.save()

        return render(request, self.template_name, {'form':form_class, 'files':files})

