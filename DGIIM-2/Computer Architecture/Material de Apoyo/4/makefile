###############################################################################
# Makefile
###############################################################################

ATT  = $(EXE:=.att)
SRC  = $(wildcard *.c *.cc)
EXE  = $(basename $(SRC))
DAT  = $(EXE:=.dat)
PERF = $(DAT:.dat=.perf)
OUT  = $(EXE:=.out)
KCG  = $(OUT:.out=.kcg)

###############################################################################

#CFLAGS = -g -fopenmp -O2 -Wall
CFLAGS = -flto -fno-inline -g -march=native -O3 -Wall
CXXFLAGS = $(CFLAGS)

###############################################################################

all: att

att: $(ATT)

clean:
	-rm -fv $(ATT) $(EXE) $(DAT) $(OUT) core.* perf.dat* *.dat.old *~

exe: $(EXE)

###############################################################################

%.att: %
	objdump -Cd $< > $@

%.dat: %
	perf record -g -o $@ -- ./$< 2048

%.perf: %.dat
	perf report -g 'graph,0.5,caller' -i $<

###############################################################################

%.out: %
	valgrind --branch-sim=yes --cache-sim=yes --callgrind-out-file=$@ --collect-jumps=yes --collect-systime=nsec --demangle=yes --dump-instr=yes --dump-line=yes --tool=callgrind --trace-jump=yes ./$< 1024

%.kcg: %.out
	kcachegrind $< &

###############################################################################

.PHONY: all att clean exe
.PRECIOUS: $(DAT) $(OUT)
.NOEXPORT:

###############################################################################
