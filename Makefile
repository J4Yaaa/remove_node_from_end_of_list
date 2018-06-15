a.out:linklist.cpp remove_nth_node_from_end_of_list.cpp
	g++ -o $@ $^
.PHONY:clean
clean:
	rm a.out
