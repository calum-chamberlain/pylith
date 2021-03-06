# -*- Makefile -*-
#
# ----------------------------------------------------------------------
#
# Brad T. Aagaard, U.S. Geological Survey
# Charles A. Williams, GNS Science
# Matthew G. Knepley, University of Chicago
#
# This code was developed as part of the Computational Infrastructure
# for Geodynamics (http://geodynamics.org).
#
# Copyright (c) 2010-2015 University of California, Davis
#
# See COPYING for license information.
#
# ----------------------------------------------------------------------
#

SUBDIRS = utilities

INTERPRETER = $(PYTHON)
noinstINTERPRETER = $(PYTHON)

bin_SCRIPTS = \
	pylith

do_build = sed -e s%[@]INTERPRETER[@]%$(noinstINTERPRETER)%g -e s%[@]PYTHONPATH[@]%$(noinstPYTHONPATH)%g
do_install = sed -e s%[@]INTERPRETER[@]%$(INTERPRETER)%g -e s%[@]PYTHONPATH[@]%$(PYTHONPATH)%g

pylith:  $(srcdir)/pylith.in Makefile
	$(do_build) <  $(srcdir)/pylith.in > $@ || (rm -f $@ && exit 1)
	chmod +x $@

install-binSCRIPTS: $(bin_SCRIPTS)
	@$(NORMAL_INSTALL)
	test -z "$(bindir)" || $(mkdir_p) "$(DESTDIR)$(bindir)"
	@list='$(bin_SCRIPTS)'; for p in $$list; do \
	  if test -f "$$p.in"; then d=; else d="$(srcdir)/"; fi; \
	  if test -f $$d$$p.in; then \
	    f=`echo "$$p" | sed 's|^.*/||;$(transform)'`; \
	    echo " $(do_install) '$$d$$p.in' > '$(DESTDIR)$(bindir)/$$f'"; \
	    $(do_install) "$$d$$p.in" > "$(DESTDIR)$(bindir)/$$f"; \
	    echo " chmod +x '$(DESTDIR)$(bindir)/$$f'"; \
	    chmod +x "$(DESTDIR)$(bindir)/$$f"; \
	  else :; fi; \
	done

EXTRA_DIST = \
	pylith.in

CLEANFILES = $(bin_SCRIPTS)


# End of file 
