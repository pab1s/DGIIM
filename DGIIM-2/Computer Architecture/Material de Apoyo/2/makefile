###############################################################################
# makefile
###############################################################################

SHELL = /bin/bash
.ONESHELL:

###############################################################################

SRC = $(wildcard *.c *.cc *.cpp)
EXE = $(basename $(SRC))
ATT = $(EXE:=.att)
ALL = $(shell echo {8,9{a,b,c},10}.cc)
LOG = $(ALL:.cc=.log)
SVG = 8.svg
PNG = 8.png

NATIVE   = $(shell [ "$$HOSTNAME" != "atcgrid" ] && echo "-march=native")
CFLAGS   = -fopenmp $(NATIVE) -O3 -Wall
CXXFLAGS = $(CFLAGS)
#LDFLAGS  = -Wl,--no-as-needed
#LDLIBSS  = -lrt

###############################################################################

default: $(EXE)

all: $(PNG)

clean:
	-rm -fv $(ATT) $(EXE) $(LOG) $(PNG) $(SVG) core.* perf.data* *.dat *~

###############################################################################

%.att: %
	objdump -C -d ./$< > ./$@

%.log: %
	for (( i=10; i<100000; i*=10 )); do
		./$< $$i &> /dev/null
	done
	for (( i=1; i<=16384; i*=2 )); do \
		echo "$$i $$("./$<" $$i 2> /dev/null)"; \
	done | tee './$@'

%.png: %.svg
	convert $< $@

$(SVG): $(LOG)
	gnuplot <<< "\
		set terminal svg; \
		set output '$@'; \
		set grid; \
		set key bottom; \
		set xlabel 'N'; \
		set ylabel 'time'; \
		set logscale x 2; \
		set logscale y 10; \
		set xtics rotate; \
		set xtics (1, 2, 4, 8, 16, 32, 64, 128, 256, 512, '1ki' 1024, '2ki' 2048, '4ki' 4096, '8ki' 8192, '16ki' 16384, '32ki' 32768, '64ki' 65526, '128ki' 131072, '256ki' 262144, '512ki' 524288, '1Mi' 1048576, '2Mi' 2097152, '4Mi' 4194304, '8Mi' 8388608, '16Mi' 16777216, '32Mi' 33554432, '64Mi' 67108864, '128Mi' 134217728, '256Mi' 268435456, '512Mi' 536870912, '1Gi' 1073741824); \
		set ytics ('1ns' 1, '10ns' 10, '100ns' 100, '1us' 1000, '10us' 10000, '100us' 100000, '1ms' 1000000, '10ms' 10000000, '100ms' 100000000, '1s' 1000000000, '10s' 10000000000, '100s' 100000000000); \
		plot  '8.log' u 1:2 w lp lc 1 pt  5 t  '8', \
		     '9a.log' u 1:2 w lp lc 2 pt  7 t '9a', \
		     '9b.log' u 1:2 w lp lc 3 pt  9 t '9b', \
		     '9c.log' u 1:2 w lp lc 4 pt 11 t '9c', \
		     '10.log' u 1:2 w lp lc 7 pt 13 t '10'"

###############################################################################

%.dat: %
	perf record -F max -o $@ -- ./$<

%.perf: %.dat
	perf report -i $<

###############################################################################

.PHONY: all clean default
.PRECIOUS: $(LOG) $(PNG) $(SVG)
.NOEXPORT:

###############################################################################
