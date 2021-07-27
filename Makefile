all:
	g++ cw.cpp -o cw
	@echo "Run the following command :"
	@echo "bash script.sh"
clean:
	rm -f cw *.txt *.png