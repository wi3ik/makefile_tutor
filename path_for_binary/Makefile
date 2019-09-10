help:
	@echo "build code examples to path (modify) original C-logic."
	@echo "make binary == main logic which will be modified"
	@echo "make path == path to modify original file"
	@echo ""
	@echo "objfump -S --srction=.text binary"
	@echo "find relevant address with jump opcode and replace it with new opcode"

binary: binary.c
	gcc -o binary binary.c

patch: patch.c
	gcc -o patch patch.c

clean:
	rm -rf binary
	rm -rf patch
	
