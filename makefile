win: 
	make -f makefile.win compile_src run

win-test:
	make -f makefile.win compile_tests run

mac:
	make -f makefile.mac compile_src run

mac-test:
	make -f makefile.mac compile_tests run
