# FDF
This is first project in graphic branch.
The subject is to create voluminous picture from file.
Program read a file with numbers that determine the altitude of image:
![alt text](https://github.com/volchey/Unit/blob/master/fdf/42map.png?raw=true)

Than parse it and draw image in new window:
![alt text](https://github.com/volchey/Unit/blob/master/fdf/42map_result.png?raw=true)
## About project
FDF is written on Mac OS and compiled with clang. It use Makefile to compile project. It contain graphic library minilibx which is used to open new window and put a pixel to it.
## Installing
You should download minilibx library which is present in file sources.tgz .

To use this program you need to type **make re** in your terminal. This command create a binary file which call fdf.
To run this binary file you need to type **./fdf** and name of file you want to read.
Some maps are included in test_maps dir.

**Full example to run this program:**
```
git clone https://github.com/volchey/Unit.git fdf
cd fdf
make re
./fdf test_maps/42.fdf
```
**_To close the window press escape_**