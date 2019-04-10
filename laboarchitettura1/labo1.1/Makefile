N=hello
M=my_string_master
CMP=gc_string_master
SCRPT=check_master.sh

all: $(N) $(M)

test_master: $(M)
	./$(SCRPT) $(CMP) $(M) m
	./$(SCRPT) $(CMP) $(M) f
	./$(SCRPT) $(CMP) $(M) mp
	./$(SCRPT) $(CMP) $(M) fp

$(M): $(M).c
	gcc -o $(M) -DMY_SOURCE_FILE='"$(M)"' $(M).c

$(N): $(N).c
	gcc -o $(N) $(N).c

clean:
	/bin/rm -f a.out *.o $(M) $(N) diff_*.txt
