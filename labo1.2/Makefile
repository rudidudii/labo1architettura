N=hello1
E=hello
E1=hello1
SCRPT=./check.sh

all: $(E) $(E1)

$(E): $(E).c
	gcc -o $(E) $(E).c

$(E1): $(E1).c
	gcc -o $(E1) $(E1).c

check_$(E1): $(E1) $(E)
	$(SCRPT) $(E1) $(E)

clean:
	/bin/rm -f a.out *.o $(E) $(E1) diff_*.txt
