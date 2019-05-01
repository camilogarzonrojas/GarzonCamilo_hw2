run: resultados clean
resultados : runFourier  Resultados_hw2.tex
	pdflatex Resultados_hw2.tex	
runFourier : Fourier.py
	python3 Fourier.py
clean: resultados
	find . ! -name 'Fourier.py' ! -name 'hw2.mk' ! -name 'Resultados_hw2.tex' ! -name 'signal.dat' ! -name 'signalSuma.dat' ! -name 'temblor.txt'  ! -name 'signalSuma.dat' ! -name 'Resultados_hw2.pdf' -type f -delete

