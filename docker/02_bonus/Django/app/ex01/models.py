from django.db import models

class Movies(models.Model):
    episode_nb      = models.ForeignKey('self', on_delete=models.CASCADE)
    title           = models.CharField(max_length=64)
    opening_crawl   = models.TextField(null=True)
    director        = models.CharField(max_length=32)
    producer        = models.CharField(max_length=128)
    release_dat     = models.DateField()

    def __str__(self):
        return self.title
