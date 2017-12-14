Function get_next_line(int fd, char **line) allows you to read only one line from file. 
With each call to GNL you get next line of the file. 
Function use static variable to save the line after \n. GNL read BUFF_SIZE bytes from file. It can work with any BUFF_SIZE. GNL return 1 if line readed 0 if it is end of the file and -1 if there 
was a mistake when file reading.
