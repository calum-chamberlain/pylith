MASTERROOT = pylith_overview

TEXMASTER = $(MASTERROOT).tex

TEXSRCS = 

TEXFILES = $(TEXMASTER) $(TEXSRCS)

AUXFILES = $(TEXMASTER:.tex=.aux)

PDFFILE = $(TEXMASTER:.tex=.pdf)

DVIFILE = $(TEXMASTER:.tex=.dvi)

PSFILE = $(TEXMASTER:.tex=.ps)

PDFTMPFILE = tmp.pdf

default:

pdf: $(PDFFILE)
ps: $(PSFILE)
dvi: $(DVIFILE)

again:
	pdflatex $(TEXMASTER) && mv $(PDFFILE) $(PDFTMPFILE)
	ppower4 $(PDFTMPFILE) $(PDFFILE)

$(PDFTMPFILE): $(TEXFILES) $(AUXFILES)
	pdflatex $(TEXMASTER) && mv $(PDFFILE) $(PDFTMPFILE)

$(PDFFILE): $(PDFTMPFILE)
	ppower4 $(PDFTMPFILE) $(PDFFILE)

$(PSFILE): $(DVIFILE)
	dvips -o $(PSFILE) $(DVIFILE)

$(DVIFILE): $(TEXFILES) $(AUXFILES)
	latex $(TEXMASTER)

$(AUXFILES):
	touch $(AUXFILES)

clean:
	rm -f $(AUXFILES) $(DVIFILE) $(PSFILE) $(PDFTMPFILE)\
		$(MASTERROOT).log $(MASTERROOT).out *~
	rm -fr auto
	rm `find figs -name "*.pdf"`

pdffigs:
	for i in `find figs -name "*.eps"`; do epstopdf $$i; done
	for i in `find figs -name "*.pdf.BAK"`; do j=`echo $$i | sed -e s/.BAK//g`; cp -f $$i $$j; done

compressfigs:
	gzip `find figs -name "*.eps"`

uncompressfigs:
	gunzip `find figs -name "*.eps.gz"`

