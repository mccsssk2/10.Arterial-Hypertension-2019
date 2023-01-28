# Grandi model make
CC       = mpicc
CFLAGS   =
INCLUDE  = /home/kharches/software/sundials/instdir/include
MY_APP = shi
LIB	 = -L/home/kharches/software/sundials/instdir/lib

shi:	shi2009.c
	${CC} ${CFLAGS} -I${INCLUDE} -c shi2009.c -o shi2009.o
	${CC} ${CFLAGS} shi2009.o -I${INCLUDE} -lm ${LIB} -lsundials_cvodes -lsundials_nvecserial -o ${MY_APP}

run:
	./${MY_APP}

clean:
	rm -r ${MY_APP} *.o *~

veryclean:
	rm -r *.dat ${MY_APP} ${MY_APPI} *.o *~

