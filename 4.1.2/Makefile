PROG_NAME=prot_constr
CXX=g++
BUILD_ARGS=${PROG_NAME}.cpp -o ${PROG_NAME}
DBG_ARGS=-g

build:
	${CXX} ${BUILD_ARGS} 

build_debug:
	${CXX} ${DBG_ARGS} ${BUILD_ARGS} 

rebuild:
	make clean
	make build

rebuild_debug:
	make clean
	make build_debug

clean:
	@if [ -f "${PROG_NAME}" ]; then \
		echo "Deleting file \"${PROG_NAME}\""; \
		rm prot_constr; \
	else \
		echo "File \"${PROG_NAME}\" not found. Ignoring..."; \
	fi
