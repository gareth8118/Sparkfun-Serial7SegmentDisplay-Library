
COMPONENT_NAME = Sparkfun_Serial7SegmentDisplay

CPPUTEST_HOME = ../cpputest

CPPUTEST_USE_EXTENSIONS = Y

SRC_DIRS = \
	Sparkfun_Serial7SegmentDisplay

TEST_SRC_DIRS = \
	tests

INCLUDE_DIRS = \
	Sparkfun_Serial7SegmentDisplay \
	tests \
	$(CPPUTEST_HOME)/include

include $(CPPUTEST_HOME)/build/MakefileWorker.mk
