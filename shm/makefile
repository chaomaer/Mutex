hdrs = sharedata.h
opts = -g -c
r_src = reader.cpp
r_obj = reader.o
w_src = writer.cpp
w_obj = writer.o
all: reader writer
reader: $(r_obj)
	g++ $(r_obj) -o reader
reader.o: $(r_src) $(hdrs)
	g++ $(opts) $(r_src)
writer: $(w_obj)
	g++ $(w_obj) -o writer
writer.o: $(w_src) $(hdrs)
	g++ $(opts) $(w_src)
clean:
	rm reader writer *.o