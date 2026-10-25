bfs_prog: 
	g++ -Wall -Wextra -std=c++23 src/graph.cpp drivers/bfs_driver.cpp -o bfs_prog -Iinclude

dfs_prog:
	g++ -Wall -Wextra -std=c++23 src/graph.cpp drivers/dfs_driver.cpp -o dfs_prog -Iinclude

clean:
	rm -f bfs_prog dfs_prog