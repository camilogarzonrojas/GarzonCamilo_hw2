run: resultados clean Ode
resultados: Ode runFourier  Resultados_hw2.tex 
	pdflatex Resultados_hw2.tex	
runFourier: Fourier.py
	python3 Fourier.py
Ode: Edificio.cpp Plots_hw2.py
	g++ Edificio.cpp
	./a.out 
	python3 Plots_hw2.py
clean: resultados Ode
	find . ! -name 'Fourier.py' ! -name 'hw2.mk' ! -name 'Edificio.cpp' ! -name 'Plots_hw2.py' ! -name 'Resultados_hw2.tex' ! -name 'signal.dat' ! -name 'signalSuma.dat' ! -name 'temblor.txt'  ! -name 'signalSuma.dat' ! -name 'Resultados_hw2.pdf' -type f -delete

