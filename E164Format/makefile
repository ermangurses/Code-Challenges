JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	E164Format.java \
	E164FormatTest.java 

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class
