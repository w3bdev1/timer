.SILENT:

PROG=timer
SOURCE_DIR=src
OUTPUT_DIR=bin

timer: clean ${OUTPUT_DIR}
	gcc -Wall -o ${OUTPUT_DIR}/${PROG} ${SOURCE_DIR}/${PROG}.c

clean:
	rm -rf ${OUTPUT_DIR}

${OUTPUT_DIR}:
	mkdir -p ${OUTPUT_DIR}
