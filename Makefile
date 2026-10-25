bfs_prog: 
	g++ -Wall -Wextra -std=c++23 src/graph.cpp src/main.cpp -o bfs_prog -Iinclude

clean:
	rm -f bfs_prog