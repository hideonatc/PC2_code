DIR = /home/hideonatc/Documents/PC2/code/
COM = g++
all:$(f)
	$(COM) $(f).cpp -o $(f)
	$(DIR)$(f)
	rm $(f)
	cp $(f).cpp ../../../Desktop