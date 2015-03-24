SOURCES=main.c concurrency-issue.c concurrency-solved.c relock.c
OBJECTS=$(SOURCES:.c=.o)
EXEC=futex

all: clean $(EXEC)

$(EXEC): $(OBJECTS)
	gcc -o $(EXEC) $(OBJECTS) -pthread
	rm $(OBJECTS)

$(OBJECTS): $(SOURCES)
	gcc -c $(SOURCES)

clean:
	rm -f $(OBJECTS)
	rm -f $(EXEC)
