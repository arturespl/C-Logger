OUT=logger.out

ALL:
	g++ -o ${OUT} main.cpp LOG.cpp

clean:
	rm ${OUT}

run:
	./${OUT}