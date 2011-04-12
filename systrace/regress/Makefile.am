AUTOMAKE_OPTIONS = foreign no-dependencies

DISTCLEANFILES = *~

noinst_PROGRAMS = stat fork vfork

stat_SOURCES = test_stat.c
fork_SOURCES = test_fork.c
vfork_SOURCES = test_vfork.c

all: regress test_stat

regress: 
	@chmod u+x regress.sh
	@./regress.sh

test_stat:
	@mkdir ./tmp || echo "./tmp already there"
	@echo -en "stat:\t"
	@../systrace -At -d ./tmp ./stat || echo "FAILURE"
	@sleep 1
	@rm -rf ./tmp

clean:
	rm -f ${DISTCLEANFILES}
