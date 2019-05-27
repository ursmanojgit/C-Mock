CMOCK=$(shell readlink -f ..)
CWD=$(shell pwd)

CFLAGS=$(shell $(CMOCK)/bin/cmock-config --cflags)
LDFLAGS=$(shell $(CMOCK)/bin/cmock-config --libs $(GMOCK) $(GTEST))

SRCS=$(shell ls *.cc)
OBJS=$(SRCS:.cc=.o)

all: liboal.so cmock_test

oal-adapter.o: oal-adapter.c
	$(CC) -c -fPIC $^ -o $@

liboal.so: oal-adapter.o
	$(CC) -shared -Wl,-soname,$(CWD)/$@ -o $@ $^

%.o: %.cc
	$(CXX) -c $(CFLAGS) $^ -o $@

cmock_test: $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) -pthread -L$(CWD) -loal -lgmock_main -lgmock -lgtest

clean:
	rm -f $(OBJS) cmock_test oal-adapter.o liboal.so
