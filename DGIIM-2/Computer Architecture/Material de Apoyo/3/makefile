###############################################################################
# makefile
###############################################################################

SHELL = bash
.ONESHELL:

###############################################################################

SRC = $(wildcard *.c *.cc *.cpp)
EXE = $(basename $(SRC))
ATT = $(EXE:=.att)

CFLAGS   = -fopenmp -O2 -Wall
CXXFLAGS = $(CFLAGS)

MPICC  = $(shell locate mpicc  | grep '/bin/mpicc$$')
MPICXX = $(shell locate mpic++ | grep '/bin/mpic++$$')
MPIRUN = $(shell locate mpirun | grep '/bin/mpirun$$')

N = 99999999

###############################################################################

default: $(EXE)

all: stat

clean:
	-rm -fv $(ATT) $(EXE) core.* perf.* *~

stat: $(sort $(filter pi% opi% mpi-pi%,$(EXE)))
	@for i in $^; do \
		echo -en "$$i      \t"; \
		if echo $$i | grep -q mpi; then \
			perf stat -r 7 -- $(MPIRUN) -n 4 ./$$i $(N) |& grep elapsed; \
		else \
			perf stat -r 7 --                ./$$i $(N) |& grep elapsed; \
		fi | tr -s ' '; \
	done

###############################################################################

e1: 1
	@echo "./$< 4 10"
	./$< 4 10 | sort -n
	printf '%79s\n' | tr ' ' '-'
	echo "./$< 5 10"
	./$< 5 10 | sort -n

###############################################################################

define tabla
	export OMP_NUM_THREADS=$1
	echo '     static  dynamic   guided'
	echo '--- -------  -------  -------'
	echo ' i: 1  2  4  1  2  4  1  2  4'
	echo '--- -------  -------  -------'
	for (( i = 0; i < 16; ++i )); do
		echo -en "$$(seq -w $$i 17 16 | tr -d '\n'): "
		for s in schedule-clause++ scheduled-clause++ scheduleg-clause++; do
			for c in 1 2 4; do
				id=$$(if [ "$$s" == "schedule-clause++" ]; then
					./$$s $$c 2> /dev/null
				else
					./$$s 16 $$c
				fi | grep -v '^suma' | sort -b -k 3 | grep "a\[$$i\]")
				if [ -n "$$id" ]; then 
					id=$${id:9:1}
				else
					id='x'
				fi
				echo "$$id."
			done | tr '[[:space:]].' ' '
		done
		echo
	done
endef

2a: schedule-clause++ scheduled-clause++ scheduleg-clause++
	@$(call tabla,2)

2b: schedule-clause++ scheduled-clause++ scheduleg-clause++
	@$(call tabla,4)

###############################################################################

benchmark: LDLIBS+=-lbenchmark
mpi-pi: CC=$(MPICC)
mpi-pi++: CXX=$(MPICXX)

%.att: %
	objdump -C -d ./$< > ./$@

%.data: %
	if echo $< | grep -q mpi; then
		perf record --call-graph dwarf -o $@ -- $(MPIRUN) -n 4 ./$< $(N)
	else
		perf record --call-graph dwarf -o $@ --                ./$< $(N)
	fi

%.perf: %.data
	perf report -i ./$<

###############################################################################

.NOEXPORT:
.PHONY: all clean default stat 2a 2b

###############################################################################
